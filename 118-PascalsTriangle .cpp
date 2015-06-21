#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        int i;
        vector<vector<int> > ans;
        for(i=0; i<numRows; i++)
        {
        	ans.push_back(getRow(i));
        }
        return ans;
    }
    
    
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
};

int main()
{
	Solution *slt = new Solution();
	vector<vector<int> > result;
	int i, j, in=5;
	result = slt->generate(in);
	for(i=0; i<result.size(); i++)
	{
		for(j=0; j<result[i].size(); j++)
		{
			cout<<result[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
