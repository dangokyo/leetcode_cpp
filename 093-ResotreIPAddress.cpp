#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string sol;
        sol ="";
        IPResolver(0, 0, s, sol, ans);
        return ans;
    }
    
    bool IPResolver(int start, int level, string s, string &sol, vector<string> &ans)
    {
        if(start == s.size() && level == 4)
        {
                 sol = sol.substr(1, sol.size()-1);
                 ans.push_back(sol);
                 return true;
        }
        else if(start == s.size() && level < 4)
        {
             return false;
        }
        else if(start != s.size() && level == 4)
        {
             return false;
        }
        else if(start < s.size() && level <4)
        {
             //cout<<level<<" "<<sol<<endl;
             string tmp = sol;
             string part;
             int num;
             bool flag = false;
             int i;
             for(i=1; i<=3 && start+i<= s.size(); i++)
             {
                      part = s.substr(start, i);
                      //cout<<start<<" "<<level<<" "<<part<<endl;
                      if(part[0]=='0')
                      {
                                    if(part.size()==1){
                                                       num=0;
                                    }
                                    else if(part.size() > 1)
                                    {
                                         return false;
                                    }
                      }
                      else
                      {
                          num = toInteger(part);
                      }
                      if(num <= 255 && num >=0)
                      {
                             sol += ".";
                             sol += part;
                             flag = IPResolver(start+i, level+1, s, sol, ans);
                      }
                      else
                      {
                          return false;
                      }
                      
                      sol = tmp;
             }
             return false;
        }
    }
                      
    
    int toInteger(string s)
    {
        int length = s.size();
        int i;
        int ans = 0;
        for(i=0; i<length; i++)
        {
                     ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
};

int main()
{
    string in = "25525511135";
    //string in = "11111";
    //string in = "010010";
    Solution *slt = new Solution();
    vector<string> result;
    int i;
    result = slt->restoreIpAddresses(in);
    for(i=0; i< result.size(); i++)
    {
             cout<<result[i]<<endl;
    }
    cin>>i;
    return 0;
}
