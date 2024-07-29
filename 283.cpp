#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int *ptr1, *ptr2;
        ptr1 = ptr2 = nums.data();
        while(ptr1 < nums.data() + nums.size()){
            if(*ptr1 != 0){
                *ptr2 = *ptr1;
                ptr2++;
            }
            ptr1++;
        }
        while(ptr2 < nums.data() + nums.size()){
            *ptr2 = 0;
            ptr2++;
        }
        return;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    Solution s;
    s.moveZeroes(nums);
    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}