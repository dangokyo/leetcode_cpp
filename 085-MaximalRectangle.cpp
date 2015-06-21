#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int height = matrix.size();
        if(height == 0) return 0;
        int width = matrix[0].size();
        if(width == 0) return 0;
        
        int i, j;
        int ans = 0, sol;
        vector<int> v(width, 0);
        vector<vector<int> > dp(height+1, v);
        for(i=1; i<=height; i++)
        {
                 for(j=0; j<width; j++)
                 {
                          if(matrix[i-1][j] == '0') continue;
                          else dp[i][j] = dp[i-1][j]+1;         
                 }
        }
        
        for(i=1; i<=height; i++)
        {
                     sol = largestRectangleArea(dp[i]);
                     //cout<<i<<':'<<sol<<endl;
                     if(sol>ans) ans = sol;     
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& height) {
        int length = height.size();
        if(length == 0) return 0;
        else if(length == 1) return height[0];
        int result = 0;
        stack<int> myStack;
        int i;
        int left, right;
        height.push_back(0);
        for(i=0; i<length+1; i++)
        {
                 while(!myStack.empty() && height[myStack.top()] > height[i])
                 {
                                        right = myStack.top();
                                        myStack.pop();
                                        if(myStack.size() == 0)
                                        {
                                                           left = -1;
                                        }
                                        else left = myStack.top();    
                                        result = max(result, height[right]*(i-1 - left));     
                 } 
                 //cout<<result<<endl;            
                 myStack.push(i);        
        }
        return result;
    }
};

int main()
{
    vector<char> v(5, '1');
    vector<vector<char> > board(6, v);
    board[1][3] = '0';
    Solution *slt = new Solution();
    cout<<slt->maximalRectangle(board)<<endl;
    getchar();
    return 0;
}
