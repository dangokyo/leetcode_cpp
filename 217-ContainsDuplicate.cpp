#include<iostream>
#include<vector>
#include<set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset;
        int length = nums.size();
        int i;
        for(i=0; i<length; i++)
        {
        	if(myset.count(nums[i]) > 0) return true;
        	else myset.insert(nums[i]);
        }
        return false;
    }
};


int main()
{
	vector<int> in;
	Solution *slt = new Solution();
	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
	in.push_back(4);
	in.push_back(5);
	in.push_back(6);
	cout<<slt->containsDuplicate(in)<<endl;
	return 0;
}
