#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left, right, mid;
        int length = num.size();
        left = 0;
        right =length - 1;
        int ans;
        while(left < right-1)
        {
        	while(left<right && num[left] == num[left+1])
        	{
        		left++;
        	}
        	while(left<right && num[right-1] == num[right])
        	{
        		right--;
        	}
        	
        	mid = (left + right)/2;
        	if(num[mid]>=num[left] && num[mid] >= num[right])
        	{
        		left = mid;
        	}
        	else if(num[mid]<=num[left] && num[mid]<=num[right])
        	{
        		right = mid;
        	}
        	else if(num[mid] < num[right] && num[left]<num[mid])
        	{
        		right = mid;
        	}
        	else if(num[mid] > num[right] && num[left]<num[mid])
        	{
        		left = mid;
        	}
        }
        
        ans = (num[left] >= num[right])?num[right]:num[left];
		return ans;
    }
};

int main()
{
	vector<int> in;
	in.push_back(4);
	/*in.push_back(5);
	in.push_back(6);
	in.push_back(7);
	in.push_back(0);
	in.push_back(1);
	in.push_back(2);*/
	Solution *slt = new Solution();
	cout<<slt->findMin(in)<<endl;
	return 0;
}
