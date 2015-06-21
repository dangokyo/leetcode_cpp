#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 31;
        while(i>=0)
        {
                   ans = (ans<<1) + (n%2);
                   n = n>>1;           
                   i--;
        }
        return ans;
    }
};

int main()
{
    uint32_t in = 43261596;
    Solution *slt = new Solution();
    cout<<slt->reverseBits(in)<<endl;;
    cin>>in;
    return 0;
}
