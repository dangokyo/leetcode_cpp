#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {  
         //t difference nums[i] and nums[j], k displace i and j
         int length = nums.size();
         int i;
         set<int>::iterator set_min;
         if(length <2 || k==0 || t < 0) return false;
         set<int> myset;
         myset.insert(nums[0]);
         for(i=1; i<length; i++)
         {
                  if(i>k) myset.erase(nums[i-k-1]);
                  set_min = myset.lower_bound(nums[i] - t);
                  if(set_min != myset.end() && abs(nums[i] - *set_min) <=t ) return true;
                  
                  myset.insert(nums[i]);
         }
         return false;
    }
};

int main()
{
	Solution *slt = new Solution();
	vector<int> in;
	in.push_back(1);
	in.push_back(2147483647);
	//in.push_back(3);
	//in.push_back(1);
	//in.push_back(5);
	//in.push_back(6);
	cout<<slt->containsNearbyAlmostDuplicate(in, 1, 2147483647);
	getchar();
	return 0;
}
