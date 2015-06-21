#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string t = string(s);
        int i;
        int ans = 0, flag=0;
        int length = t.size();
        for(i=length - 1; i >= 0; i--)
        {
                     if(flag==0 && t[i]==' ')
                     {
                                continue;
                     }
                     else if(flag==0 && t[i]!=' ')
                     {
                          flag = 1;
                          ans++;
                     }
                     else if(flag==1 && t[i]==' ')
                     {
                          break;
                     }
                     else if(flag==1 && t[i]!=' ')
                     {
                          ans++;
                     }
        }
        return ans;
    }
};

int main()
{
    Solution *slt = new Solution();
    string in = "Hello world           !";
    cout<< slt->lengthOfLastWord(in.c_str())<<endl;
    cin>>in;
    return 0;
}
