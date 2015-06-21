#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int t=n;
        int ans = 0;
        do{
            t = t / 5;
            ans = ans+t;
        }while(t>0);
        return ans;
    }
};

int main()
{
    int in = 99;
    Solution *slt = new Solution();
    cout<<slt->trailingZeroes(in)<<endl;
    cin>>in;
    return 0;
}
