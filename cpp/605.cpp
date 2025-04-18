#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        if(s == 1) return (flowerbed[0] + n) <= 1;
        for(int i=0; i<s; i++){
            if(!n) break;
            if(i == 0){
                if(!flowerbed[0] && !flowerbed[1]){
                    flowerbed[0]++;
                    n--;
                    i++;
                }
            }
            else if(i == s-1){
                if(!flowerbed[s-1] && !flowerbed[s-2]) n--;
            }
            else if(!flowerbed[i-1] && !flowerbed[i] && !flowerbed[i+1]){
                flowerbed[i]++;
                n--;
                i++;
            }
        }
        return !n;
    }
};

int main(){
    Solution s;
    int flowerNum;
    cin >> flowerNum;
    vector<int> flowerbed(flowerNum);
    for(int i=0; i<flowerNum; i++) cin >> flowerbed[i];
    int n;
    cin >> n;
    cout << s.canPlaceFlowers(flowerbed, n) << endl;
}