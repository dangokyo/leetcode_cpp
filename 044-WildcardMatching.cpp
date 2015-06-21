#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
         int length = s.size();
         int patternLength =p.size();
         if(patternLength==0) return !length;
         
         int stringIndex = 0;
         int patternIndex = 0;
         int stringPreviousIndex = 0;
         int patternPreviousIndex = -1;
         while(stringIndex < length)
         {
                           if(patternIndex < patternLength &&(s[stringIndex]==p[patternIndex] || p[patternIndex]=='?'))
                           {
                                          stringIndex++;
                                          patternIndex++;               
                           }
                           else if(patternIndex <patternLength && p[patternIndex]=='*')
                           {
                                stringPreviousIndex = stringIndex;
                                patternPreviousIndex = patternIndex;
                                patternIndex++;
                           }
                           else if(patternPreviousIndex >=0)
                           {
                                stringIndex = stringPreviousIndex + 1;
                                stringPreviousIndex = stringIndex;
                                patternIndex = patternPreviousIndex;
                           }
                           else return false;
         }
         
         if(stringIndex < length) return false;
         
         while(patternIndex < patternLength)
         {
                            if(p[patternIndex] == '*') patternIndex++;
                            else break;                   
         }
         
         if(patternIndex == patternLength) return true;
         else return false;
        
    }
};

int main()
{
    Solution *slt = new Solution();
    string s = "aa";
    string p = "*??*";
    cout<<slt->isMatch(s, p)<<endl;
    cin>>s;
    return 0;
}
