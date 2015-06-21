#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        partitionSolver(s, ans);
        return ans;
    }
    
    int partitionSolver(string str, vector<vector<string> > &ans)
    {
        int i, j;
        int length = str.size();
        string t1, t2;
        for(i=1; i<=length; i++)
        {
                 t1 = str.substr(0, i);
                 t2 = str.substr(i, length - i);
                 vector<vector<string> > sol;
                 if(isPalindrome(t1))
                 {
                                     vector<string>  tmp;
                                     if(t2.size()==0)
                                     {
                                                     tmp.push_back(t1);
                                                     ans.push_back(tmp);
                                                     return 0;
                                     }
                                     partitionSolver(t2, sol);
                                     for(j=0; j<sol.size(); j++)
                                     {
                                              tmp.clear();
                                              tmp.push_back(t1);
                                              tmp.insert(tmp.end(), sol[j].begin(), sol[j].end());
                                              ans.push_back(tmp);
                                     }
                                                             
                 }
                 else continue;
        }
        return 0;    
    }
    
    bool isPalindrome(string str)
    {
         int i;
         int length = str.size();
         for(i=0; i<length/2; i++)
         {
                  if(str[i] != str[length -1 -i]) return false;
         }
         return true;
    }
};

int main()
{
    string in = "aab";
    Solution *slt = new Solution();
    vector<vector<string> > result = slt->partition(in);
    int i, j;
    for(i = 0; i<result.size(); i++)
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
