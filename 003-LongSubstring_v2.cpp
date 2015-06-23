#include<iostream>
#include<map>
using namespace std;

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left=0, right=0;
        int length = s.size();
        if(length == 0) return 0;
        else if(length == 1) return 1;
        map<char, int> mymap;
        mymap[s[0]] = 0;
        while(right<length)
        {
                           right++;
                           if(right>=length) 
                           {
                                             right--;
                                             break;
                           }
                           if(mymap.find(s[right]) == mymap.end() )
                           {
                                                   mymap[s[right]] = right;
                           }
                           else
                           {
                               int t = mymap[s[right]];
                               if(t < left)
                               {
                                    mymap[s[right]] = right;
                               }
                               else
                               {
                                   left = t+1;
                                   mymap[s[right]] = right;
                               }
                           }
                           if(right -left+1 > ans) ans = right - left + 1;
        }
        if(right -left+1 > ans) ans = right - left + 1;
        return ans;
    }
};

int main()
{
	Solution *slt = new Solution();
	string in = "abcabcbb";
	//string in = "ab";
    //string in = "msboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuu";
	//string in = "qrsvbspk";
	//string in = "xnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxz";
	cout <<slt->lengthOfLongestSubstring(in)<<endl;
	//cout<<slt<<endl;
	getchar();
    return 0;
}
