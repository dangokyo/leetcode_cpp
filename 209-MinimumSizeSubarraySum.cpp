#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = nums.size();
        int left = 0;
        int right = 0;
        int ans = length;
        int sum = 0;
        while(right < length)
        {
        	while(right < length && sum < s)
        	{
        		sum += nums[right];
        		right++;
        	}
        	while(left < right && sum >= s)
        	{
        		if(ans > right - left) ans = right - left;
        		sum = sum - nums[left];
        		left++;
        	}
        }
        if(ans == length && sum < s) return 0;
        return ans;
    }
};

int main()
{
    vector<int> in;
    in.push_back(2);
    in.push_back(3);
    //in.push_back(1);
    //in.push_back(2);
    //in.push_back(4);
    //in.push_back(3);
    Solution *slt = new Solution();
    cout<<slt->minSubArrayLen(7, in);
    return 0;
}
