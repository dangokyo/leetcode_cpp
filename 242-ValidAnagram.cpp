#include<iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
         int key1 = hash(s);
         int key2 = hash(t);
         if(key1 == key2) return true;
         else return false;
        
    }
    
    int hash(string str){
        int ans = 0;
        int length = str.size();
        int a[26] = {0};
        for(int i=0; i<length; i++){
                a[str[i]-'a']++;
        }
        for(int i=0; i<26; i++){
                ans = ans*17 + a[i];
        }
        return ans;    
    }
};

int main()
{
    string s= "car";//"anagram";
    string t= "rat";//"nagaram";
    Solution *slt = new Solution();
    cout<<slt->isAnagram(s, t)<<endl;
    getchar();
    return 0;
}
