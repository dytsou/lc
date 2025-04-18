#include<iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int times = 0;
        for(int i : prime){
            while(n % i == 0){
                times += i;
                n /= i;
                if (n == 1) return times;
            }
        }
        return times + n;
    }
private:
    int prime[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
};