// RomanToInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
		int i, length;
		length = s.size();
		int ans=0;

		for(i = 0; i < length;)
		{
			if(s[i] == 'M')       //M is 1000
			{
				ans += 1000;
				i++;
			}
			else if(s[i] == 'D')  //D is 500
			{
				ans += 500;
				i++;

			}
			else if(s[i] == 'C')  //C is 100
			{
				if(s[i+1] == 'M')
				{
					ans += 900;
					i +=2;
				}
				else if(s[i+1] == 'D')
				{
					ans += 400;
					i += 2;
				}
				else
				{
					ans += 100;
					i++;
				}
			
			}
			else if(s[i] == 'L')  //L is 50
			{
				ans +=50;
				i++;
			}
			else if(s[i] == 'X')  //X is 10
			{
				if(s[i+1] == 'C')
				{
					ans += 90;
					i +=2;
				}
				else if(s[i+1] == 'L')
				{
					ans += 40;
					i += 2;
				}
				else
				{
					ans += 10;
					i++;
				}
			}
			else if(s[i] == 'V')  //V is 5
			{
				ans += 5;
				i++;
			}
			else if(s[i] == 'I')  //I is 1
			{
				if(s[i+1] == 'X' )
				{
					ans += 9;
					i +=2;
				}
				else if(s[i+1] == 'V')
				{
					ans += 4;
					i += 2;
				}
				else
				{
					ans += 1;
					i++;
				}
			}
		}
        
		return ans;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	string in = "MI";
	Solution *slt = new Solution();
	cout<<slt->romanToInt(in);

	char x;
	cin>>x;
	return 0;
}

