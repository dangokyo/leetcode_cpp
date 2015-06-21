#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        if(m == 0) return 0;
        vector<int> v(m+1, 0);
        
        int n = t.size();
        vector<vector<int> > dp(n+1, v);
        int i, j;
        /*for(i=1; i<=m; i++)
        {
        	if(s[i-1] == s[0])
        	{
        		dp[1][i] = dp[1][i-1]+1;
        	}
        	else dp[1][i] = dp[1][i-1];
        }*/
        for(i=0; i<m; i++) dp[0][i] = 1;
        for(i=1; i<=m; i++)
        {
        	for(j=1; j<=((i>n)?n:i) ; j++)
        	{
        		//cout<<"processing:"<<j<<' '<<i<<endl;
        		if(t[j-1] == s[i-1])
        		{
        			dp[j][i] = dp[j-1][i-1] + dp[j][i-1];
        		}
        		else
        		{
        			dp[j][i] = dp[j][i-1];
        		}
        	}
        	
        	/*for(int p=0; p<=n; p++)
        	{
        		for(int q=0; q<=m;q++)
        		{
        			cout<<dp[p][q]<<' ';
        		}
        		cout<<endl;
        	}
        	cout<<endl;*/
        }
        
        return dp[n][m];
    }
};

int main()
{
	string s = "crabbbit";
	string t = "rabbit";
	Solution *slt = new Solution();
	cout<<slt->numDistinct(s, t);
	return 0;
}
