#include <vector>
#include<string>
#include<iostream>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
         if(matrix.size()<0) return;
         int row, col;
         int i, j;
         row = matrix.size();
         col = matrix[0].size();
         int x_flag = 0;
         int y_flag = 0;
         for(i=0; i<row; i++)
         {
                  if(matrix[i][0] == 0) x_flag = 1;
         }
         for(i =0; i<col; i++)
         {
               if(matrix[0][i] == 0) y_flag = 1;
         }
         
         for(i=1; i<row; i++)
         {
                  for(j=1; j<col; j++)
                  {
                           if(matrix[i][j] == 0)
                           {
                                           matrix[i][0] = 0;
                                           matrix[0][j] = 0;
                           }
                  }
         }
         for(i=1; i<row; i++)
         {
                  for(j=1; j<col; j++)
                  {
                           if(matrix[i][0] == 0 || matrix[0][j] == 0)
                           {
                                           matrix[i][j] = 0;
                           }
                  }
         }
         if(x_flag == 1)
         {
                   for(i=0; i<row; i++)
                            matrix[i][0] = 0;
         }
         if(y_flag == 1)
         {
                   for(i=0; i<col; i++)
                            matrix[0][i] = 0;
         }
        
    }
};
int main()
{
    vector<vector<int> > in;
    vector<int> t;
    Solution *slt = new Solution();
    int i, j;
    for(i=0; i<10; i++)
             t.push_back(1);
    for(i=0; i<8; i++)
             in.push_back(t);
    in[3][5] = 0;
    slt->setZeroes(in);
    for(i=0; i<in.size(); i++)
    {
             for(j=0; j<in[i].size(); j++)
             {
                      cout<<in[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>i;
    return 0;
}
