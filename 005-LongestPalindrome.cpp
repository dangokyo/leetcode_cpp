// LongestPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
		int length = s.size();
		int index;
		int left, right;
		int ans = 0, tmp_ans;
		string ans_str;
		for(index = 0; index < length; index++)
		{
			//**aa**
			if(index + 1<length && s[index]==s[index+1])
			{
				left = index;
				right = index + 1;
				tmp_ans = 0;
				while(left>=0 && right < length)
				{
					if(s[left]==s[right])
					{
						tmp_ans += 2;
						left--;
						right++;
					}
					else break;
				}
				++left; --right;
				
				if(tmp_ans > ans)
				{
					ans = tmp_ans;
					ans_str = s.substr(left, right - left + 1);
				}
			}
			//**a**

			if(index - 1 < 0 || index + 1>=length)
			{
				tmp_ans = 1;
				left = index;
				right = index;
			}
			else
			{
				left = index - 1;
				right = index + 1;
				tmp_ans = 1;
				while(left>=0 && right < length)
				{
					if(s[left]==s[right])
					{
						tmp_ans += 2;
						left--;
						right++;
					}
					else break;
				}
				++left; --right;
			}
			
				
			if(tmp_ans > ans)
			{
				ans = tmp_ans;
				ans_str = s.substr(left, right - left + 1);
			}
		}
		return ans_str;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution *slt = new Solution();
	string in = "bb";
	string result = slt->longestPalindrome(in);
	cout<<result;

	char x;
	cin>>x;
	return 0;
}

