#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int length = prices.size();
        int left, right;
        left = 0;
        right = 0;
        while(left < length - 1)
        {
                   if(prices[left + 1] > prices[left])
                   {
                                  right = left + 1;
                                  while(prices[right] > prices[right-1] && right <length)
                                  {
                                            right++;
                                  }
                                  ans += prices[right - 1] - prices[left];
                                  left = right;          
                   }
                   else
                   {
                       left++;
                   }
        }
        return ans;
        
    }
};


int main()
{
    Solution *slt = new Solution();
    vector<int> in;
    in.push_back(8);
    in.push_back(1);
    in.push_back(3);
    in.push_back(4);
    in.push_back(4);
    in.push_back(7);
    in.push_back(2);
    in.push_back(7);
    cout<<slt->maxProfit(in);
    int i;
    cin>>i;
    return 0;
}
