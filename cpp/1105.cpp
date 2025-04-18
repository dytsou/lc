#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth){
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<= n; i++){
            int width = 0, height = 0;
            for(int j=i; j>0; j--){
                width += books[j-1][0];
                if(width > shelfWidth)
                    break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }
        return dp[n];
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> books(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        cin >> books[i][0] >> books[i][1];
    int shelfWidth;
    cin >> shelfWidth;
    Solution s;
    cout << s.minHeightShelves(books, shelfWidth) << endl;
    return 0;
}