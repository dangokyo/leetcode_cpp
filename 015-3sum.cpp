// 15-3sum.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
		
		if(num.size()<3)
		{
			return ans;
		}

		vector<int> tmp;
		int length = num.size();
		int i, left, right, mid;
		std::sort(num.begin(), num.end());

		for(i=0; i< length - 2; ++i)
		{
			left = i + 1;
			right = length - 1;

			if( i > 0 && num[i] == num[i-1])
			{
				continue;
			}


			while(left < right)
			{
				if(num[i] + num[left] + num[right] > 0)
				{
					--right;
				}
				else if(num[i] + num[left] + num[right] < 0)
				{
					++left;
				}
				else if(num[i] + num[left] + num[right] == 0)
				{
				    tmp.clear();
					tmp.push_back(num[i]);
					tmp.push_back(num[left]);
					tmp.push_back(num[right]);
					ans.push_back(tmp);

					++left;
					--right;

					while(left < right && num[left]==num[left-1])
					{
						++left;
					}
					while(left < right && num[right]==num[right+1])
					{
						--right;
					}
				}
				
			}
		}
		return ans;
        
    }
};


int DisplayVector(vector<int> v)
{
	int length = v.size();
	int i;
	for(i=0; i< length; i++)
	{
		std::cout<<v[i]<<' ';
	}
	std::cout<<endl;
	return 0;
}

int main()
{
	Solution *slt = new Solution();
	char a;
	vector<int> numbers;
    vector< vector<int> > result;
	numbers.push_back(0);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(-1);
	numbers.push_back(-4);
	result = &slt->threeSum(numbers);
	for(int i=0 ; i < result.size(); i++)
	{
		DisplayVector(result[i]);
	}

	return 0;
}

