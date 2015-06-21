#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
                   vector<string> ans;
                   queue<string> ans_queue;
                   string top, tmp;
                   int val, i, j;
                   int length = digits.size();
                   if(length==0)
                   {
                       ans.push_back(tmp);
                       return ans;
                   }
                   
                   string pad[8][4]={{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
                   for(i=0; i< length; i++)
                   {
                            val = (int)(digits.at(i)) -50;
                            if(i==0)
                            {
                                    for(j=0; j<4; j++)
                                    {
                                             if(pad[val][j]!="\0")
                                             {
                                                                  ans_queue.push(pad[val][j]);
                                             }
                                    }
                            }
                            else if(i!=0)
                            {
                                 top = ans_queue.front();
                                 while(top.size()==i)
                                 {
                                                     ans_queue.pop();
                                                     for(j=0; j<4;j++)
                                                     {
                                                              if(pad[val][j]!="\0")
                                                              {
                                                                                   tmp = top;
                                                                                   tmp = tmp + pad[val][j];
                                                                                   ans_queue.push(tmp);
                                                              }
                                                     }
                                                     top = ans_queue.front();
                                 }
                            }
                                 
                                 
                            //cout<<val<<endl;
                   }
                   while (!ans_queue.empty())  
                   {  
                      ans.push_back(ans_queue.front());  
                      ans_queue.pop();  
                   } 
                   
                   return ans;
        
    }

};

int main()
{
    string in = "23";
    Solution *slt = new Solution();
    vector<string> result;
    
    result = slt->letterCombinations(in);
    
    char x;
    cin>>x;
    return 0;
}
