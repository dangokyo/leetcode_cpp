#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
	vector<int> result;
	int i, j, in=5;
	result = slt->getRow(in);
	for(i=0; i<result.size(); i++)
	{
		cout<<result[i]<<' ';
	}
	return 0;
}
