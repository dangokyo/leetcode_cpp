#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int left, right, sum, tmp;
    	int i;
    	int max = INT_MIN; 
    	left = 0;
    	right = 0;
    	sum = max;
    	for(i=0; i<n; i++)
    	{
    		if(A[i]<=0)
    		{
    			if(A[i] > sum)
    				sum = A[i];
    		}
    		else if(A[i] > 0)
    		{
    			break;
    		}
    	}
    	for(; i<n; i++)
    	{
    		if(A[i] <= 0) continue;
    		tmp = A[i];
    		if(tmp > sum)
    		{
    			sum = tmp;
    		}
    		
    		
    		right = i + 1;
    		if(right >= n) break;
    		
    		while(right < n)
    		{
    			tmp = tmp + A[right];
				if(tmp < 0)
				{
    				//cout<<"branch1:"<<i<<' '<<right<<' '<<tmp<<endl;
					i = right ;
					break;
				} 
				else if(tmp >= 0)
				{
    				//cout<<"branch2:"<<i<<' '<<right<<' '<<tmp<<endl;
					right++;
					if(tmp > sum)
					{
						sum =tmp;
					}
					else if(tmp < sum)
					{
						continue;
					}
				}
    		}
    	}
        return sum;
    }
};

int main()
{
	//int array[2] = {-1, -2};
	//int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
	//int array[1] = {1};
	int array[7] ={3,-2,-3,-3,1,3,0};
	Solution *slt = new Solution();
	cout<<slt->maxSubArray(array, sizeof(array)/4);
	return 0;
} 
