#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, StringInfo> m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
            m[arr[i]].str = arr[i];
            if(m[arr[i]].firstIdx == -1)
                m[arr[i]].firstIdx = i;
        }
        for(int i = 0; i < arr.size(); i++){
            if(m[arr[i]].count == 1) k--;
            if(k == 0) return m[arr[i]].str;
        }
        return "";
    }
private:
    struct StringInfo{
        int firstIdx;
        int count;
        string str;
        StringInfo(): firstIdx(-1), count(0), str(""){}
        bool operator++(int){
            count++;
            return true;
        }
        bool operator--(int){
            count--;
            return true;
        }
        bool operator<(const StringInfo& si){
            if(count == si.count)
                return firstIdx < si.firstIdx;
            return count < si.count;
        }
    };
};

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Solution s;
    cout << s.kthDistinct(arr, k) << endl;
}