#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rQueue, dQueue;
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') rQueue.push(i);
            else dQueue.push(i);
        }
        while(!rQueue.empty() && !dQueue.empty()){
            if(rQueue.front() < dQueue.front())
                rQueue.push(rQueue.front() + n);
            else dQueue.push(dQueue.front() + n);
            rQueue.pop();
            dQueue.pop();
        }
        return !rQueue.empty() ? "Radiant" : "Dire";
    }
};