#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int i;
        int ans = A[0];
        for(i=1; i<n; i++)
        {
                 ans ^= A[i];
                 cout<<i<<":"<<ans<<endl;
        }
        return ans;
    }
};

int main()
{
    int A[5] = {1,3,2,3,1};
    int in = 5;
    Solution *slt = new Solution();
    cout<<slt->singleNumber(A, in)<<endl;
    cin>>in;
    return 0;
}
