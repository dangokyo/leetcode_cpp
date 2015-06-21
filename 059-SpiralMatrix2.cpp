#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
                       vector<vector<int> > ans;
                       vector<int> t;
                       vector<vector<bool> > pass;
                       vector<bool> tb;
                       if(n == 0)  return ans;
                       
                       int i;
                       int x = 1, y = 1;
                       int dir = 0; //0 for right, 1 for down, 2 for left, 3 for up
                       for(i=0; i<n; i++)
                                t.push_back(0);
                       for(i=0; i<n; i++)
                                ans.push_back(t);
                       for(i=0; i<n+2; i++)
                                tb.push_back(true);
                       for(i=0; i<n+2; i++)
                                pass.push_back(tb);
                       for(i=0; i<n+2; i++)
                       {
                                pass[0][i] = false;
                                pass[n+1][i] = false;
                                pass[i][0] = false;
                                pass[i][n+1] = false;
                       }
                       i = 1;
                       int size = n * n;
                       while(true)
                       {
                                //cout<<x<<' '<<y<<endl;
                                ans[x-1][y-1] = i;
                                pass[x][y] = false;
                                //Display(pass);
                                if(!pass[x][y+1] && !pass[x][y-1] && !pass[x+1][y] && !pass[x-1][y])
                                {
                                                break;
                                }
                                if(dir==0)
                                {
                                      if(pass[x][y+1])
                                      {
                                                      x = x;
                                                      y = y+1;
                                      }
                                      else
                                      {
                                          x = x+1;
                                          y = y;
                                          dir = 1;
                                      }    
                                }
                                else if(dir == 1)
                                {
                                     if(pass[x+1][y])
                                     {
                                                     x = x+1;
                                                     y = y;
                                     }
                                     else
                                     {
                                         x = x;
                                         y = y-1;
                                          dir = 2;
                                     }
                                }
                                else if(dir == 2)
                                {
                                     if(pass[x][y-1])
                                     {
                                                     x = x;
                                                     y = y-1;
                                     }
                                     else
                                     {
                                         x = x-1;
                                         y = y;
                                         dir = 3;
                                     }
                                }
                                else if(dir == 3)
                                {
                                     if(pass[x-1][y])
                                     {
                                                     x = x-1;
                                                     y = y;
                                     }
                                     else
                                     {
                                         x = x;
                                         y = y+1;
                                         dir = 0;
                                     }
                                }
                                i++;
                       }   
                       return ans;       
    }
};

int main()
{
    int in=4;
    Solution *slt = new Solution();
    vector<vector<int> > result;
    result = slt->generateMatrix(in);
    int i, j;
    for(i=0; i< in; i++)
    {
             for(j=0; j<in; j++)
             {
                      cout<<result[i][j]<<' ';
             }
             cout<<endl;
    }
    
    cin>>in;
    return 0;
}
