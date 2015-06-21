#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
         stack<char> myStack;
         char t,p;
         int counter=0, i = 0;
         int length = s.size();
         for(i=0; i< length; i++)
         {
                  t = s.at(i);
                  //cout<<t<<endl;
                  if(t=='(' || t=='[' || t=='{')
                  {
                            myStack.push(t);
                  }
                  else if(t==')')
                  {
                       if(myStack.empty())
                       {
                                          return false;
                       }
                       p = myStack.top();
                       if(p=='(')
                       {
                                 myStack.pop();
                       }
                       else return false;
                  }
                  else if(t==']')
                  {
                       if(myStack.empty())
                       {
                                          return false;
                       }
                       p = myStack.top();
                       if(p=='[')
                       {
                                 myStack.pop();
                       }
                       else return false;
                  }
                  else if(t == '}')
                  {
                       if(myStack.empty())
                       {
                                          return false;
                       }
                       p = myStack.top();
                       if(p=='{')
                       {
                                 myStack.pop();
                       }
                       else return false;
                  }
                  
                  counter++;
                       
         }
         if(!myStack.empty())
                             return false;
         else return true;
         return false;
    }
};


int main()
{
    string in = "()[]{}";
    //string in = "([)]";
    //string in = "]";
    Solution *slt = new Solution();
    cout<<slt->isValid(in)<<endl;
    
    char x;
    cin>>x;
    return 0;
}
