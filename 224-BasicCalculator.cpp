#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        int length = s.size();
        int i;
        stack<int> signStack;
        stack<int> numStack;
        for(i=0; i<length; i++)
        {
                 if(s[i] == ' ')
                 {
                         continue;
                 }
                 else if(s[i] == '(')
                 {
                      signStack.push(sign);
                      numStack.push(ans);
                      ans = 0;
                      sign = 1;
                 }
                 else if(s[i] == ')')
                 {
                          ans = numStack.top()+ ans*signStack.top();
                          numStack.pop();
                          signStack.pop();
                 }
                 else if(s[i] == '+')
                 {
                      sign = 1;
                 }
                 else if(s[i] == '-')
                 {
                      sign = -1;
                 }
                 else if(s[i]<='9' && s[i]>='0')
                 {
                      int tmp = 0;
                      while(s[i]<='9' && s[i]>='0')
                      {
                                      tmp = tmp*10 + int(s[i]-'0');   
                                      i++;             
                      }
                      i--;
                      ans = ans + tmp*sign;
                      //cout<<i<<":"<<ans<<endl;
                 }
        }
                      
        return ans;
    }
};

int main()
{
    //string in = "(1+(4+5+2)-3) + (6+8)";
    string in = "1-(1+2+3)";
    Solution *slt = new Solution();
    cout<<slt->calculate(in)<<endl;
    cin>>in;
    return 0;
}
