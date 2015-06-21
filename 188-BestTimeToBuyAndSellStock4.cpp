#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int length = prices.size();
        int i, j;
        int ans=0;
        if(length<=1) return 0;
        if(k >= length/2)
        {
             for(i=1; i<length; i++)
             {
                      ans += max(0, prices[i]-prices[i-1]);         
             }
             return ans;
        }
        
        vector<int> v(length, 0);
        vector<vector<int> > dp1(k+1, v);  // dp1[k][i] optimal solution to sell at ith day with at most k transactions
        vector<vector<int> > dp2(k+1, v);  // dp2[k][i] optimal solution from 0 to ith day with at most k transactions
        int diff = 0;
        
        int t;
       
        for(j=1; j<=k; j++)
        { 
                 for(i=1; i<length; i++)
                 {
                      diff = prices[i] - prices[i-1];
                      dp1[j][i] = max(dp2[j-1][i-1]+max(diff, 0), dp1[j][i-1]+diff);
                      dp2[j][i] = max(dp1[j][i], dp2[j][i-1]);             
                 } 
                 /*cout<<j<<"th transaction"<<endl;
                 for(t=0; t<length; t++) cout<<dp1[j][t]<<' ';
                 cout<<endl;      
                 for(t=0; t<length; t++) cout<<dp2[j][t]<<' ';
                 cout<<endl<<endl;  */
        }
        return dp2[k][length-1];
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int> in;
    /*in.push_back(1);
    in.push_back(5);
    in.push_back(4);
    in.push_back(6);
    in.push_back(5);
    in.push_back(8);
    in.push_back(3);
    in.push_back(9);*/
    in.push_back(3);
    in.push_back(2);
    in.push_back(6);
    in.push_back(5);
    in.push_back(0);
    in.push_back(3);
    cout<<slt->maxProfit(2, in)<<endl;
    getchar();
    return 0;
}
