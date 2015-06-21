#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int length = s.size();
        int i;
        int ans = 0;
        for(i=0; i<length; i++)
        {
                 ans = ans*26 + (int)(s[i]-'A') + 1;
        }
        return ans;
    }
};


int main()
{
    string in = "";
    Solution *slt = new Solution();
    cout<<slt->titleToNumber(in)<<endl;
    cin>>in;
    return 0;
}
