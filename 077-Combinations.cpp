#include<iostream>
#include<vector>

using namespace std;

// k numbers out of 1 to n

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int > solution;
        combineSolver(0, 1, n, k, ans, solution);
        return ans;
    }
    
    int combineSolver(int level, int start, int n, int k, vector<vector<int> >& ans, vector<int>& sol)
    {
        int i;
        //cout<<"test:"<<level<<" "<<start<<" "<<endl;
        if(level == k){
                 ans.push_back(sol);
                 /*for(int j = 0; j<sol.size(); j++)
                         cout<<sol[j]<<' ';
                 cout<<endl;*/
                 sol.pop_back();
                 return 0;
        }
        for(i=start; i<=n - k + 1 + level; i++){
                     sol.push_back(i);
                     vector<int> t_vec = sol;
                     combineSolver(level+1, i+1, n, k, ans, t_vec);
                     sol.pop_back();
        }
        return 0;  
    }  
};

int main()
{
    int n, k, i, j;
    n = 4;
    k = 3;
    vector<vector<int> > result;
    Solution *slt = new Solution();
    result = slt->combine(n, k);
    for(i=0; i< result.size(); i++)
    {
             for(j=0; j< result[i].size(); j++)
             {
                      cout<< result[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>n;
    return 0;
}
