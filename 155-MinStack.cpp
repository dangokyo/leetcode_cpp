#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
       stack<int> mystack;
       stack<int> minstack;
       void push(int x) {
            mystack.push(x);
            if(minstack.empty() || minstack.top()>=x)
            {
                                minstack.push(x);
            }
       }

       void pop() {
            if(minstack.top() == mystack.top())
            {
                                minstack.pop();
            }
            if(mystack.empty())
            {
                               return;
            }
            else mystack.pop();
       }

       int top() {
           return mystack.top();
       }

       int getMin() {
           return minstack.top();
       }
};

int main()
{
    MinStack stack;
    cout<<"step1"<<endl;
    stack.push(0);
    cout<<"step2"<<endl;
    stack.push(1);
    cout<<"step3"<<endl;
    stack.push(0);
    cout<<"step4"<<endl;
    stack.getMin();
    cout<<"step5"<<endl;
    stack.pop();
    cout<<"step6"<<endl;
    stack.getMin();
    cout<<"step7"<<endl;
    return 0;
}
