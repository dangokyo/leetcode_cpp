#include<iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        
        int pos=0, i=0;
        for(i=0; i<n; i++)
        {
                 if(A[pos] == A[i])
                 {
                             continue;
                 }
                 pos++;
                 A[pos] = A[i];   
        }
        return pos+1;
    }
};

int main()
{
    Solution *slt = new Solution();
    int in[] = {1,1,2};
    int result = slt->removeDuplicates(in,3);
    cout<<result<<endl;
    cin>>result;
    return 0;
}
