#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
         int t = n;
         if(n <= 0) return false;
         while(t > 1){
                 if(t % 2 ==1) return false;
                 else t = t/2;        
         }
         return true;
    }
};

int main()
{
    Solution *slt = new Solution();
    cout<<slt->isPowerOfTwo(13)<<endl;
    getchar();
    return 0;
}
