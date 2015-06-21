#include <vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) { // 0 red. 1 white. 2 blue
        int red_index = 0;
        int blue_index = n - 1;
        int i;
        for(i=0; i<blue_index+1; i++)
        {
                 cout<<i<<endl;
                 for(int j=0; j<13; j++){
                          cout<<A[j]<<' ';
                          }
                 cout<<endl;
                 if(A[i] == 0)
                 {
                         A[i] = A[red_index];
                         A[red_index] = 0;
                         red_index++;
                         continue;
                 }
                 else if(A[i] == 2)
                 {
                      A[i] = A[blue_index];
                      A[blue_index] = 2;
                      blue_index--;
                      i--;
                      continue;
                 }
                 else if(A[i] == 1)
                 {
                      continue;
                 }
                 i++;
        }
    }
};

int main()
{
    int A[13] = {1, 0, 0, 0, 0, 2, 1, 0, 1, 0, 0, 0, 2};
    int i;
    Solution *slt = new Solution();
    slt->sortColors(A, 13);
    for(i=0; i<13; i++){
             cout<<A[i]<<' ';
    }
    cin>>i;
    return 0;
}
