#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        //cout<<"start"<<endl;
        ans = SelectKth(nums, 0, nums.size()-1, k);
        return ans;
    }
    
    int SelectKth(vector<int>& nums, int left, int right, int k)
    {
        int middle;
        int ans;
        if(left == right) 
        {
                return nums[left];
        }
        else
        {
            middle = partition(nums, left, right);
            //return nums[middle];
            //cout<<"Select:"<<left<<" "<<right<<" "<<middle<<" "<<k<<endl;
            if(middle -left + 1 >= k)
            {
                      ans = SelectKth(nums, left, middle, k);
            }
            else
            {
                ans = SelectKth(nums, middle+1, right, k -(middle-left+1));
            }
        }
        return ans;
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[left];
        int l = left;
        int r = right;
        int t;
        //cout<<"partion init"<<left<<" "<<right<<endl;
        //getchar();
        /*cout<<"start:"<<left<<" "<<right<<endl;
        for(int i=0; i<nums.size(); i++) cout<<nums[i]<<' ';
        cout<<endl;*/
        while(l < r)
        {
                while(nums[r] <= pivot && l < r && r > left) 
                {
                              r--;
                }
                while(nums[l] >= pivot && l < r && l < right) 
                {
                              l++;
                              //while(nums[l] == nums[l+1]) l++;
                }
                //cout<<"partition:"<<l<<" "<<r<<endl;
                if(l < r)
                {
                     t = nums[l];
                     nums[l] = nums[r];
                     nums[r] = t;
                }
                /*cout<<l<<" "<<r<<endl;
                for(int i=0; i<nums.size(); i++) cout<<nums[i]<<' ';
                cout<<endl;*/
        }    
        nums[left] = nums[l];
        nums[l] = pivot;
        /*cout<<"end"<<endl;
        for(int i=0; i<nums.size(); i++) cout<<nums[i]<<' ';
        cout<<endl;*/
        return l;
    }
};

int main()
{
    //cout<<"start"<<endl;
    Solution *slt = new Solution();
    vector<int> in;
    in.push_back(3);
    in.push_back(3);
    in.push_back(2);
    in.push_back(1);
    in.push_back(5);
    in.push_back(6);
    in.push_back(4);
    cout<<slt->findKthLargest(in, 3)<<endl;
    cout<<slt->findKthLargest(in, 4)<<endl;
    cout<<slt->findKthLargest(in, 5)<<endl;
    return 0;
}
