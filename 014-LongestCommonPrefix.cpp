// LongestCommonPrefix.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		int length = strs.size();
		int i, k = 0;
		char tmp;
		string ans;

		if(length == 0) return ans;
		while(true)
		{
			if(strs[0].size()==k)
			{
				break;
			}

			tmp = strs[0][k];
			for(i=1; i< length; i++)
			{
				if(strs[i].size()==k)
				{
					break;
				}
				if(strs[i][k] != tmp)
				{
					break;
				}
			}

			if(i!=length)
			{
				break;
			}
			else
			{
				ans.append(1, tmp);
			}
			k++;
		}
		return ans;

    }
};

int main()
{
	vector<string> in;
	Solution *slt = new Solution(); 
	in.push_back("abcdefg");
	in.push_back("abweerq");
	in.push_back("abhsa");

	cout<<slt->longestCommonPrefix(in);

	char x;
	cin>> x;
	return 0;
}

