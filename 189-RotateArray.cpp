#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int i = 0;
         int length = nums.size();
         k = k % length;
         vector<int> t_vec;
         for(i=length-k; i<length; i++)
         {
                         t_vec.push_back(nums[i]);                
         }
         for(i=length-1; i>=k ;i--)
         {
                         nums[i] = nums[i-k];
         }
         for(i=0; i<k; i++)
         {
                  nums[i] = t_vec[i];
         }
         return;
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int > in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(4);
    in.push_back(5);
    in.push_back(6);
    in.push_back(7);
    int k = 10;
    slt->rotate(in,k);
    int i = 0;
    for(i=0; i<in.size(); i++)
             cout<<in[i]<<' ';
    cin>>i;
    return 0;
}
