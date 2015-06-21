#include<iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i;
        int ai = m - 1;
        int bi = n - 1;
        if(m == 0)
        {
        	for(i=0; i<n; i++)
        	{
        		A[i] = B[i];
        	}
        }
        
		if(n == 0)
			return;
        
        
        for(i = m + n - 1 ; i>=0 && ai>=0 && bi>=0; i--)
        {
        	if(A[ai] >= B[bi])
        	{
        		A[i] = A[ai];
        		ai--;
        	}
        	else 
        	{
        		A[i] = B[bi];
        		bi--;
        	}
        }
        
        if(ai>=0)
        {
        	for(; i>=0; i--, ai--)
        	{
        		A[i] = A[ai];
        	}
        }
        
        if(bi>=0)
        {
        	for(; i>=0; i--, bi--)
        	{
        		A[i] = B[bi];
        	}
        }
    }
};


int main()
{
	//int a[13] = {1, 1, 3, 5, 5, 9, 13};
	//int b[6] = {2, 4, 4, 8, 8, 12};
	int a[2] = {2};
	int b[1] = {1};
	Solution *slt = new Solution();
	slt->merge(a, 1, b, 1);
	int i;
	for(i=0; i<2; i++)
		cout<<a[i]<<' ';
	return 0;
}
