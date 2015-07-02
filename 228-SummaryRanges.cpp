#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int length = nums.size();
        int i=0;
        int BeginValue, EndValue;
        vector<string> ans;
        if(length == 0) return ans;
        BeginValue = nums[0];
        EndValue = nums[0];
        for(i=1; i<length; i++)
        {
               if(nums[i] == EndValue + 1){
                          EndValue++;
               }
               else{
                    if(BeginValue == EndValue){
                                  string t;
                                  t = t + ConvertInteger(EndValue);   
                                  ans.push_back(t);           
                    }
                    else {
                         string t;
                         t = t + ConvertInteger(BeginValue);
                         t = t + "->";
                         t = t + ConvertInteger(EndValue);   
                         ans.push_back(t);       
                    }
                    
                    BeginValue = nums[i];
                    EndValue = nums[i];
               }  
        }
        if(BeginValue == EndValue){
                      string t;
                      t = t + ConvertInteger(EndValue);   
                      ans.push_back(t);           
        }
        else {
             string t;
             t = t + ConvertInteger(BeginValue);
             t = t + "->";
             t = t + ConvertInteger(EndValue);   
             ans.push_back(t);       
        }
        return ans;
    }
    
    string ConvertInteger(int num)
    {
           string ans;
           if(num == INT_MIN) return "-2147483648";
           int n = abs(num);
           int t;
           if(num==0) return "0";
           while(n>0){
                        t = n%10;
                        ans = (char)('0'+t) + ans;
                        n = n/10;  
           }
           if(num >= 0) return ans;
           else return '-'+ans;
    }
};
int main()
{
    vector<int> in;
    in.push_back(-2147483648);
    in.push_back(-2147483647);
    in.push_back(-1);
    in.push_back(0);
    in.push_back(1);
    in.push_back(2);
    in.push_back(4);
    in.push_back(5);
    in.push_back(7);
    in.push_back(14);
    in.push_back(15);
    in.push_back(16);
    Solution *slt = new Solution();
    vector<string> result = slt->summaryRanges(in);
    for(int i=0; i<result.size();i++) cout<<result[i]<<endl;
    
    getchar();
    return 0;
}
