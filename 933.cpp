#include<iostream>
#include<queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter(): v(), curr(0){}
    int ping(int t){
        v.push_back(t);
        while(v[curr] < t - 3000) curr++;
        return v.size() - curr;
    }
private:
    vector<int> v;
    int curr;
};