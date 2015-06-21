#include<iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        if(n==0) return ans;
        int t1 = n, t2;
        while(t1!=0)
        {
                   t2 = t1%26;
                   if(t2 == 0) 
                   {
                         ans = "Z" + ans;
                         t1 = t1/26 - 1;
                   }
                   else
                   {
                       ans =(char)(t2 - 1 + 'A') + ans;
                       t1 = t1/ 26;
                   }
        }
        return ans;
    }
};

int main()
{
    int in = 703;
    Solution *slt = new Solution();
    cout<<slt->convertToTitle(in)<<endl;
    cin>>in;
    return 0;
}
