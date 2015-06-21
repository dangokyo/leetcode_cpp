#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	int length = s.size();
    	if(dict.size() <= 0) return false;
    	if(length == 0) return true;
    	string tmp;
    	vector<bool> dp(length+1, false);
    	dp[length] = true;
    	int i, j;
    	for(i=length-1; i>=0; i--)
    	{
    		for(j=i; j<length; j++)
    		{
    			tmp =s.substr(i, j - i + 1);
    			if(dict.count(tmp) && dp[j+1])
    			{
    				dp[i] = true;
    			}
    		}
    	}
  		return dp[0];      
    }
};

int main()
{
	unordered_set<string> myset = {"leet", "code"};
	Solution *slt = new Solution();
	string in = "leetcode";
	cout<<slt->wordBreak(in, myset);
	return 0;
}
