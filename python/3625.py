class Solution:
    def normalizeSlope(self, dx: int, dy: int) -> Tuple[int, int]:
        """Return canonical representation of slope as (dy, dx)."""
        if dx == 0:  # Vertical line
            return (1, 0)
        if dy == 0:  # Horizontal line
            return (0, 1)
        if dx < 0:  # Negative slope
            dx, dy = -dx, -dy
        g = math.gcd(abs(dx), abs(dy))
        dx //= g
        dy //= g
        return (dy, dx)

    def interceptKey(self, x: int, y: int, slope: Tuple[int, int]) -> Tuple[int, int]:
        """Compute normalized intercept key for line with given slope through (x, y)."""
        dy, dx = slope
        if dx == 0:  # vertical line: x = const -> use x as "intercept"
            return (x, 1)
        # y = (dy/dx)*x + b  =>  b = (y*dx - dy*x) / dx
        num = y * dx - dy * x
        den = dx
        if den < 0:  # Negative denominator
            den, num = -den, -num
        g = math.gcd(abs(num), abs(den))
        if g != 0:  # Reduce fraction
            num //= g
            den //= g
        return (num, den)

    def countTrapezoids(self, points: List[List[int]]) -> int:
        n = len(points)
        if n < 4:
            return 0

        # slope -> list of intercepts of segments with that slope
        slopeToIntercept = defaultdict(list)

        # midpoint -> list of slopes of segments with that midpoint
        midToSlope = defaultdict(list)

        # Build all segments
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]

                dx = x2 - x1
                dy = y2 - y1

                k = self.normalizeSlope(dx, dy)
                b = self.interceptKey(x1, y1, k)

                slopeToIntercept[k].append(b)

                mid = (x1 + x2, y1 + y2)
                midToSlope[mid].append(k)

        ans = 0

        # First pass: count pairs of segments with same slope but different intercept
        for vec in slopeToIntercept.values():
            if len(vec) < 2:
                continue

            cnt = defaultdict(int)
            for b in vec:
                cnt[b] += 1

            sum_val = 0
            for c in cnt.values():
                ans += sum_val * c
                sum_val += c

        # Second pass: subtract parallelogram overcounts via midpoints
        for vec in midToSlope.values():
            if len(vec) < 2:
                continue

            cnt = defaultdict(int)
            for k in vec:
                cnt[k] += 1

            sum_val = 0
            for c in cnt.values():
                ans -= sum_val * c
                sum_val += c

        return ans

