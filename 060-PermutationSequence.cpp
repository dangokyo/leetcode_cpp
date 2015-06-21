#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
           vector<int> num;
           vector<int> fac;
           string ans;
           if(n == 0) return ans;
           if(n == 1) return "1";
           int i, j, target;
           int index, d;
           target = k - 1;
           for(i=1; i<=n; i++)
                   num.push_back(i);
           fac.push_back(1);
           for(i=2; i<=n; i++)
                    fac.push_back(i * fac[i-2]);
           
           if(k == 1)
           {
                for(i=0; i< n; i++)
                {
                         ans = ans + int2string(num[i]);
                }
                return ans;
           }
           
           for(i = n-2; i>=0; i--)        
           {
                 index = target / fac[i];
                 target = target - index * fac[i];
                 d = num[index];
                 ans = ans + int2string(d);
                 num.erase(num.begin() + index);
           }
           ans = ans + int2string(num[0]);
           return ans;
    }
    
    string int2string(int d)
    {
           string res, str;
           char ch;
           int i, digit = 0, t;
           if(d == 0) return "0";
           
           t = d;
           while(t > 0)
           {
                   t = t/10;
                   digit++;
           }
           for(i=0; i<digit; i++)
           {
                    t = d % 10;
                    ch =(char)(t + '0');
                    str = str + ch;
                    d = d/10;
           }
           return str;
    }
};

int main()
{
    int in1, in2;
    in1 = 3;
    in2 = 3;
    Solution *slt = new Solution();
    cout<<slt->getPermutation(in1, in2)<<endl;
    cin>>in1;
    return 0;
}
