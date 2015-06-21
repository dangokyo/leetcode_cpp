#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
         int start = 0;
         int end = n - 1;
         int mid;
         int i;
         while(start < end - 1)
         {
                     if(A[start] == A[end])
                     {
                                 if(A[start] == target){
                                             return true;
                                 }
                                 while(A[start]== A[start+1]){
                                                  start++;
                                 }
                                 while(A[end] == A[end-1]){
                                              end--;
                                 }
                                 start++;
                                 end--;
                                 continue;
                     }
                     while(A[start]==A[start+1]){
                                                 start++;
                     }
                     while(A[end] == A[end-1]){
                                  end--;
                     }
                     mid = (start + end)/2;
                     if(A[mid] == target){
                               return true;
                     }
                     else if(A[start] == target){
                          return true;
                     }
                     else if(A[end] == target ){
                          return true;
                     }                          
                     else if(A[mid] < A[end])
                     {
                          if(A[mid]< target && target < A[end]){
                                     start = mid;
                          }
                          else{
                               end = mid;
                          }
                     }
                     else if(A[mid] > A[start])
                     {
                          if(A[mid] > target && target > A[start]){
                                    end = mid;
                          }
                          else{
                               start = mid;
                          }
                     }
         }
         if(start <= n-1){
                  if(A[start] == target){
                              return true;}
         }
         if(end > 0){
                if(A[end] == target){
                          return true;}
         } 
         return false;
    }
};

int main()
{
    //int A[9] = {2, 2, 4, 6, 7, 1, 1, 1, 2};
    int A[3] = {0,0,0};
    Solution *slt = new Solution();
    int in;
    cout<<(bool)slt->search(A, 3, 1)<<endl;
    cin>>in;
    return 0;
}
    
