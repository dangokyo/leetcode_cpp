# include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	int bit = 0;
    	while(m!=n)
    	{
    		 m = m>>1;
    		 n = n>>1;
    		 bit++;
    	}
    	return (m<<bit);
        
    }
};

int main()
{
	Solution *slt = new Solution();
	int m = 4; 
	int n = 7;
	cout<<slt->rangeBitwiseAnd(m, n)<<endl;
	return 0;
}
