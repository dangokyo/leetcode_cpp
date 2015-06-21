#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        string tmp;
        map<int, bool> mymap;
        int length = s.size();
        if(length<10) return ans;
        int i=0, id;
        for(i=0; i<=length-10; i++)
        {
                tmp = s.substr(i, 10);
                id = str2int(tmp);
                if(mymap.count(id)>0)
                {
                                      if(!mymap[id])
                                      {
                                          ans.push_back(tmp);
                                          mymap[id] = true;           
                                      }
                                      else
                                      {
                                          continue;
                                      }
                }
                else
                {
                    mymap[id] = false;
                }
        } 
        return ans;
    }
    
    int str2int(string s)
    {
        int i, length;
        int ans = 0, tmp;
        length = s.size();
        for(i=0; i<length; i++)
        {
             if(s[i]=='A'){
                 tmp = 0;          
             }
             else if(s[i]=='C'){
                 tmp = 1; 
             }
             else if(s[i]=='G'){
                 tmp = 2; 
             }
             else if(s[i]=='T'){
                 tmp = 3; 
             }
             ans = ans * 4 + tmp;
        }
        return ans;
    }
};


int main()
{
    Solution *slt = new Solution();
    //string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s = "AAAAAAAAAAA";
    int i;
    vector<string> result = slt->findRepeatedDnaSequences(s);
    for(i=0; i<result.size(); i++)
    {
             cout<<result[i]<<endl;
    } 
    cin>>i; 
    return 0;
}
