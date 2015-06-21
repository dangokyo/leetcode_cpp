#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int length = s.size();
        int tmp;
        vector<bool> t(length, false);
        vector<vector<bool> > isPalin(length, t);
        vector<int> dp(length+1, 0);
        int i, j;
        
        for(i=0; i<length; i++)
        {
        	isPalin[i][i] = true;
        	for(j=1; i-j>=0 && i+j<length; j++)
        	{
        		isPalin[i-j][i+j] = isPalin[i][i] && (s[i-j] == s[i+j]);
        		if(!isPalin[i-j][i+j]) break;
        	}
        }
        
        for(i=0; i<length - 1; i++)
        {
        	if(s[i] == s[i+1])
        	{
        		isPalin[i][i+1] = true;
        		for(j=1; i-j>=0 && i+j<length; j++)
        		{
        			isPalin[i-j][i+1+j] = isPalin[i][i+1] && (s[i-j] == s[i+1+j]);
        			if(!isPalin[i-j][i+1+j]) break;
        		}
        	}
        }
        
        if(isPalin[0][length-1]) return 0;
        for(i=0; i<length; i++)
        {
        	dp[i] = length - i -1;
        }
        
        for(i=length - 1; i>=0; i--)
        {
        	if(isPalin[i][length-1]) 
			{
				dp[i] = 0;
			}
        	for(j=i; j<length; j++)
        	{
        		if(isPalin[i][j])
        		{
        			tmp = 1 + dp[j+1];
        			if(tmp < dp[i])
        			{
        				dp[i] = tmp;
        			}
				}
        	}
        }
		return dp[0];
    }    
};


int main()
{
    string s = "aaaabaaac";
    //string s = "aab";
    Solution *slt = new Solution();
    cout<<slt->minCut(s);
    return 0;
}
