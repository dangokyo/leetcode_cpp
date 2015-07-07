#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
    stack<int> main_stack;
    stack<int> sub_stack;
    
    // Push element x to the back of queue.
    void push(int x) {
        main_stack.push(x);
        return;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        MoveStack(main_stack, sub_stack);
        sub_stack.pop();
        MoveStack(sub_stack, main_stack);
        return;
    }

    // Get the front element.
    int peek(void) {
        MoveStack(main_stack, sub_stack);
        int t = sub_stack.top();
        //cout<<"peek:"<<t<<endl;
        MoveStack(sub_stack, main_stack);
        return t;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return main_stack.empty();
    }
    
    void MoveStack(stack<int>& srcStack, stack<int>& dstStack)
    {
         while(!srcStack.empty()){
                                 int t = srcStack.top();
                                 dstStack.push(t);;
                                 srcStack.pop();                        
         }    
         return;
    }
};

int main()
{
    Queue myqueue;
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);
    myqueue.push(4);
    while(!myqueue.empty()){
                            cout<<myqueue.peek()<<endl;                        
                            myqueue.pop();
    }
    getchar();
    return 0;
}
