#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
                int length = nums.size();
                vector<int> ans;
                if(length <=1 ) return nums;
                else if(length == 2){
                     if(nums[0] == nums[1]){
                                ans.push_back(nums[0]);
                                return ans;
                     }     
                     else return nums;
                }
                
                int x1, x2;
                int c1=0, c2=0;
                int count1 = 0, count2 = 0;
                int i;
                x1 = nums[0];
                c1 = 1;
                for(i=1; i<length; i++)
                {
                           if(nums[i]==x1){
                                           c1++;
                           }
                           else{
                                x2 = nums[i];
                                c2 = 1;  
                                i++; 
                                break;  
                           }       
                }
                //cout<<c1<<' '<<c2<<endl;
                for(; i<length; i++)
                {
                      if(c1 == 0){
                            if(nums[i] != x2){
                                       x1 = nums[i];
                                       c1 = 1;
                            }
                            else c2++;
                      }
                      else if(c2 == 0){
                           if(nums[i] != x1){
                                      x2 =  nums[i];
                                      c2 = 1;
                           }
                           else c1++;
                      }
                      else{
                           if(nums[i] != x1 && nums[i] != x2){
                                      c1--;
                                      c2--;
                           }
                           else if(nums[i] == x1){
                                c1++;
                           }
                           else if(nums[i] == x2){
                                c2++;
                           }
                      }
                      //cout<<x1<<':'<<c1<<endl;
                      //cout<<x2<<':'<<c2<<endl<<endl;
                }
                //cout<<x1<<' '<<x2<<endl;
                for(i=0; i<length; i++){
                         if(x1 == nums[i]) count1++;
                         if(x2 == nums[i]) count2++;
                }
                if(count1 > length/3) ans.push_back(x1);
                if(count2 > length/3 && x2 != x1) ans.push_back(x2);
                return ans;
    }   
};

int main()
{
    Solution *slt = new Solution();
    vector<int> in;
    in.push_back(1);
    in.push_back(1);
    in.push_back(1);
    in.push_back(0);
    in.push_back(0);
    in.push_back(2);
    in.push_back(2);
    in.push_back(2);
    /*in.push_back(2);
    in.push_back(4);
    in.push_back(4);*/
    vector<int> result = slt->majorityElement(in);
    for(int i=0; i<result.size(); i++)
            cout<<result[i]<<endl;
    getchar();
    return 0;
}
