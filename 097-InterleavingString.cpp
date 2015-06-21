#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int m = s1.size();
    	if(m==0) return (s2==s3);
    	
    	int n=s2.size();
    	if(n==0) return (s1==s3);
    	
    	if(m+n != s3.size() ) return false;
    	
    	vector<bool> v(m+1, false);
    	vector<vector<bool> > dp(n+1, v);
    	
    	int i, j;
    	char t;
    	for(i=0;i<m;i++)
    	{
    		if(s1[i] == s3[i]) dp[0][i+1] = true;
    		else break;
    	}
    	for(i=0; i<n;i++)
    	{
    		if(s2[i] == s3[i]) dp[i+1][0] = true;
    	}
    	
    	for(i=1; i<=n; i++)
    	{
    		for(j=1; j<=m; j++)
    		{
    			t = s3[i+j-1];
    			//cout<<"processing:"<<i<<' '<<j<<endl;
    			//cout<<t<<' '<<s1[j-1]<<' '<<s2[i-1]<<endl;
    			if((t == s1[j-1] && dp[i][j-1]) || (t == s2[i-1] && dp[i-1][j])) dp[i][j] = true;
    		}
    	}
    	//cout<<"finished"<<endl;
        return dp[n][m];
    }
};

int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s4 = "aadbbbaccc";
	Solution *slt = new Solution();
	cout<<slt->isInterleave(s1, s2, s3)<<endl;
	cout<<slt->isInterleave(s1, s2, s4)<<endl;
	return 0;
}
