#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        int i;
        int length = num.size();
        vector<bool> visited;
        for(i=0; i<length; i++)
        	visited.push_back(false);
        vector<int> tmp;
        permuteSolver(visited, ans, num, tmp);
        return ans;
    }
    
    void permuteSolver(vector<bool> &visited, vector<vector<int> > &ans, vector<int> &num, vector<int> &solution)
    {
    	if(solution.size() ==num.size())
    	{
			ans.push_back(solution);
			return;
    	}
    	int i;
    	int length = num.size();
    	
    	for(i=0; i<length; i++)
    	{
    		if(!visited[i])
    		{
    			visited[i] = true;
    			solution.push_back(num[i]);
    			permuteSolver(visited, ans, num, solution);
    			visited[i] = false;
    			solution.pop_back();
     		}
    		else continue;
    	}
    }
};

int main()
{
	vector<int> in;
	vector<vector<int> > result;
	int i, j;
	Solution *slt = new Solution();
	in.push_back(1);
	in.push_back(2);
	in.push_back(1);
	result = slt->permute(in);
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
