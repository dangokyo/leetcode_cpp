#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
                   if(n==0)
                   {
                           vector<string> ans;
                           return ans;
                   }
                   else if(n==1)
                   {
                        vector<string> ans;
                        ans.push_back("()");
                        return ans;
                   }
                   else if(n>1)
                   {
                        vector<string> ans;
                        vector<string> tmp;
                        char buffer[1000];
                        string buffer1;
                        string buffer2;
                        tmp = generateParenthesis(n-1);
                        int length,i;
                        length = tmp.size();
                        for(i=0; i< length; i++)
                        {
                                 string t = tmp[i];
                                 //cout<<"target:"<<t<<endl;
                                 int j,k, l= t.size();
                                 for(k=0; k<l; k++)
                                 {
                                          buffer1 = t.substr(0,k);
                                          buffer2 = t.substr(k,l);
                                          //cout<<"buffer1:"<<buffer1<<" buffer2:"<<buffer2<<endl;
                                          strcpy(buffer,"");
                                          strcat(buffer,buffer1.c_str());
                                          strcat(buffer,"()");
                                          strcat(buffer, buffer2.c_str());
                                          //cout<<"test"<<buffer<<endl;
                                          for(j=0; j<ans.size(); j++)
                                          {
                                                  if(!strcmp(ans[j].c_str(), buffer))
                                                  {
                                                                            //cout<<"Found equal:"<<j<<" "<<ans[j]<<" "<<buffer<<endl;
                                                                            break;
                                                  }
                                          }
                                          if(j == ans.size())
                                          {
                                               ans.push_back(buffer);
                                          }
                                 }
                        }
                        return ans;
                   }
        
    }
};

int main()
{
    int num=3, i;
    vector<string> result;
    
    Solution *slt = new Solution();
    result = slt->generateParenthesis(num);
    for(i=0; i<result.size(); i++)
    {
             cout<<result[i]<<endl;
    }
    
    cin>>i;
    return 0;
}
