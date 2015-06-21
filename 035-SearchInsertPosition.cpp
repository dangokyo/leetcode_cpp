#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(target < A[0])
        {
                  return 0;
        }
        else if(target > A[n-1])
        {
             return n;
        }
        
        int ans;
        ans = BinarySearch(A, 0, n-1, target);
        
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
             return start+1;
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
             return end;
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
    int in[6] = {1,3,5,6};
    cout<<slt->searchInsert(in, 4, 0)<<endl;
    char c;
    cin>>c;
    return 0;
}
