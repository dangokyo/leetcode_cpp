#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	map<int, bool> happy_set;
    	int next;
		happy_set[n] = true;
    	do
    	{
			next = getNext(n);
			if(happy_set.count(next))
			{
				break;
			}
			else
			{
				happy_set[next] = true;
				n = next;
			}
    	}while(next!=1);
    	
    	if(next==1)
    	{
    		return true;
    	}
    	else return false;
    	
        
    }
    
    int getNext(int n)
    {
    	int m;
    	int ans = 0;
    	while(n!=0)
    	{
    		m = n%10;
    		ans += m*m;
    		n = n/10;
    	}
    	return ans;
    }
};

int main()
{
	Solution *slt = new Solution();
	int m = 19;
	cout<<slt->isHappy(m)<<endl;
	return 0;
}
