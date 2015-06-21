#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
                return 0;
        int i;
        vector<int> t;
        for(i=0; i<=n; i++){
                 t.push_back(0);
                 }
        t[0] = 1;
        t[1] = 1;
        for(i=2; i<=n; i++){
                 t[i] = t[i-1]+t[i-2];
                 }
        return t[n];
    }
};

int main()
{
    int in = 3;
    Solution *slt = new Solution();
    cout<<slt->climbStairs(in)<<endl;
    cin>>in;
    return 0;
}
