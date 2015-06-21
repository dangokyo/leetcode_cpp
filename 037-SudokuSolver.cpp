#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
    	vector<int> candidates;
    	int i, j, length;
    	candidates.clear();
    	for(i=0; i<9; i++)
    	{
    		for(j=0; j<9; j++)
    		{
    			if(board[i][j] == '.')
    				candidates.push_back(i*9 + j);
    		}
    	}
    	length = candidates.size();
    	SudokuSolver(board, candidates, 0, length);
        
    }
    
    bool SudokuSolver(vector<vector<char> > &board, vector<int> &candidates,  int index, int  length)
    {
    	if(index == length) return true;
    	
    	int x, y;
    	int i, cur;
    	cur = candidates[index];
    	x = cur/9;
    	y = cur%9;
    	/*cout<<"CUR:"<<index<<','<<x<<' '<<y<<endl;
				
		for(int m=0; m<9; m++)
		{
			for(int n=0; n<9; n++)
			{
				cout<<board[m][n]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;*/
		
    	for(i=1; i<=9; i++)
    	{
    		board[x][y] = (char)(i + '0');
			
			
    		if(isValidSudoku(board, x, y, i))
    		{
    			if(SudokuSolver(board, candidates, index+1, length))
					return true;
				else
					board[x][y] = '.';
    		}
    		else
    		{
    			board[x][y] = '.';
    		}
    	}
    	return false;
    }
    
    bool isValidSudoku(vector<vector<char> > &board, int row, int col, int target)
    {
    	int t;
    	int i, j, x, y;
    	for(i=0; i<9; i++)
    	{
    		if(i == col) continue;
    		t = (int)(board[row][i] - '0');
    		if(t == target)
    			return false;
    	}
    	for(i=0; i<9; i++)
    	{
    		if(i == row) continue;
    		t = (int)(board[i][col] - '0');
    		if(t == target)
    			return false;
    	}
    	x = row/3;
    	y = col/3;
    	for(i = x * 3; i < x * 3 + 3; i++)
    	{
    		for(j = y * 3; j < y * 3+3; j++)
    		{
    			if(i == row && j == col) continue;
    			t = (int)(board[i][j] - '0');
    			if(t == target)
    				return false;
    		}
    	}
    	return true;
    }
};

int main()
{
	string test[] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
	int i, j;
	vector<char> t;
	vector<vector<char> > in;
	Solution *slt = new Solution();
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			t.push_back(test[i][j]);
		}
		in.push_back(t);
		t.clear();
	}
	
	slt->solveSudoku(in);
	
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			cout<<in[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
