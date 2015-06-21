#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if(x==0) return 0;
        double tmp,root;
        tmp = 0;
        root = (double)x/2;
        cout<<0<<' '<<root<<endl;
        while(tmp!=root)
        {
            tmp = root;
            root = (root + x/root) /2;
            cout<<root<<endl;
        }
        return (int)root;
        
    }
};
int main()
{    
    Solution *slt = new Solution();
    int x;
    cout<<slt->sqrt(1)<<endl;
    cin>>x;
    
    return 0;
}
