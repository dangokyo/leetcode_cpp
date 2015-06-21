#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int t1, t2, t;
        int i;
        bool last_taken = true;
        int length = nums.size();
        if(length == 0) 
        {
                  return 0;
        }
        else if(length==1)
        {
             return nums[0];
        }
        vector<int > dp(length+1, 0); 
        dp[0] = 0;
        dp[1] = nums[0];
        last_taken = true;
        
        for(i=2; i<=length; i++)
        {
                 if(last_taken)
                 {
                          if(dp[i-2] + nums[i-1] > dp[i-1])
                          {
                                     dp[i] = dp[i-2] + nums[i-1];
                          }
                          else if(dp[i-2] + nums[i-1] <= dp[i-1])
                          {
                               dp[i] = dp[i-1];
                               last_taken = false;
                          }
                 }
                 else
                 {
                     dp[i] = dp[i-1] + nums[i-1];
                     last_taken = true;
                 }
        }
        return dp[length];
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int> in;
    in.push_back(51);
    in.push_back(100);
    in.push_back(1);
    in.push_back(51);
    in.push_back(100);
    in.push_back(1);
    cout<<slt->rob(in)<<endl;
    int i;
    cin>>i;
    return 0;
}
