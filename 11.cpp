#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int max_area = 0;
        int *p = &height[0], *q = &height[height.size()-1];
        while(p < q){
            int area = (q - p) * min(*p, *q);
            max_area = max_area > area ? max_area : area;
            if(*p < *q) p++;
            else q--;
        }
        return max_area;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++)
        cin >> height[i];
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}