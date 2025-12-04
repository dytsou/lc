// Hash for pair<int,int>
struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return (static_cast<size_t>(p.first) << 32) ^ (unsigned int)p.second;
    }
};

class Solution {
    using ll = long long;
    using Slope     = pair<int,int>; // (dy, dx) reduced
    using Intercept = pair<int,int>; // (num, den) for b = num / den
    using MidKey    = pair<int,int>; // (x1 + x2, y1 + y2)

    // Return a canonical representation of slope as (dy, dx).
    static Slope normalizeSlope(int dx, int dy) {
        if (dx == 0) // Vertical line
            return {1, 0};
        if (dy == 0) // Horizontal line
            return {0, 1};
        if (dx < 0) // Negative slope
            dx = -dx, dy = -dy;
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        return {dy, dx};
    }

    // Compute normalized intercept key for line with given slope through (x, y)
    static Intercept interceptKey(int x, int y, const Slope& s) {
        int dy = s.first;
        int dx = s.second;
        if (dx == 0) // vertical line: x = const -> use x as "intercept"
            return {x, 1};
        // y = (dy/dx)*x + b  =>  b = (y*dx - dy*x) / dx
        long long num = 1LL * y * dx - 1LL * dy * x;
        long long den = dx;
        if (den < 0) { // Negative denominator
          den = -den;
          num = -num;
        }
        long long g = gcd(abs(num), abs(den));
        if (g != 0) { // Reduce fraction
          num /= g;
          den /= g;
        }
        return {(int)num, (int)den};
    }

public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n < 4) return 0;

        // slope -> list of intercepts of segments with that slope
        unordered_map<Slope, vector<Intercept>, PairHash> slopeToIntercept;
        slopeToIntercept.reserve(1LL * n * n);

        // midpoint -> list of slopes of segments with that midpoint
        unordered_map<MidKey, vector<Slope>, PairHash> midToSlope;
        midToSlope.reserve(1LL * n * n);

        // Build all segments
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                Slope k = normalizeSlope(dx, dy);
                Intercept b = interceptKey(x1, y1, k);

                slopeToIntercept[k].push_back(b);

                MidKey mid = {x1 + x2, y1 + y2};
                midToSlope[mid].push_back(k);
            }
        }

        long long ans = 0;

        // First pass: count pairs of segments with same slope but different intercept
        for (auto &entry : slopeToIntercept) {
            auto &vec = entry.second;
            if (vec.size() < 2) continue;

            unordered_map<Intercept, int, PairHash> cnt;
            cnt.reserve(vec.size());
            for (const auto &b : vec) 
                ++cnt[b];

            long long sum = 0;
            for (auto &kv : cnt) {
                long long c = kv.second;
                ans += sum * c;
                sum += c;
            }
        }

        // Second pass: subtract parallelogram overcounts via midpoints
        for (auto &entry : midToSlope) {
            auto &vec = entry.second;
            if (vec.size() < 2) continue;

            unordered_map<Slope, int, PairHash> cnt;
            cnt.reserve(vec.size());
            for (const auto &k : vec) 
              cnt[k]++;

            long long sum = 0;
            for (auto &kv : cnt) {
                long long c = kv.second;
                ans -= sum * c;
                sum += c;
            }
        }

        return (int)ans;
    }
};