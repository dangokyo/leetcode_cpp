#include<iostream>
#include<vector>

using namespace std;

// k numbers out of S[start] to S[n-1]
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
           vector<vector<int> > ans;
           sort(S.begin(), S.end());
           vector<int> empty;
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
        }
        return 0;
    }
};

int main()
{
    vector<int> s;
    vector<vector<int> > result;
    s.push_back(5);
    s.push_back(3);
    s.push_back(1);
    //s.push_back(6);
    int i, j;
    Solution *slt = new Solution();
    result = slt->subsets(s);
    for(i=0; i< result.size(); i++)
    {
             for(j=0; j<result[i].size(); j++)
             {
                      cout<<result[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>i;
    return 0;
}
