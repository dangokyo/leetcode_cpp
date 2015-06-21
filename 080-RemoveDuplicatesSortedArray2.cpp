#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i;
        int index = 0, count = 0;
        
        for(i=0; i<n; i++)
        {
                 if(i==0){
                          A[index] = A[0];
                          index++;
                          continue;
                 }
                 if(A[i] == A[i-1]){
                         count++;
                         if(count == 1)
                         {
                                  A[index] = A[i];
                                  index++;
                         }
                         else if(count>=2)
                         {
                              continue;
                         }
                 }
                 else if(A[i] != A[i-1]){
                      count = 0;
                      A[index] = A[i];
                      index++;
                 }
        }
        return index;
    }
};

int main()
{
    int A[10] = {1, 1, 1, 2, 3, 3, 4, 9, 9, 9};
    Solution *slt = new Solution();
    int i;
    int length;
    length = slt->removeDuplicates(A, 10);
    cout<<length<<endl;
    for(i=0; i<length; i++)
             cout<<A[i]<<' ';
    cin>>i;
    return 0;
}
