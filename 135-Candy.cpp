#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int length = ratings.size();
        if(length<1) return 0;
        
        vector<int> v(length, 1);
        int i;
        for(i=1; i<length; i++)
        {
        	if(ratings[i] > ratings[i-1]) v[i] = v[i-1]+1; 
        }
        
        for(i=length-2; i>=0 ; i--)
        {
        	if(ratings[i] > ratings[i+1] && v[i] <=v[i+1]) v[i] = v[i+1]+1;
        }
        
        for(i=0; i<length; i++) 
		{
			//cout<<i<<":"<<v[i]<<endl;
			ans+=v[i];
		}
		return ans;
    }
};

int main()
{
	vector<int> in;
	Solution *slt = new Solution();
	in.push_back(5);
	in.push_back(1);
	in.push_back(2);
	in.push_back(4);
	in.push_back(3);
	in.push_back(2);
	in.push_back(1);
	in.push_back(0);
	
	cout<<slt->candy(in)<<endl;
	return 0;
}
