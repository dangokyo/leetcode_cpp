#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
           string ans;
           string tmp;
           int i, length, count=0;
           char cur, t;
           char buffer[100];
           if(n == 1)
           {
                ans = "1";
           }
           else if(n > 1)
           {
                tmp = countAndSay(n-1);
                length = tmp.size();
                cur = tmp[0];
                for(i=0; i < length; i++)
                {
                       if(tmp[i] == cur)
                       {
                                 count++;
                                 continue;
                       }
                       else if(tmp[i] != cur)
                       {
                            IntToBuffer(buffer, count);
                            ans.append(buffer);
                            ans.insert(ans.end(), cur);
                            cur = tmp[i];
                            count = 1;
                       }
                }
                IntToBuffer(buffer, count);
                ans.append(buffer);
                ans.insert(ans.end(), cur);    
           }
           return ans;
    }
    
    int IntToBuffer(char buffer[], int n)
    {
        int digit = 0;
        int i = 0 , t1;
        char tmp[100];
        t1 = n;
        while(t1!=0)
        {
                    tmp[i] = '0' + (t1 % 10);
                    t1 = t1 / 10;
                    digit++;
                    i++;
        }
        for(i=0; i < digit; i++)
                 buffer[i] = tmp[digit - i - 1];
        buffer[i] = '\0';
        return 0;
    }
};


int main()
{
    Solution *slt = new Solution();
    cout<< slt->countAndSay(6);
    
    char c;
    cin>>c;
    
    return 0;
}
    
