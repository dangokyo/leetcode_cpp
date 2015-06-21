#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
    	if(n<=2) return 0;
    	
    	int i, k;
    	vector<int> result;
    	vector<bool> isVisited(n-3, false);
    	for(i=2; i<n; i++ )
    	{
    		if(!isVisited[i-2])
    		{
    			result.push_back(i);
    			for(k = i; k<n; k +=i)
    			{
    				isVisited[k-2] = true;
    			}
    		}
    		else continue;
    	}
    	
    	return result.size();
    }
};

int main()
{
	Solution *slt = new Solution();
	int in = 2;
	cout<<slt->countPrimes(in)<<endl;
	return 0;
}
