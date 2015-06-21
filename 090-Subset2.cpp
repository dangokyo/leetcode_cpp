#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
           vector<vector<int> > ans;
           vector<int> empty;
           sort(S.begin(), S.end());
           ans.push_back(empty);
           int start, k;
           int length = S.size();
           for(k=1; k<=length; k++)
           {
                    //cout<<"Size:"<<k<<endl;
                    subsetCombine(k, S, ans); //pick k elements in the set
           }
           return ans;
    }
    
    int subsetCombine(int k, vector<int> &S, vector<vector<int> > &ans)
    {
        vector<int> sol;
        subsetCombineSolver(0, 0, k, S, sol, ans);
        return 0;
    }
    
    int subsetCombineSolver(int start, int level, int k, vector<int> &S, vector<int> &sol, vector<vector<int> > &ans)
    {
        int i;
        int length = S.size();
        if(level == k)
        {
                 ans.push_back(sol);
                 sol.pop_back();
                 return 0;
        }
        for(i=start; i< length - k + level + 1; i++)
        {
                     sol.push_back(S[i]);
                     vector<int> t_vec = sol;
                     subsetCombineSolver(i+1, level+1, k, S, t_vec, ans);
                     sol.pop_back();
                     while(S[i+1] == S[i]) i++;
        }
        return 0;
    }
};

int main()
{
	vector<int> in;
	vector<vector<int> > result;
	in.push_back(1);
	in.push_back(2);
	in.push_back(2);
	Solution *slt = new Solution();
	result = slt->subsetsWithDup(in);
	int i, j;
	for(i=0; i<result.size(); i++)
	{
		for(j=0; j<result[i].size(); j++)
		{
			cout<<result[i][j]<<' ';
		}
		cout<<endl;
	}
}
