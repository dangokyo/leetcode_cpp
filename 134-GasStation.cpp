#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length = gas.size();
        vector<int> load(length * 2, 0);
        int i, j;
        for(i=0; i<length; i++)
        {
                 load[i] = gas[i]-cost[i];
                 load[i+length] = load[i];
        }
        int ans;
        for(i=0; i<length; i++)
        {
                 if(load[i] < 0) continue;
                 
                 ans = load[i];
                 for(j=1; j<length; j++)
                 {
                        ans += load[i+j];
                        if(ans < 0) break;                    
                 }
                 if(j==length)
                 {
                              return i;
                 }
                 else
                 {
                     i = i + j;
                 }
        }
        return -1;
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int> gas;
    vector<int> cost;
    gas.push_back(3);
    gas.push_back(2);
    gas.push_back(4);
    gas.push_back(1);
    gas.push_back(2);
    cost.push_back(6);
    cost.push_back(1);
    cost.push_back(3);
    cost.push_back(0);
    cost.push_back(2);
    int i;
    cout<<slt->canCompleteCircuit(gas, cost)<<endl;
    cin>>i;
    return 0;
}
