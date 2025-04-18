#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int val, idx;
    Node(int val, int idx): val(val), idx(idx){}
    bool operator<(const Node& a) const{
        if(val == a.val) return idx < a.idx;
        return val < a.val;
    }
    bool operator>(const Node& a) const{
        if(val == a.val) return idx > a.idx;
        return val > a.val;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<Node, vector<Node>, less<Node>> minHeap;
        priority_queue<Node, vector<Node>, greater<Node>> maxHeap;
        for(int i = 0; i < arrays.size(); i++){
            if(minHeap.size() < 2) minHeap.push(Node(arrays[i].front(), i));
            else if(arrays[i].front() <= minHeap.top().val){
                minHeap.pop();
                minHeap.push(Node(arrays[i].front(), i));
            }
            if(maxHeap.size() < 2) maxHeap.push(Node(arrays[i].back(), i));
            else if(arrays[i].back() >= maxHeap.top().val){
                maxHeap.pop();
                maxHeap.push(Node(arrays[i].back(), i));
            }
        }
        Node min1 = minHeap.top(); 
        minHeap.pop();
        Node min2 = minHeap.top();
        Node max1 = maxHeap.top();
        maxHeap.pop();
        Node max2 = maxHeap.top();
        if(min2.idx != max2.idx) return max2.val - min2.val;
        return max(max1.val - min2.val, max2.val - min1.val);
    }
};

int main() {
    Solution s;
    int n, m;
    vector<vector<int>> arrays(n);
    for(int i = 0; i < n; i++){
        cin >> m;
        arrays[i].resize(m);
        for(int i = 0; i < m; i++)
            cin >> arrays[n][m];
    }
    cout << s.maxDistance(arrays) << endl;
    return 0;
}
