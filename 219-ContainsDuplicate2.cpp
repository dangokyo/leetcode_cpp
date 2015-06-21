#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	map<int, int> mymap;
    	int i, length = nums.size();
    	for(i=0; i<length; i++)
    	{
    		if(mymap.count(nums[i]) > 0)
    		{
    			if(i - mymap[nums[i]] <=k )
    			{
    				return true;
    			}
    			else mymap[nums[i]] = i;
    		}
    		else
    		{
    			mymap[nums[i]] = i;
    		}
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
	in.push_back(1);
	in.push_back(5);
	in.push_back(6);
	cout<<slt->containsNearbyDuplicate(in, 3)<<endl;
	return 0;
}
