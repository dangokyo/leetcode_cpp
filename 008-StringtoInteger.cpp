#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int digit=0, t;
        int length = str.size();
        int sign = 1;
        int ans=0;
        bool hasSign = false;
        
        while(str[i]==' ') i++;
        
		for(; i<length; i++)
        {
        	//cout<<i<<":"<<str[i]<<endl;
			if(str[i] == '-') 
			{
				sign = -1;
				if(hasSign) return 0;
				else hasSign = true;
				continue;
			}
			else if(str[i] == '+')
			{
				sign = 1;
				if(hasSign) return 0;
				else hasSign = true;
				continue;
			}
        	else if(str[i]>='0' && str[i] <= '9')
        	{
        		t = str[i]-'0';
        		if(sign > 0)
        		{
        			if(ans > INT_MAX/10 || (ans == INT_MAX/10 &&  t > INT_MAX-(INT_MAX/10)*10  ))
        			return INT_MAX;
        		}
        		else if(sign < 0)
        		{
        			if(ans > INT_MAX/10 || (ans == INT_MAX/10 && t >= INT_MAX - (INT_MAX/10)*10 + 1) )
        			{
        				//cout<<"test:"<<ans<<' '<<i<<' '<<t<<' '<<(INT_MAX - (INT_MAX/10)*10  + 1)<<endl;
        				return INT_MIN;
        			}
        		}
        		ans = ans*10 + t;
        	}
        	else
        	{
        		return ans*sign;
        	}
        }
        
        return ans*sign;
    }
};

int main()
{
	Solution *slt = new Solution();
	cout<<slt->myAtoi("21")<<endl;
	cout<<slt->myAtoi("-134123")<<endl;
	cout<<slt->myAtoi("-+134123")<<endl;
	cout<<slt->myAtoi("21af")<<endl;
	cout<<slt->myAtoi("-121af")<<endl;
	cout<<slt->myAtoi("2147483646")<<endl;
	cout<<slt->myAtoi("2147483646")<<endl;
	cout<<slt->myAtoi("2147483647")<<endl;
	cout<<slt->myAtoi("2147483648")<<endl;
	cout<<slt->myAtoi("-2147483648")<<endl;
	cout<<slt->myAtoi("-2147483649")<<endl;
	cout<<slt->myAtoi("-2147483647")<<endl;
    return 0;
}
