#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
         int length = s1.size();
         if(length==0) return false;
         else if(length==1) return (s1==s2);
         else if(length==2) return (s1[0] == s2[0] && s1[1]==s2[1]) || (s1[0]==s2[1] && s1[1]==s2[0]);
         int i;
         bool f1, f2;
         string s11, s12, s21, s22;
         
         
         map<char, int> myMap;
         for(i=0; i<length;i++)
         {
         	if(myMap.count(s1[i]) == 0)
         	{
         		myMap[s1[i]] = 1;
         	}
         	else myMap[s1[i]]++;
         }
         
         for(i=0; i<length; i++)
         {
         	if(myMap.count(s2[i]) > 0)
         	{
         		if(myMap[s2[i]] > 0) myMap[s2[i]]--;
         		else return false;
         	}
         	else return false;
         }
         //cout<<"breaking:"<<s1<<' '<<s2<<endl;
         for(i=1; i<length; i++)
         {
                   	//cout<<"breaking:"<<s1<<' '<<s2<<endl;
                   	s11 = s1.substr(0, i);
                   	s12 = s1.substr(i, length-i);
                   
                   	s21 = s2.substr(0, i);
                   	s22 = s2.substr(i, length-i);
                   	//cout<<1<<':'<<s11<<' '<<s21<<' '<<s12<<' '<<s22<<endl;
                	//cout<<isScramble(s11, s21)<<endl<<isScramble(s12, s22)<<endl;
                   	if(isScramble(s11, s21) && isScramble(s12, s22) ) return true;
                   
                   	s21 = s2.substr(0, length-i);
                   	s22 = s2.substr(length-i, i);
                   	//cout<<2<<':'<<s11<<' '<<s22<<' '<<s12<<' '<<s21<<endl;
                   	//cout<<isScramble(s11, s22)<<endl<<isScramble(s12, s21)<<endl;
                   	if(isScramble(s11, s22) && isScramble(s12, s21) ) return true;
         }
         
         return false;
        
    }
};

int main()
{
    string s1, s2;
    s1 = "aabb";
    s2 = "abab";
    Solution *slt = new Solution();
    cout<<slt->isScramble(s1, s2)<<endl;
    return 0;
}
