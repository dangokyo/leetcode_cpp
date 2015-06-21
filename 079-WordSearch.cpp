#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	
	int length;
	int height;
	int width;
    bool exist(vector<vector<char> >& board, string word) {
    	length = word.size();
    	if(length == 0) return true;
    	
    	height = board.size();
    	if(height==0) return false;
    	width = board[0].size();
    	if(width ==0) return false;
    	
    	if(length > length * height) return false;
    	//cout<<length<<' '<<height<<' '<<width<<endl;
    	
    	int i, j;
    	for(i=0; i<height; i++)
    	{
    		for(j=0; j<width; j++)
    		{
    			//cout<<"start:"<<i<<' '<<j<<endl;
    			if(WordSearchSolver(i, j, 0, board, word) ) return true;
    		}
    	}
        return false;
    }
    
    bool WordSearchSolver(int x, int y, int level, vector<vector<char> >& board, string& word)
    {
    	//cout<<"processing1:"<<level<<' '<<x<<' '<<y<<endl;
    	if (board[x][y] != word[level] || board[x][y] == ' ')
            return false;
        else if (level == word.size() - 1)
            return true;
    	
    	char t = board[x][y];
    	//cout<<"processing2:"<<x<<' '<<y<<endl;
    	board[x][y] = ' ';
    	if((x+1 < height && WordSearchSolver(x+1, y, level+1, board, word)) 
		|| (y+1 < width && WordSearchSolver(x, y+1, level+1, board, word)) 
    	|| (x >= 1 && WordSearchSolver(x-1, y, level+1, board, word))
    	|| (y >= 1 && WordSearchSolver(x, y-1, level+1, board, word))
    	)
    	{
    		return true;
    	}
    	board[x][y] = t;
    	return false;
    }
};

int main()
{
	Solution *slt = new Solution();
	vector<char> v(4, 'A');
	vector<vector<char> > board(3, v);
	
	board[0][1] = 'B';
	board[0][2] = 'C';
	board[0][3] = 'E';
	board[1][0] = 'S';
	board[1][1] = 'F';
	board[1][2] = 'C';
	board[1][3] = 'S';
	board[2][1] = 'D';
	board[2][2] = 'E';
	board[2][3] = 'E';
	string word1 = "SEE";
	string word2 = "ABCCED";
	string word3 = "ABCB";
	cout<<slt->exist(board, word1)<<endl;
	//cout<<slt->exist(board, word2)<<endl;
	//cout<<slt->exist(board, word3)<<endl;
	return 0;
}
