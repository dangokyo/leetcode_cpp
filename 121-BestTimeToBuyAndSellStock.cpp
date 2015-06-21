#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int length = prices.size();
        int i;
        int min = INT_MAX, tmp_high = 0;
        int ans = 0;
        for(i=0; i<length; i++)
        {
                 if(prices[i] < min)
                 {
                              min = prices[i];
                              tmp_high = prices[i];
                 }
                 else if(prices[i] >= min)
                 {
                      tmp_high = prices[i];
                 }
                 if(tmp_high - min > ans)
                 {
                             ans = tmp_high - min;
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
    cout<<slt->maxProfit(in);
    int i;
    cin>>i;
    return 0;
}
