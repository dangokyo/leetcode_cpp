#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int i, j;
        int t;
        vector<int> v(m+1, 0);
        vector<vector<int> > dp(n+1, v);
        for(i=0; i<=m; i++) dp[0][i] = i;
        for(i=0; i<=n; i++) dp[i][0] = i;
        for(i=1; i<=n; i++)
        {
                 for(j=1; j<=m; j++)
                 {
                          t = ((word2[i-1] == word1[j-1])?0:1);
                          //cout<<i<<" "<<j<<" "<<word1[i-1]<<" "<<word2[j-1]<<" "<<t<<endl;
                          dp[i][j] = min( min(dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1]+t);            
                 }
        }
        /*for(i=0; i<=n; i++)
        {
                 for(j=0; j<=m; j++)
                 {
                          cout<<dp[i][j]<<' ';          
                 }
                 cout<<endl;
        }*/
        return dp[n][m];
    }
};

int main()
{
    string s1 = "horse";
    string s2 = "ros";
    Solution *slt = new Solution();
    cout<<slt->minDistance(s1, s2)<<endl;
    cin>>s1;
    return 0;
}
