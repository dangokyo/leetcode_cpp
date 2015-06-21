#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        int n = 0, i;
        for(i=0; i<length; i++)
        {
                 if(nums[i]>0) n++;         
        }
        //cout<<"length:"<<n<<endl;
        vector<bool> vec(n+2, false);
        for(i=0; i<length; i++)
        {
            if(nums[i] <= n && nums[i]>=1)
            {
                vec[nums[i]] = true;
            }
        }
        for(i=1; i<=n+1 && vec[i]; i++) ;
        return i;
    }
};

int main()
{
    vector<int> in;
    Solution *slt = new Solution();
    in.push_back(1);
    in.push_back(4);
    in.push_back(3);
    in.push_back(2);
    cout<<slt->firstMissingPositive(in);
    getchar();
    return 0;
}
