#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int i, j;
        int length = matrix.size();
        if(length == 0) return;
        
        for(i=0; i<length - 1; i++)
        {
        	for(j=0; j < length - i -1; j++)
        	{
        		swap(matrix[i][j], matrix[length - 1 - j][length - 1 - i]);
        	}
        }
        
        for(i=0; i<length / 2; i++)
        {
        	for(j=0; j < length ; j++)
        	{
        		swap(matrix[i][j], matrix[length - 1 - i][j]);
        	}
        }
    }
    
    int swap(int &a, int &b)
    {
    	int t;
    	t = a;
    	a = b;
    	b = t;
    	return 0;
    }
};

int main()
{
	vector<int> t;
	vector<vector<int> > in;
	Solution *slt = new Solution();
	int i, j;
	
	t.push_back(1);
	t.push_back(2);
	in.push_back(t);
	t.clear();
	t.push_back(3);
	t.push_back(4);
	in.push_back(t);
	
	for(i=0; i<in.size(); i++)
	{
		for(j=0; j<in[i].size(); j++)
		{
			cout<<in[i][j]<<' ';
		}
		cout<<endl;
	}
	
	slt->rotate(in);
	
	for(i=0; i<in.size(); i++)
	{
		for(j=0; j<in[i].size(); j++)
		{
			cout<<in[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
