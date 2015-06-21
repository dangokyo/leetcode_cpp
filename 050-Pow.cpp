#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
    	double ans;
    	if(n==0)
    	{
    		return 1;	
    	}
    	else if((x - 1.00000) < 1e-32 && (x - 1.00000) > -1e-32)
    	{
    		return 1;
    	}
    	else if((x + 1.00000) < 1e-32 && (x + 1.00000) > -1e-32)
    	{
    		if(n%2 == 0)
    			return 1;
    		else if(n%2 == 1)
    			return -1;
    	}
    	if(n > 0)
    	{
    		ans = power(x, n);
    	}
    	else if(n < 0)
    	{
    		ans = 1 / power(x, -n) ;
    	}
    	return ans;
    }
    
    double power(double base, int n)
    {
    	double t, ans;
    	if(n == 0)
    	{
    		return 1;
    	}
    	t = power(base, n/2);
		if(n % 2 == 0)
    	{
    		ans = t * t;
    	}
    	else if(n % 2 == 1)
    	{
    		ans = t * t * base;
    	}
    	return ans;
    	
    }
};

int main()
{
	Solution *slt = new Solution();
	cout<<slt->pow(-1, -2147483647);
	return 0;
}
