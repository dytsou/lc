#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int posIdx = 0;
        vector<int> ans;
        for(int asteroid : asteroids){
            if(asteroid > 0) break;
            ans.push_back(asteroid);
            posIdx++;
        }
        for(int i=posIdx; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                ans.push_back(asteroids[i]);
            }
            else{
                while(true){
                    if(ans.empty() || ans.back() < 0){
                        ans.push_back(asteroids[i]);
                        break;
                    }
                    else if(ans.back() < -asteroids[i]){
                        ans.pop_back();
                    }
                    else if(ans.back() == -asteroids[i]){
                        ans.pop_back();
                        break;
                    }
                    else break;
                }
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for(int i=0; i<n; i++)
        cin >> asteroids[i];
    Solution s;
    vector<int> res = s.asteroidCollision(asteroids);
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}