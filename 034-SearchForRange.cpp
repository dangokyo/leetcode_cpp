#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
                vector<int> ans;
                int i, mid, left, right;
                
                mid = BinarySearch(A, 0, n-1, target);
                left = mid;
                right = mid;
                cout<<mid<<endl;
                if(mid == -1)
                {
                       ans.push_back(-1);
                       ans.push_back(-1);
                }
                while(mid != -1)
                {
                          left = BinarySearch(A, 0, mid-1, target);
                          if(left>0)
                          {
                                      mid = left;
                          }
                          else if(left == 0)
                          {
                               ans.push_back(left);
                               break;
                          }
                          else if(left==-1)
                          {
                               left = mid;
                               ans.push_back(left); 
                               break;
                          }
                }
                while(mid != -1)
                {
                          right = BinarySearch(A, mid+1, n-1, target);
                          if(right>0 && right < n -1)
                          {
                                      mid = right;
                          }
                          else if(right == n-1)
                          {
                               ans.push_back(right);
                               break;
                          }
                          else if(right==-1)
                          {
                               right = mid;
                               ans.push_back(right); 
                               break;
                          }
                }
                
                /*for(i=0; i<ans.size(); i++)
                         cout<<ans[i]<<' ';*/
                return ans;        
    }
    int BinarySearch(int A[], int start, int end, int target)
    {
        int mid;
        if(start == end && A[start] == target)
        {
                 return start;
        }
        else if(start == end && A[start] != target)
        {
             return -1;
        }
        else if(start+1 == end && A[start] == target)
        {
             return start;
        }
        else if(start + 1 == end && A[end] == target)
        {
             return end;
        }
        else if(start + 1 == end && A[start]!= target && A[end]!=target)
        {
             return -1;
        }
        
        mid = (start + end) / 2;
        if(A[mid] == target)
        {
                  return mid;
        }
        else if(A[mid] < target)
        {
             return BinarySearch(A, mid, end, target);
        }
        else if(A[mid] > target)
        {
             return BinarySearch(A, start, mid, target);
        }
    }
};

int main()
{
    Solution *slt = new Solution();
    int in[6] = {5,7,8,8,8,10};
    slt->searchRange(in, 6, 9);
    char c;
    cin>>c;
    return 0;
}
