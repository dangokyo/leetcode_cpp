#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> sol;
        CombinationSolver(1, 0, k, n, ans, sol);
        return ans;
    }
    
    int CombinationSolver(int start, int level, int k, int sum, vector<vector<int> >& ans, vector<int> &sol)
    {
    	int i;
    	//cout<<start<<" "<<level<<" "<<sum<<endl;
    	if(level == k) 
		{
			if(sum == 0) 
			{
				ans.push_back(sol);
				return 0;
			}
			else return 0;
		}
    	
    	for(i= start; i<=9; i++)
    	{
    		sol.push_back(i);
    		CombinationSolver(i+1, level+1, k, sum-i, ans, sol);
    		sol.pop_back();
    	}
    	return 0;
    }
};

int main()
{
	vector<vector<int> > result;
	Solution *slt = new Solution();
	result = slt->combinationSum3(3, 9);
	int i, j;
	cout<<"result:"<<endl;
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

