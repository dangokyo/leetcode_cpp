#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len1, len2;
        int i,j;
        len1 = strlen(haystack);
        len2 = strlen(needle);
        
        if(len1 == 0 && len2!=0) 
        {
                return -1;
        }
        else if(len2 == 0) 
        {
             return 0;
        }
        for(i=0; i< len1-len2+1; i++)
        {
                 for(j=0; j<len2; j++)
                 {
                          if(haystack[i+j] == needle[j])
                          {
                                           continue;
                          }
                          else break;
                 }
                 if(j==len2) return i;
                 else continue;
        }
        
        return -1;
    }
};

int main()
{    
    Solution *slt = new Solution();
    int result;
    char *buf1 = "andsoiemwuda";
    char *buf2 = "oiem";
    result = slt->strStr(buf1, buf2);
    cout<<result<<endl;
    cin>>result;
    
    return 0;
}
