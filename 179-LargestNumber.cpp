#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string ans;
        int t;
        int length = num.size();
        int i, j;
        for(i=0; i<length-1; i++) 
		{
			for(j=i+1; j<length; j++)
			{
				if(!isLarger(num[i], num[j]))
				{	
					t = num[i];
					num[i] = num[j];
					num[j] = t;
				}
			}
		}
		
		for(i=0; i<length; i++)
		{
			ans = ans + int2str(num[i]);
		}
		length = ans.size();
		for(i=0; i<= length-2; i++)
		{
			if(ans[i]!='0'){
				 break;
			}
		}
		ans = ans.substr(i, length-i+1);
        return ans;
    }
    
    string int2str(int num)
    {
    	string ans;
    	if(num==0) return "0";
    	while(num != 0)
    	{
    		ans = char((num % 10) + '0') + ans;
    		num = num /10;
    	}
    	return ans;
    }
    bool isLarger(int a, int b) //a is larger than b 12 121
    {
    	int da = 0, db = 0;
    	int i;
    	string sa, sb;
    	if(a == 0) sa = "0";
    	if(b == 0) sb = "0";
    	while(a!=0)
    	{
    		sa = char((a % 10) + '0') + sa;
    		a = a/10;
    		da++;
    	}
    	while(b!=0)
    	{
    		sb = char((b % 10) + '0') + sb;
    		b = b/10;
    		db++;
    	}
    	string s1, s2;
    	s1 = sa + sb;
    	s2 = sb + sa;
    	for(i=0; i<s1.size(); i++)
    	{
    		if(s1[i]==s2[i])
    		{
    			continue;
    		}
    		else if(s1[i] < s2[i])
    		{
    			return false;
    		}
    		else if(s1[i] > s2[i])
    		{
    			return true;
    		}
    	}
    }
};

int main()
{
	vector<int> in;
	Solution *slt = new Solution();
	in.push_back(12);
	in.push_back(121);
	cout<<slt->largestNumber(in)<<endl;
	return 0;
}
