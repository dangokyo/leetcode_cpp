#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1;
        if(dividend == 0 ) sign = 0;
        if(dividend < 0) sign = sign * (-1);
        if(divisor < 0) sign = sign * (-1);
        unsigned int ans = 0;
        
        unsigned int div1 = abs(dividend);
        unsigned int div2 = abs(divisor);
        
        unsigned int tmp1 = div1;
        unsigned int tmp2 = div2;
        unsigned int tmp, val=1;
        unsigned int digit = 0;
        if(tmp1 == tmp2) return 1*sign;
        
        //cout<<"Sign:"<<sign<<' '<<tmp1<<' '<<tmp2<<endl;
        while(tmp1 >= tmp2 && tmp2!=0)
        {
                   tmp = tmp2<<1;
                   //cout<<ans;
                   if(tmp<tmp1)
                   {
                               digit++;
                               tmp2 = tmp;
                               //cout<<tmp2<<endl;
                               continue;
                   }
                   else if(tmp>tmp1)
                   {
                        while(digit>0)
                        {
                                       val = val * 2;
                                       digit--;
                        }
                        ans = ans + val;
                        val = 1;
                        tmp1 = tmp1 - tmp2;
                        tmp2 = div2;
                   }
                   else if(tmp == tmp1)
                   {    
                        digit++;
                        while(digit>0)
                        {
                                       val = val * 2;
                                       digit--;
                        }
                        //cout<<"test case3:"<<ans<<endl;
                        ans = ans + val;
                        //cout<<"test case3:"<<ans<<endl;
                        break;
                   }
                        
        }
        //cout<<"Final check:"<<ans<<' '<<sign<<' '<<(int)ans*sign<<' '<<ans*sign<<endl;
        if(ans > 2147483647 && sign>0) 
        {
                    return 2147483647;
        }
        else
             return ans*sign;
    }
};

int main()
{
    Solution *slt = new Solution();
    int result;
    //result = slt->divide(-2147483648,-1);
    //result = slt->divide(-2147483648,-2147483648);
    //result = slt->divide(-1,1);
    result = slt->divide(1,2);
    
    cout<<result<<endl;
    int x;
    cin>>x;
    
    return 0;
}
