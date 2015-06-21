#include<iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        int pos1 = 0, pos2 = 0;
        int len1 = version1.size();
        int len2 = version2.size();
        while(true)
        {
                   while(version1[pos1]=='.' && pos1<len1) pos1++;
                   while(version2[pos2]=='.' && pos2<len2) pos2++;
                   
                   if(pos1==len1 && pos2<len2)
                   {
                                 v1 = 0;
                                 v2 = getMajor(version2, pos2);
                   }
                   else if(pos1<len1 && pos2==len2)
                   {
                        v1 = getMajor(version1, pos1);
                        v2 = 0;
                   }
                   else if(pos1==len1 && pos2 == len2)
                   {
                        return 0;
                   }
                   else
                   {
                       v1 = getMajor(version1, pos1);
                       v2 = getMajor(version2, pos2);
                   }
                   if(v1 > v2) 
                   {
                         return 1;
                   }
                   else if(v2 > v1)
                   {
                        return -1;
                   }
                   else if(v1 == v2)
                   {
                        continue;     
                   }
        }
    }
    
    int getMajor(string version, int &position)
    {
        int length = version.size();
        int i;
        int ans= 0;
        for(i=position; i<length; i++)
        {
                  if(version[i]<='9' && version[i]>='0')
                  {
                                     ans = ans*10+(int)(version[i]-'0');
                  }
                  else break;        
        }
        position = i;
        return ans;
    }
};

int main()
{
    string v1 = "1.2";
    string v2 = "1.1";
    Solution *slt = new Solution();
    cout<<slt->compareVersion(v1, v2)<<endl;
    cin>>v1;
    return 0;
}
