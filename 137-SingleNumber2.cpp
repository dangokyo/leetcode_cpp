#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> digits(32, 0);
        int i, j;
        int t;
        int ans = 0;
        for(i=0; i<n; i++)
        {
              t = A[i];
              for(j=0; j<32; j++)
              {
                       digits[j] +=  (t>>j) & 1;
              }
        }
        for(i=0; i<32;i++)
        {
                 digits[i] = digits[i] % 3;
        }
        for(i=31; i>=0; i--)
        {
                  ans = ans * 2 + digits[i];
        }
        return ans;        
    }
};

int main()
{
    int A[7] = {1,3,1,5,3,3,1};
    int in = 7;
    Solution *slt = new Solution();
    cout<<slt->singleNumber(A, in)<<endl;
    cin>>in;
    return 0;
}
