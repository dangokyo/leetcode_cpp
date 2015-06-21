#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int i, sum=0,left, right;
        int length = 0, start = 0;
        int MAX = 83647;
        int ans = MAX;
        int diff = 0;
        
		std::sort(num.begin(), num.end());
        length = num.size();
        
        for(start=0; start< length - 2; start++)
        {
                     left = start + 1;
                     right = length - 1;
                     while(left < right)
                     {
                                sum =  num[start] + num[left] + num[right];
                                diff = sum - target;
                                if(diff < 0)
                                {
                                        left++;
                                }
                                else if(diff > 0)
                                {
                                     right--;
                                }
                                else if(diff == 0)
                                {
                                     return target;
                                }
                                
                                if(abs(diff) < abs(target - ans))
                                {
                                             ans = sum;
                                }
                     }
                     
        }
        
        return ans;
    }
};

int main()
{
    //[-3,-2,-5,3,-4]
    vector<int> in;
    in.push_back(-3);
    in.push_back(-2);
    in.push_back(-5);
    in.push_back(3);
    in.push_back(-4);
    Solution *slt = new Solution();
    cout<<slt->threeSumClosest(in, -1)<<endl;
    
    char x;
    cin>>x;
    return 0;
}
