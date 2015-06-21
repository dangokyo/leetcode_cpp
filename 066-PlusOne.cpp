#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans, t;
        int i, carry = 0, length, d;
        for(i=digits.size()-1; i>=0; i--)
        {
                               t.push_back(digits[i]);
        }
        length = t.size();
        for(i=0; i< length; i++)
        {
                 d = t[i];
                 if(i==0)
                 {
                         t[i] = (d + 1) % 10;
                         carry = (d + 1) / 10;
                 }
                 else if(i>0)
                 {
                      t[i] = (d + carry) % 10;
                      carry = (d + carry) / 10;
                 }
                 //cout<<i<<":"<<t[i]<<" "<<carry<<endl;
        }
        if(carry > 0)
                 t.push_back(carry);
                 
        for(i=t.size()-1; i>=0; i--)
        {
                               ans.push_back(t[i]);
        }
        return ans; 
    }
};

int main()
{
    vector<int> in, result;
    Solution *slt = new Solution();
    int i;
    in.push_back(9);
    in.push_back(9);
    in.push_back(9);
    in.push_back(9);
    result = slt->plusOne(in);
    for(i=0; i<result.size(); i++)
             cout<<result[i]<<endl;
    cout<<endl;
    cin>>i;
    return 0;
}
