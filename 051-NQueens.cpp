#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> sol;
        string row;
        int i;
        
        if(n==1)
        {
                row = "Q";
                sol.push_back(row);
                ans.push_back(sol);
                return ans;
        }
        
        for(i = 0; i<n; i++)
              row += ".";
        for(i=0; i<n; i++)
                 sol.push_back(row);
        
        NQueensSolver(ans, sol, 0, n);
        if(ans.size()==0)
                         ans.push_back(sol);
        return ans;
    }
    
    int NQueensSolver(vector<vector<string> > &ans, vector<string> &sol, int level, int n)
    {
       if(level == n)
       {
                ans.push_back(sol);
                return 0;
       }
       int row, col;
       row = level;
       for(col = 0; col < n; col++)
       {
               sol[row][col] = 'Q';
               if(isValidBoard(sol, row, col, n))
               {
                                    NQueensSolver(ans, sol, level+1, n);
               }
               sol[row][col] = '.';
                      
       }  
       return 0;
    }
    
    bool isValidBoard(vector<string> &sol, int row, int col, int n)
    {
         int i;
         for(i=0; i<n; i++)
         {
                  if(i==col)
                            continue;
                  if(sol[row][i] == 'Q')
                                 return false;
         }
         for(i=0; i<n; i++)
         {
                  if(i==row)
                            continue;
                  if(sol[i][col] == 'Q')
                                 return false;
         }
         for(i=1; row+i<n && col+i<n; i++)
         {
                  if(sol[row+i][col+i] == 'Q')
                                       return false;
         }
         for(i=1; row-i>=0 && col+i<n; i++)
         {
                  if(sol[row-i][col+i] == 'Q')
                                       return false;
         }
         for(i=1; row-i>=0 && col-i>=0; i++)
         {
                  if(sol[row-i][col-i] == 'Q')
                                      return false;
         }
         for(i=1; row+i<n && col-i>=0; i++)
         {
                  if(sol[row+i][col-i] == 'Q')
                                       return false;
         }
         return true;
    }
         
};

int main()
{
    int in = 8;
    int i, j, k;
    Solution *slt = new Solution();
    vector<vector<string> > result;
    result = slt->solveNQueens(in);
    for(i=0; i<result.size(); i++)
    {
             cout<<"Solution "<<i<<endl;
             for(j=0; j<in; j++)
             {
                      for(k = 0; k<in; k++)
                      {
                            cout<<result[i][j][k] << ' ';
                      }
                      cout<<endl;
             }
    }
    cin >> in;
    return 0;
}
