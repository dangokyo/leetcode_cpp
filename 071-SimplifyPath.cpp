#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> myStack;
        int i = 0;
        int length = path.size();
        string tmp = "";
        string ans = "";
        for(i=0; i< length; i++)
        {
                 tmp.clear();
                 while(path[i]=='/' && i<length) {
                                     i++;
                 }
                 while(path[i]!='/' && i<length){
                                     tmp += path[i];
                                     i++;
                 }
                 //cout<<"procesing:"<<i<<' '<<tmp<<endl;
                 if(tmp =="..")
                 {
                        if(!myStack.empty())
                        {
                                             myStack.pop();
                        }
                        else continue;
                 }
                 else if(tmp== ".")
                 {
                      continue;
                 }
                 else{
                      if(tmp.size()>0) myStack.push(tmp);
                 }
        }
        
        if(myStack.empty()) ans = "/";
        while(!myStack.empty())
        {
                ans = "/"+myStack.top()+ans;
                myStack.pop();
        }
        /*if(ans.size()>1)
        {
                        ans = ans.substr(0, ans.size()-1);
        }*/     
        //cout<<ans.size()<<endl;
        return ans;
    }
};
int main()
{
    string in = "/a/./b/../../c/";
    //string in = "/home/../../..";
    //string in = "/";
    //string in = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
    Solution *slt = new Solution();
    cout<<slt->simplifyPath(in)<<endl;
    cin>>in;
    return 0;
}
