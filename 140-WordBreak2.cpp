#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int i, j, k;
        int length = s.size();
		vector<string> ans;
    	string tmp;
    	vector<bool> dp(length+1, false);
    	dp[length] = true;
        if(dict.size() == 0 || length == 0) return ans;
        
        
    	for(i=length-1; i>=0; i--)
    	{
    		for(j=1; j<=length-i;j++)
    		{
    			tmp = s.substr(i, j);
    			if(dict.count(tmp)>0 && dp[i+j])
    			{
    				dp[i] = true;
    				break;
    			}
    			else continue;
    		}
    	}
        wordBreakSolver(s, ans, dict, dp, 0);
        return ans; 
    }
    
    void wordBreakSolver(string &s, vector<string> &ans, unordered_set<string> &dict, vector<bool> &dp, int position)
    {
    	if(!dp[position]) return;
    	
    	vector<string> sol;
    	string s1, s2;
    	int length = s.size();
    	int i, j;
    	for(i=position; i<=length; i++)
    	{
    		sol.clear();
    		s1 = s.substr(position,i-position+1);
    		//cout<<"test:"<<position<<" "<<s1<<" "<<dp[i]<<endl;
    		
    		if(i == length && dict.count(s1)>0) 
			{
				ans.push_back(s1);
				return;
			}
    		
    		if(dict.count(s1)>0 && dp[i+1])
    		{
					wordBreakSolver(s, sol, dict, dp, i+1);
    				for(j=0; j<sol.size(); j++)
    					ans.push_back(s1+" "+sol[j]);
			}
    	}
    }
};

int main()
{
	//unordered_set<string> myset = {"cat", "cats", "and", "sand", "dog"};
	//string in = "catsanddog";
	unordered_set<string> myset = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};//{"cat", "cats", "and", "sand", "dog"};
	string in = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	Solution *slt = new Solution();
	vector<string> result= slt->wordBreak(in, myset);
	int i;
	for(i=0; i<result.size();i++)
	{
		cout<<result[i]<<endl;
	}
}
