#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
                vector<int> ans;
                ans.push_back(0);
                if(n==0)
                {
                        return ans;
                }
                int i, j, t = 1;
                int length;
                for(i=0; i<n; i++)
                {
                         length = ans.size();
                         for(j=length-1; j>=0; j--)
                         {
                                          ans.push_back(ans[j]);
                         }
                         for(j=t; j<t*2; j++)
                         {
                                  ans[j] += t;
                         }
                         t *=2;
                }
                return ans;
    }
};

int main()
{
    int in = 3;
    Solution *slt = new Solution();
    vector<int> result;
    result = slt->grayCode(in);
    for(int i=0; i<result.size(); i++)
    {
            cout<<result[i]<<endl;
    }
    cin>>in;
    return 0;
}
