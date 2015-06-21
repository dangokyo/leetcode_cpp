#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int i, j, l;
    	l = triangle.size();
    	vector<int> dp;
    	vector<int> tmp;
    	if(l==0)
    	{
    		return 0;
    	}
    	
    	dp = triangle[0];
    	for(i = 1; i < l;i++)
    	{
    		tmp = dp;
    		dp = triangle[i];
    		for(j=0; j<i+1; j++)
    		{
    			if(j==0)
    			{
    				dp[0] = tmp[0] + dp[0];
    			}
    			else if(j == i)
    			{
    				dp[j] = tmp[j-1] + dp[j];
    			}
    			else
    			{
    				if(tmp[j-1] >= tmp[j])
    				{
    					dp[j] = tmp[j] + dp[j];
    				}
    				else if(tmp[j-1] < tmp[j])
    				{
    					dp[j] = tmp[j-1] + dp[j];
    				}
    			}
    		}
    	}
        return findMin(dp);
    }
    
    int findMin(vector<int> v)
    {
    	int min = INT_MAX;
    	int length = v.size();
    	int i;
    	for(i=0;i<length; i++)
    	{
    		if(v[i] < min)
    		{
    			min = v[i];
    		}
    	}
    	return min;
    }
};


    
    vector<int> getRow(int rowIndex) {
    	vector<int> ans;
    	int i, j, length, k;
    	for(i=0; i<=rowIndex; i++)
    	{
    		ans.push_back(1);
    		length = ans.size();
    		for(j = length - 2; j>=1 ; j--)
    		{
    			ans[j] = ans[j] + ans[j-1];
    		}
    		
    	}
    	return ans;
        
    }
    vector<vector<int> > generate(int numRows) {
        int i;
        vector<vector<int> > ans;
        for(i=0; i<numRows; i++)
        {
        	ans.push_back(getRow(i));
        }
        return ans;
    }
    

int main()
{
	Solution *slt = new Solution();
	vector<vector<int> > in = generate(5);
	int result;
	result = slt->minimumTotal(in);
	cout<<result<<endl;
	return 0;
}
