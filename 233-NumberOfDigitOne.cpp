#include<iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        int vec[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        int t = n;
        int highpart, lowpart;
        int digit, value;
        while(t > 0)
        {
                if(t < 10){
                     if(t>=1) return ans + 1;
                     else return ans;
                }
                
                digit = 1;
                value = 0;
                highpart = getHighPart(t, digit, value);
                
                lowpart = t - highpart;
                cout<<highpart<<' '<<lowpart<<' '<<digit<<' '<<value<<endl;
                
                ans = ans + calc(digit);
                if(value == 1){
                         ans = ans + (lowpart + 1);         
                }
                else {
                     ans = ans + vec[digit] + (value - 1) * calc(digit);
                }
                
                        
                t = lowpart;
        }
        
        return ans;
    }
    
    int getHighPart(int num, int& digit, int& highestDigit)
    {
        if(num < 10) return num;
        int t = 10;
        while(num / t >= 10)
        {
                  digit++;
                  t = t *10;
        }
        highestDigit = num/t;
        return (num/t)*t;     
        
    }
    
    int calc(int i){
        if(i==0) return 0;
        int t=i;
        int ans = 1;
        while(t > 1) 
        {
                ans = ans * 10;
                t--;
        }
        ans = i * ans;
        return ans;
    }
};

int main()
{
    Solution *slt = new Solution();
    cout<<slt->countDigitOne(100)<<endl;
    getchar();
    return 0;
}
