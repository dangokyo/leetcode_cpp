// ZigzagConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
		string ans;
		int length = s.size();
        int index, zigsize, row;
		//ans = s;
		if(nRows == 1) return s;

		zigsize = nRows * 2 - 2;
			//cout<<s[length - index - 1];
		for(row = 0; row < nRows; row++)
		{
			for(index = row; index < length; index += zigsize)
			{
				if(index >= length)
					break;

				ans.append(1,s[index]);

				if(row > 0 && row < nRows - 1)
				{
					int tmp = index + zigsize - 2 * row;
					if(tmp < length)
					{
						ans.append(1, s[tmp]);
					}
				}
			}

		}
		return ans;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	string in = "PAYPALISHIRING";
	string result;
	Solution *slt = new Solution();
	result = slt->convert(in, 3);
	cout<<result;

	char x;
	cin>>x;
	return 0;
}

