#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> smap;
        map<char, char> inv_smap;
        int length = s.size();
        int i;
        char c1, c2, tc;
        for(i=0; i<length; i++)
        {
                 c1 = s[i];
                 c2 = t[i];
                 
                 if(smap.count(c1)==0)
                 {
                                      if(inv_smap.count(c2)==0)
                                      {
                                                               smap[c1] = c2;
                                                               inv_smap[c2] = c1;
                                      }
                                      else if(inv_smap.count(c2)>0)
                                      {
                                           tc = inv_smap[c2];
                                           if(tc != c1) return false;
                                           else continue;
                                      }                    
                 }
                 else if(smap.count(c1) > 0)
                 {
                      tc = smap[c1];
                      if(tc!= c2) return false;
                      else continue;
                 }
        }
        return true;
    }
};

int main()
{
    Solution *slt = new Solution();
    string str1, str2;
    str1 = "foo";
    str2 = "bar";
    cout<<slt->isIsomorphic(str1, str2)<<endl;
    
    cin>>str1;
    return 0;
}
