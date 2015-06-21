#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int height = matrix.size();
        if(height==0) return 0;
        int width = matrix[0].size();
        if(width==0) return 0;
        
        int ans = 0;
        int t1, t2, t3;
        vector<int> v(width, 0);
        vector<vector<int> > dp(height, v);
        int i, j;
        for(i=0; i<width; i++)
        {
                 if(matrix[0][i] == '1') 
                 {
                                 dp[0][i] = 1;
                                 ans = 1;
                 }
        }
        for(i=0; i<height; i++)
        {
                 if(matrix[i][0] == '1') 
                 {
                                 dp[i][0] = 1;
                                 ans = 1;
                 }
        }
        for(i=1; i<height; i++)
        {
                 for(j=1; j<width; j++)
                 {
                          t1 = dp[i-1][j];
                          t2 = dp[i][j-1];
                          t3 = dp[i-1][j-1];
                          if(matrix[i][j] == '1')
                          {
                                          dp[i][j] = min(min(t1, t2), t3) + 1;
                                                       
                          }
                          else dp[i][j] = 0;
                          
                          if(dp[i][j] > ans) ans = dp[i][j];      
                 }
        }
        return ans*ans;
        
    }
};

int main()
{
    vector<char> v(5, '1');
    vector<vector<char> > in(4, v);
    Solution *slt = new Solution();
    in[0][1] = '0';
    in[0][3] = '0';
    in[0][4] = '0';
    in[1][1] = '0';
    in[3][1] = '0';
    in[3][2] = '0';
    in[3][4] = '0';
    cout<<slt->maximalSquare(in)<<endl;
    getchar();
    return 0;
}
