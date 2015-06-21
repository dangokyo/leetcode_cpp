#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> sol;
        string row;
        int i;
        
        if(n==1)
        {
                ans = 1;
                return ans;
        }
        
        for(i = 0; i<n; i++)
              row += ".";
        for(i=0; i<n; i++)
                 sol.push_back(row);
        
        NQueensSolver(ans, sol, 0, n);
        return ans;
    }
    
    int NQueensSolver(int &ans, vector<string> &sol, int level, int n)
    {
       if(level == n)
       {
                ans++;
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
    for(in=1; in<=14; in++)
    {
             cout<<slt->totalNQueens(in)<<endl;
    }
    cin >> in;
    return 0;
}
