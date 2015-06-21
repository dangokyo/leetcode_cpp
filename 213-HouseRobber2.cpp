#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size<=0) return 0;
        int ans = 0;
        int t1, t2;
        int i;
        
        //take nums[0], dp from 2 to n-2
        t1 = robberSolver(2, size-2, nums);
        t1 = t1+nums[0];
        cout<<t1<<endl;
        //do not take nums[0], dp from 1 to n-1
        t2 = robberSolver(1, size-1, nums);
        cout<<t2<<endl;
        if(t1 >= t2) return t1;
        else return t2;
    }
    
    int robberSolver(int start, int end, vector<int>& nums)
    {
    	int length = end - start + 1;
    	if(length <= 0) return 0;
    	else if(length == 1) return nums[start];
    	
    	int i;
    	vector<int> dp(length+1, 0);
    	dp[0] = 0;
    	dp[1] = nums[start];
    	bool previous_taken = true;
    	for(i=2; i<=length; i++)
    	{
    		if(previous_taken)
    		{
    			if(dp[i-2] + nums[i + start - 1] <= dp[i-1])
    			{
    				dp[i] = dp[i-1];
    				previous_taken = false;
    			}
    			else
    			{
    				dp[i] = dp[i-2] + nums[i + start - 1];
    			}
    		}
    		else
    		{
    			dp[i] = dp[i-1] + nums[i + start - 1];
    			previous_taken = true;
    		}
    	}
    	return dp[length];
    }
};

int main()
{
	vector<int> in;
	in.push_back(3);
	in.push_back(4);
	in.push_back(3);
	in.push_back(1);
	Solution *slt = new Solution();
	cout<<slt->rob(in)<<endl;
	
	return 0;
}
