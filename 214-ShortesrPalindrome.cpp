#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
           string t;
           int i, length, sol;
           
           t = s;
           reverse(t.rbegin(), t.rend());
           length = s.size();
           sol = 0;
           for(i=1; i<=length; i++)
           {
                    string t1 = s.substr(0, i);
                    string t2 = t.substr(length-i, i);
                    //cout<<t1<<" "<<t2<<endl;
                    if(t1 == t2) sol = i;
           }
           t = t.substr(0, length-sol);
           return t + s;
    }
};

int main()
{
    string in = "abcd";
    Solution *slt = new Solution();
    cout<<slt->shortestPalindrome(in)<<endl;
    cin>>in;
    return 0;
}
