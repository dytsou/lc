#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int left_less = 0, left_more = 0, right_less = 0, right_more = 0;
            for(int j = 0; j < i; j++){
                if(rating[j] < rating[i]) left_less++;
                else if(rating[j] > rating[i]) left_more++;
            }
            for(int k = i + 1; k < n; k++){
                if(rating[k] < rating[i]) right_less++;
                else if(rating[k] > rating[i]) right_more++;
            }
            ans += left_less * right_more + left_more * right_less;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> rating(n);
    for(int i = 0; i < n; i++)
        cin >> rating[i];
    Solution s;
    cout << s.numTeams(rating) << endl;
    return 0;
}