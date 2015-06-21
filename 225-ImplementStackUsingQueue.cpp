#include<iostream>
#include<queue>
#include<stack>

using namespace std;
class Stack {
public:
    // Push element x onto stack.
    queue<int> main;
    queue<int> tmp;
    void push(int x) {
        main.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(this->empty()) return;
        else if(main.size() ==1)
        {
        	main.pop();
        }
        else
        {
        	int t;
        	while(tmp.size()) tmp.pop(); 
        	
        	while(main.size() > 1)
        	{
        		t = main.front();
        		tmp.push(t);
        		main.pop();
        	}
        	main.pop();
        	main = tmp;
        }
    }

    // Get the top element.
    int top() {
    	int t;
        if(main.size() ==1)
        {
        	t = main.front();
        	return t;
        }
        else
        {
        	while(tmp.size()) tmp.pop(); 
        	
        	while(main.size() > 1)
        	{
        		t = main.front();
        		tmp.push(t);
        		main.pop();
        	}
        	t = main.front();
        	main.pop();
        	main = tmp;
        	main.push(t);
        	return t;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return main.empty();
    }
};


int main()
{
	Stack mystack;
	mystack.push(5);
	mystack.push(4);
	mystack.push(3);
	cout<<mystack.top()<<endl;
	mystack.pop();
	cout<<mystack.top()<<endl;
	mystack.push(12);
	mystack.push(16);
	while(!mystack.empty())
	{
		cout<<mystack.top()<<endl;
		mystack.pop();
	}
	
	return 0;
}
