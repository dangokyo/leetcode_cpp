#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> mystack;
        int length = tokens.size();
        if(length == 1) return toInteger(tokens[0]);
        int i, t;
        int op1, op2;
        int ans = 0;
        for(i=0; i<length; i++)
        {
                 if(isOperator(tokens[i]))
                 {
                                          op2 = mystack.top();
                                          mystack.pop();
                                          op1 = mystack.top();
                                          mystack.pop();
                                          ans = process(tokens[i], op1, op2);
                                          mystack.push(ans);
                 }
                 else
                 {
                     mystack.push(toInteger(tokens[i]));
                 }
        }
        return ans;
    }
    
    bool isOperator(string s)
    {
         int length = s.size();
         if(length!=1) return false;
         
         if(s=="0" || s=="1" || s=="2" || s=="3" || s=="4" || s=="5" || s=="6" || s=="7" || s=="8" || s=="9") return false;
         
         return true;
    }
    
    int process(string operand, int op1, int op2)
    {
        if(operand == "+")
        {
                   return op1 + op2;
        }
        else if(operand == "-")
        {
             return op1 - op2;
        }
        else if(operand == "*")
        {
             return op1 * op2;
        }
        else if(operand == "/")
        {
             return op1/op2;
        }
    }
    
    int toInteger(string s)
    {
        int flag = 1;
        if(s[0] == '-')
        {
                flag = -1;
        }
        int length =s.size();
        int i;
        int ans = 0;
        for(i=0; i<length; i++)
        {
                 if(s[i] <= '9' && s[i]>='0') ans = ans * 10 + (s[i] - '0');
                 else continue;
        }
        return ans*flag;
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<string> in;
    in.push_back("4");
    in.push_back("13");
    in.push_back("5");
    in.push_back("/");
    in.push_back("+");
    int result = slt->evalRPN(in);
    cout<<result<<endl;
    cin>>result;
    return 0;
}
