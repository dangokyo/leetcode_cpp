#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
    	int length = s.size();
    	int i;
    	int ans = 0, cur = 0;
    	int curSign, nextSign;
    	int curNum;
    	int sign[3] = {0, 1, -1};
    	stack<int> mystack;
    	while(s[0] == ' ') s.erase(0, 1);
    	
    	i=0;
    	curSign = 1;
    	if(s[0]=='-')
    	{
    		i = 1;
    		curSign = 2;
    	}
    	curNum = getNumber(i, s);
    	while(true)
    	{
    		if(s[i] == ' ') i++;
    		//cout<<"processing:"<<i<<' '<<curSign<<' '<<curNum<<endl;
    		
    		nextSign = getNextSign(i, s);
    		//cout<<"nextsign:"<<nextSign<<endl;
    		if(nextSign==0)
    		{
    			mystack.push(sign[curSign] * curNum);
    			break;
    		}
    		
    		if(s[i] == ' ') i++;
    		int t = getNumber(i, s);
    		//cout<<"next number:"<<t<<endl;
    		if(nextSign == 1 || nextSign == 2)
    		{
    			mystack.push(sign[curSign] * curNum);
    			curNum = t;
    			curSign = nextSign;
    		}
    		else if(nextSign == 3)
    		{
    			curNum = curNum * t;
    		}
    		else if(nextSign == 4)
    		{
    			curNum = curNum/t;
    		}
    		
    	}
    	
    	
    	while(!mystack.empty())
    	{
    		ans += mystack.top();
    		mystack.pop();
    	}
    	return ans;
        
    }
    
    int getNextSign(int& pos, string& s) // 0 for no further sign, 1 for '+', 2 for '-', 3 for '*', 4 for '/'
	{
		if(pos >= s.size()-1) return 0;
		int ans;
		if(s[pos] == '+') ans = 1;
		else if(s[pos] == '-') ans = 2;
		else if(s[pos] == '*') ans = 3;
		else if(s[pos] == '/') ans = 4;
		pos++;
		return ans;	
	}
	
	int getNumber(int& pos, string& s)
	{
		int ans = 0;
		while(s[pos]<='9' && s[pos]>='0')
		{
			ans = ans * 10 + (s[pos]-'0');
			pos++;
		}
		return ans;
	}
};

int main()
{
	Solution *slt = new Solution();
	string in = " 3/2";
	cout<<slt->calculate(in);
	return 0;
}
