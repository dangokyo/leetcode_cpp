#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
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
    Solution *slt = new Solution();
    vector<int> in;
    /*in.push_back(2);
    in.push_back(1);
    in.push_back(5);
    in.push_back(6);
    in.push_back(2);
    in.push_back(3);*/
    
    in.push_back(5);
    in.push_back(5);
    in.push_back(1);
    in.push_back(7);
    in.push_back(1);
    in.push_back(1);
    in.push_back(5);
    in.push_back(2);
    in.push_back(7);
    in.push_back(6);
    cout<<slt->largestRectangleArea(in)<<endl;
    getchar();
    return 0;
}
