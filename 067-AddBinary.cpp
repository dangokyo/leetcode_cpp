#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
           string s1, s2, s, ans;
           int l1 , l2, i, carry;
           int t1, t2, sum;
           char ch;
           s1 = string(a.rbegin(), a.rend());
           s2 = string(b.rbegin(), b.rend());
           l1 = s1.size();
           l2 = s2.size();
           carry = 0;
           for(i=0; i<l1 || i<l2; i++)
           {
                    if(i < l1)
                    {
                         t1 = s1[i] - '0';
                    }
                    else t1 = 0;
                    if(i < l2)
                    {
                         t2 = s2[i] - '0';
                    }
                    else t2 = 0;
                    sum = (t1 + t2 + carry) % 2;
                    carry = (t1 + t2 + carry) / 2;
                    ch = sum + '0';
                    s = s + ch;
           }
           if(carry==1)
           {
                       s = s + '1';
           }
           ans = string(s.rbegin(), s.rend());
           return ans;
    }
};

int main()
{
    string in1, in2;
    in1 = "";
    in2 = "1011";
    Solution *slt = new Solution();
    cout<<slt->addBinary(in1, in2)<<endl;
    cin>>in1;
    
    return 0;
}
