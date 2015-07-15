#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int ans = searchSolver(nums, target, 0, length-1);
        return ans;
    }
    
    int searchSolver(vector<int>& nums, int target, int left, int right)
    {
        if(left == right){
                if(nums[left] == target) return left;
                else return -1;
        }
        
        int middle = (left + right)/2;
        int pivot = nums[middle];
        if(pivot == target) return middle;
        //cout<<left<<' '<<right<<' '<<pivot<<endl;
        if(pivot>=nums[left] && pivot <= nums[right]){
                             if(target <= pivot){
                                       return searchSolver(nums, target, left, middle);
                             }
                             else return searchSolver(nums, target, middle+1, right);                     
        }
        else if(pivot >= nums[left] && pivot >= nums[right]){
             if(target <= pivot && target >= nums[left]){
                       return searchSolver(nums, target, left, middle);
             }
             else return searchSolver(nums, target, middle+1, right);
        }
        else if(pivot <= nums[left] && pivot <= nums[right]){
             if(target <= nums[right] && target >= pivot){
                       return searchSolver(nums, target, middle+1, right);
             }
             else return searchSolver(nums, target, left, middle);
             
        }
    }
};

int main()
{
    vector<int> in;
    in.push_back(5);
    in.push_back(1);
    in.push_back(3);
    /*in.push_back(7);
    in.push_back(0);
    in.push_back(1);
    in.push_back(2);*/
    Solution *slt = new Solution();
    cout<<slt->search(in, 1);
    getchar();
    return 0;
}
