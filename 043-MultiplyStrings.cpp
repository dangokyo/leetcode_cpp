#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	int t1, t2;
    	int i, j, digit, carry, l1, l2, mul;
    	l1 = num1.size();
    	l2 = num2.size();  
    	carry = 0;
		string ans(l1 + l2 + 1, '0');
		if(!strcmp(num1.c_str(), "0") || !strcmp(num2.c_str(), "0")) return "0";
		for(i=l1-1; i>=0; i--)
		{
			for(j=l2 - 1; j>= 0; j--)
			{
				t1 = num1[i] - '0';
				t2 = num2[j] - '0';
				digit = ans[i+j+2] - '0';
				mul = t1 * t2;
				//cout<<"test:"<<i<<' '<<j<<' '<<mul<<' '<<carry<<' '<<digit<<endl;
				ans[i+j+2] = (mul + carry + digit) %10 + '0';
				//cout<<ans<<endl;
				carry = (mul + carry + digit) / 10;
			}
			if(carry > 0)
			{
				ans[i+1] = carry + '0';
				carry = 0;
			}
			//cout<<"After one round:"<<ans<<endl;
				
		}
		for(i=0; i<2; i++)
		{
				if(ans[i] != '0')
					break;
		}
		ans = ans.substr(i, l1 + l2 + 1);
        return ans;
    }
};

int main()
{
	string in1, in2;
	//in1 = "143143214321322";
	//in2 = "13513412399";
	in1 = "9";
	in2 = "0";
	Solution *slt = new Solution();
	cout<<slt->multiply(in1, in2);
	return 0;
}
