#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int i, j, d1, d2,d3;
        vector<int> dp;
        int length = s.size();
        if(length == 0) return 0;
        for(i=0; i<=length; i++)
        {
                 dp.push_back(0);
        }
        dp[0] = 1;
        for(i=1; i<=length; i++)
        {
                 if(i == 1)
                 {
                      d1 = s[i-1] - '0';
                      if(d1< 10 && d1>0)
                      {
                               dp[i] = 1;
                      }
                      else if(d1 == 0)
                      {
                           dp[i] = 0;
                      }
                 }
                 else if(i >= 2)
                 {
                      d1 = s[i-2] - '0';
                      d2 = s[i-1] - '0';
                      if(d2>0 && d2 < 10)
                      {
                              dp[i] += dp[i-1];
                      }
                      
                      if(d1 == 1 && d2 <10 && d2 >= 0)
                      {
                           dp[i] += dp[i-2];
                      }
                      else if(d1 == 2 && d2 < 7 && d2 >=0)
                      {
                           dp[i] += dp[i-2];
                      }
                      else
                      {
                          dp[i] += 0;
                      }
                      
                 }
                 cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[length];
    }
};

int main()
{
    Solution *slt = new Solution();
    string in = "99";
    cout<<slt->numDecodings(in)<<endl;
    cin>>in;
    return 0;
}
