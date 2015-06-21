#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
    	int i, j, m, n;
    	int occupied[9];
    	
    	NullifyArray(occupied, 9);
    	
    	for(i=0; i<9; i++)
    	{
    		NullifyArray(occupied, 9);
    		for(j=0; j<9; j++)
    		{
    			int t = (int)(board[i][j] - '1');
    			if(t >= 0 && t <9)
    			{
    				if(occupied[t]==0)
    				{
    					occupied[t] = 1;
    				}
    				else if(occupied[t] == 1)
    				{
    					return false;
    				}
    			}
    			else continue;
    		}
    	}
    	
    	for(i=0; i<9; i++)
    	{
    		NullifyArray(occupied, 9);
    		for(j=0; j<9; j++)
    		{
    			int t = (int)(board[j][i] - '1');
    			if(t >= 0 && t <9)
    			{
    				if(occupied[t]==0)
    				{
    					occupied[t] = 1;
    				}
    				else if(occupied[t] == 1)
    				{
    					return false;
    				}
    			}
    			else continue;
    		}
    	}
    	
    	for(i=0; i<3; i++)
    	{
    		for(j=0; j<3; j++)
    		{
    			NullifyArray(occupied, 9);
    			for(m = i*3; m<i*3+3; m++)
    			{
    				for(n = j*3; n < j*3+3; n++)
    				{
    					int t = (int)(board[m][n] - '1');
    					if(t >= 0 && t <9)
    					{
    						if(occupied[t]==0)
    						{
    							occupied[t] = 1;
    						}
    						else if(occupied[t] == 1)
    						{
    							return false;
    						}
    					}
    					else continue;
    				}
    			}
    		}
    	}
    	
    	return true;
    }
    
    void NullifyArray(int Array[], int n)
    {
    	int i;
    	for(i=0; i<n; i++)
    		Array[i] = 0;
    }
};

int main()
{
	vector<char> t;
	vector<vector<char> > in;
	int i;
	for(i=0; i<9; i++)
	{
		t.push_back('.');
	}
	
	for(i=0; i<9; i++)
	{
		in.push_back(t);
	}
	in[0][1] = '8';
	in[0][2] = '7';
	in[0][3] = '6';
	in[0][4] = '5';
	in[0][5] = '4';
	in[0][6] = '3';
	in[0][7] = '2';
	in[0][8] = '1';
	in[1][0] = '2';
	in[2][0] = '3';
	in[3][0] = '4';
	in[4][0] = '5';
	in[5][0] = '6';
	in[6][0] = '7';
	in[7][0] = '8';
	in[8][0] = '9';
	Solution *slt = new Solution();
	cout<< slt->isValidSudoku(in)<<endl;
	
	return 0;
	
}
