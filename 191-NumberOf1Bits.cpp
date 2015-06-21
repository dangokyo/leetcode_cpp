#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n!=0)
        {
                   if(n%2 == 1) ans++;
                   n = n>>1;
        }
        return ans;
    }
};

int main()
{
    Solution *slt = new Solution();
    uint32_t in = 11;
    cout<<slt->hammingWeight(in)<<endl;;
    cin>>in;
    return 0;
}
