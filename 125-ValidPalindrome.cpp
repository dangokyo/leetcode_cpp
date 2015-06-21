#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
         string str;
         int l = s.size();
         int i;
         for(i=0; i<l; i++)
         {
                  if(s[i] <= 'z' && s[i]>= 'a')
                  {
                          str.push_back(s[i]);
                  }
                  else if(s[i]<= 'Z' && s[i]>='A')
                  {
                       str.push_back((char)(s[i] + 32));
                  }
                  else if(s[i]<='9' && s[i]>= '0')
                  {
                       str.push_back(s[i]);
                  }
         }
         l = str.size();
         for(i=0; i<l/2; i++)
         {
                  if(str[i] != str[l-1-i]) return false;
         }
         return true;
        
    }
};


int main()
{
    //string in = "A man, a plan, a canal: Panama";
    string in = "1a2";
    Solution *slt = new Solution();
    cout<<slt->isPalindrome(in);
    cin>>in;
    return 0;
}
