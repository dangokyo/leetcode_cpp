#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> number_list;
        vector<int> index_list;
        vector<int> ans;
        int length = nums.size();
        if(length == 0) return ans;
        int i;
        
        number_list.push_back(nums[0]);
        index_list.push_back(0);
        for(i=1; i<k-1; i++){
                 updateList(number_list, index_list, nums[i], i);
        }
        for(i=k-1; i<length; i++){
                   if(index_list[0] <= i-k){
                                 number_list.erase(number_list.begin());
                                 index_list.erase(index_list.begin());   
                   }
                   updateList(number_list, index_list, nums[i], i);
                   ans.push_back(number_list[0]);
        }
        return ans;
    }
    
    void updateList(vector<int>& num_list, vector<int>& index_list, int target, int index)
    {
         int length = num_list.size();
         if(length == 0){
                   num_list.push_back(target);
                   index_list.push_back(index);
                   return;          
         }
         for(int i=length-1; i>=0; i--){
                 if(num_list[i] <= target){
                                num_list.pop_back();
                                index_list.pop_back();               
                 }
                 else break;
         }
         num_list.push_back(target);
         index_list.push_back(index);
         return;     
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int> in;
    /*in.push_back(1);
    in.push_back(3);
    in.push_back(-1);
    in.push_back(-3);
    in.push_back(5);
    in.push_back(3);
    in.push_back(6);
    in.push_back(7);*/
    vector<int> result = slt->maxSlidingWindow(in, 0);
    for(int i=0;i<result.size(); i++){
            cout<<result[i]<<' ';
    }
    getchar();
    return 0;
}
