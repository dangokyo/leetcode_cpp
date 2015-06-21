#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int length =s.size();
        int i, t;
        string tmp;
        for(i=length-1; i>=0; i--)
        {
                        if(s[i]==' ') continue;
                        else break;
        }
        string str = s.substr(0, i+1);
        if(str.size()==0)  
        {
                           s = "";
                           return;
        }
        s.clear();
        length = str.size();
        for(i=0; i<length; i++)
        {
                 if(str[i]==' ') continue;
                 t = i;
                 while(str[i+1] != ' ' && str[i+1]!='\0') i++;
                 tmp = str.substr(t, i - t + 1);
                 s = tmp + s;
                 if(str[i+1] == ' ') s =" "+s;
        }
    }
};

int main()
{
    //string in = "the sky is blue";
    string in = " ";
    //string in = "1 ";
    Solution *slt = new Solution();
    cout<<in<<endl;
    slt->reverseWords(in);
    cout<<in<<":"<<in.size()<<endl;
    cin>>in;
    return 0;
}
