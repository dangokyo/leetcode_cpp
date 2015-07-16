#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int length = nums.size();
        if(length <= 1) return nums;
        vector<int> dp1(length, 1);
        vector<int> dp2(length, 1);
        int i;
        for(i=1; i<length; i++){
                 dp1[i] = dp1[i-1] * nums[i-1];         
        }
        for(i=length-2; i>=0; i--){
                        dp2[i] = dp2[i+1]*nums[i+1];
        }
        for(i=0; i<length; i++){
                 ans.push_back(dp1[i] * dp2[i]);
        }
        
        return ans;
    }
};

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(4);
    Solution *slt = new Solution();
    vector<int> result = slt->productExceptSelf(in);
    for(int i=0; i<in.size(); i++)
            cout<<result[i]<<' ';
    getchar();
    return 0;
}
