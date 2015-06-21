#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign=0;
        int ans = 0;
        int t;
        if(x>0) sign = 1;
        else sign = -1;
        x = abs(x);
        while(x>0)
        {
                  t = x%10;
                  ans = ans*10 + t;
                  x = x/10;
                  if(ans >INT_MAX/10 && x != 0) return 0;
        }
        return ans*sign;
    }
};

int main()
{
    int in = -1534236469;
    Solution *slt = new Solution();
    cout<<slt->reverse(in)<<endl;
    getchar();
    return 0;
}
