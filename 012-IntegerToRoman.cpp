// IntegerToRoman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std; 

class Solution{
public:
	string intToRoman(int num) {
		char symbol[7] = { 'I','V','X', 'L','C', 'D','M'};  
		string ans;  
		int scale = 1000;  
		for(int i =6; i>=0; i-=2)  
		{  
			int digit = num/scale;  
			if(digit != 0)  
			{        
				if(digit <= 3)  
				{  
					ans.append(digit, symbol[i]);  
				}  
				else if(digit ==4)  
				{  
					ans.append(1, symbol[i]);  
					ans.append(1, symbol[i+1]);  
				}  
				else if(digit ==5)  
				{  
					ans.append(1, symbol[i+1]);  
				}  
				else if(digit <=8)  
				{  
					ans.append(1, symbol[i+1]);  
					ans.append(digit-5, symbol[i]);  
				}  
				else if(digit ==9)  
				{  
					ans.append(1, symbol[i]);  
					ans.append(1, symbol[i+2]);  
				}  
			}  
			num = num%scale;  
			scale/=10;        
		}  
		return ans;  
	} 
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution *slt = new Solution();
	cout<< slt->intToRoman(2456);

	char x;
	cin>>x;
	return 0;
}

