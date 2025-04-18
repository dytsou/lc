#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<Entry> pq;
        for (int i = 0; i < n; i++)
            pq.push(Entry(nums[i], i));
        long long ans = 0;
        for (int j = 1; j <= right; j++) {
            Entry e = pq.top();
            pq.pop();
            if (j >= left) ans += e.sum;
            if (e.i + 1 < n) 
                pq.push(Entry(e.sum + nums[e.i + 1], e.i + 1));
        }
        const int kMod = 1e9 + 7;
        return ans % kMod;
    }
private:
    struct Entry{
        int sum;
        int i;
        bool operator<(const Entry& e) const{
            return sum > e.sum;
        }
        Entry(int sum, int i): sum(sum), i(i){}
    };
};