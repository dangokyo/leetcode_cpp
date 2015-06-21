// PalindromeNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int number,t, mid, left, right, left_num, right_num;
		int digit  = 0;
		if(x >0)
		{
			number = x;
		}
		else if(x==0)
		{
		    return true;
		}
		else if(x < 0) 
		{
		    return false;
		}

		number = x;
		t = number;
		//cout << number << endl;
		while(t != 0)
		{
			++digit;
			t = t/10;
		}


		if(digit % 2 ==0) 
		{
			left = 1;
			right = 1;
			for(int i = 0; i<digit/2 - 1; i++)
			{
				left = left *10;
				right = right * 10;
			}
			left = left * 10;
			for(int i = 0; i < digit/2; i++)
			{
				left_num = (number/ left) % 10;
				right_num = (number / right)% 10;
				//cout<<"left:"<<left_num<<"right:"<<right_num<<endl;
				if(left_num == right_num)
				{
					left = left * 10;
					right = right / 10;
					continue;
				}
				else return false;
			}

		}
		else if(digit % 2 == 1)
		{
			mid = 1;
			for(int i = 0; i<digit/2; i++)
			{
				mid = mid *10;
			}
			left = mid;
			right = mid;
			for(int i = 0; i < digit/2 + 1; i++)
			{
				left_num = (number/ left) % 10;
				right_num = (number / right)% 10;
				//cout<<"left:"<<left_num<<"right:"<<right_num<<endl;
				if(left_num == right_num)
				{
					left = left * 10;
					right = right / 10;
					continue;
				}
				else return false;
			}
		}
		return true;

    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution *slt = new Solution();
	int in = 1331;//1234544321;
	bool result = slt->isPalindrome(in);
	cout << result <<endl;
	char x;
	cin>> x;
	return 0;
}

