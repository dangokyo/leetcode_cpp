#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        int i;
        int ans =INT_MIN;
        vector<int> max(n, 0);
        vector<int> min(n, 0);
        max[n-1] = A[n-1];
        min[n-1] = A[n-1];
        
        for(i=n-2; i>=0; i--)
        {
                 if(A[i]>0)
                 {
                           if(max[i+1] > 0) 
                           {
                                       max[i] = A[i] * max[i+1];
                           }
                           else if(max[i+1]<=0)
                           {
                                max[i] = A[i];
                           }
                           
                           if(min[i+1] == 0)
                           {
                                       min[i] = A[i];
                           }
                           else min[i] = min[i+1] * A[i];
                 }
                 else if(A[i] < 0)
                 {
                      if(min[i+1] > 0)
                      {
                                  max[i] = A[i];
                                  min[i] = A[i] * max[i+1];   
                      }
                      else if(max[i+1]<0)
                      {
                           max[i] = A[i] * min[i+1];
                           min[i] = A[i];
                      }
                      else if(min[i+1]<0 && max[i+1]>0)
                      {
                                  max[i] = A[i] * min[i+1];
                                  min[i] = A[i] * max[i+1];   
                      }
                      else if(min[i+1]==0 && max[i+1]==0)
                      {
                           max[i] = A[i];
                           min[i] = A[i];    
                      }
                 }
                 else if(A[i] == 0)
                 {
                      continue;
                 }
        }
        for(i=0; i<n; i++)
        {
                 if(ans < max[i]) ans = max[i];
        }  
        return ans;
    }
};

int main()
{
    //int A[] = {1,2,4,-2,5,4,-3,1};
    //int A[]= {5, 2, 0, -1,  3, -2, 4};
    //int A[] = {-2};
    //int A[] = {-4, -3, -2};
    int A[] = {-3, 0, -2};
    Solution *slt = new Solution();
    cout<<slt->maxProduct(A, (sizeof(A)/4))<<endl;
    int i;
    cin>>i;
    return 0;
}
