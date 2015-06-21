#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n == 1) return 1;
        
        vector<int> dp;
        int i, j;
        for(i=0; i<=n; i++)
        {
                 dp.push_back(0);
        }
        dp[0] = 1;
        dp[1] = 1;
        for(i=2; i<=n; i++)
        {
                 for(j=0; j<i; j++)
                 {
                          dp[i] += dp[j] * dp[i-1-j];
                 }
        }
        return dp[n];
    }
};

int main()
{
    int in = 4;
    Solution *slt = new Solution();
    cout<<slt->numTrees(in)<<endl;
    cin>>in;
    return 0;
}
