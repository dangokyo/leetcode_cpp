#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	long long int quotient, remainder;
    	int sign = 1;
    	long long int n = numerator;
    	long long int d = denominator;
    	if(numerator==0) return "0";
    	
    	if(numerator<0)
    	{
    		sign *= -1;
    		n = (long long int)numerator * (-1);
    	}
    	
    	if(denominator<0)
    	{
    		sign *= -1;
    		d = (long long int)denominator * (-1);
    	}
    	
    	string q, r;
    	string ans;
    	
    	quotient = n / d;
    	remainder = n%d;
    	q = Int2String(quotient);
    	r = Remainder2Fraction(remainder*10, d);
    	
    	if(r.size()==0) 
		{
			ans = q;
		}
		else
    	{
    		ans = q + "."+r;
    	}
    	if(sign == -1) ans = "-"+ans;
    	return ans;
    }
    
    string Int2String(long long int num)
    {
    	string ans;
    	if(num==0) return "0";
    	
    	long long int t = num;
		while(t!=0)
    	{
    		ans =(char)((t %10)+'0')+  ans;
    		t = t/10;
    	}
    	return ans;
    }
    
    string Remainder2Fraction(long long int num, long long int denominator)
    {
    	string ans;
    	if(num==0) return ans;
    	string t1 , t2;
    	long long int quotient = num;
    	int len, index;
    	int digit = 0;
    	map<int, int> rmap;
    	while(true)
    	{
    		rmap[quotient] = digit;
    		cout<<quotient<<" "<<denominator<<endl;
			if(quotient >= denominator)
			{
				ans = ans + (char)((quotient/denominator)+'0');
				quotient = quotient % denominator;
				quotient *=10;
				digit++;
			}
			else if(quotient<denominator)
			{
				ans = ans + '0';
				quotient *=10;
				digit++;
			}
			
			
    		if(rmap.count(quotient) > 0) 
			{
				len = ans.size();
				index = rmap[quotient];
				t1 = ans.substr(0, index);
				t2 = ans.substr(index, len - index);
				ans = t1+"("+t2+")";
				break;
			}
			
			if(quotient == 0)
			{
				break;
			}
    	}
    	return ans;
    }
};

int main()
{
	int in1 = -2147483648, in2 = 1;
	Solution *slt = new Solution();
	cout<<slt->fractionToDecimal(in1, in2)<<endl;	
    return 0;
}
