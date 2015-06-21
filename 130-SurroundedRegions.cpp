#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    void solve(vector<vector<char> > &board) {
         int height = board.size();
         if(height == 0) return;
         
         int width = board[0].size();
         if(width == 0) return;
         int i, j;
         
         for(i=0; i<width; i++)
         {
                  if(board[0][i]=='O')
                  {
                                   reverseTravel(board, 0, i, height, width);                
                  }
                  if(board[height-1][i]=='O')
                  {
                                   reverseTravel(board, height-1, i, height, width);                
                  }
                                           
         }
         
         for(i=0; i<height; i++)
         {
                  if(board[i][0]=='O')
                  {
                                    reverseTravel(board, i, 0, height, width);
                  }
                  
                  if(board[i][width-1]=='O')
                  {
                                          reverseTravel(board, i, width-1, height, width);
                  }
         }
         for(i=0; i< height; i++)
         {
                  for(j=0; j<width; j++)
                  {
                          if(board[i][j]=='O') board[i][j] = 'X';
                          if(board[i][j]=='A') board[i][j] = 'O';
                  }
         }
    }
    
    void reverseTravel(vector<vector<char> > &board, int x, int y, int &height, int &width)
    {
         board[x][y] = 'A';
         if(y+1<width-1 && board[x][y+1]=='O')
         {
                   reverseTravel(board, x, y+1, height, width);     
         }
         
         if(y-1>0 && board[x][y-1]=='O')
         {
                   reverseTravel(board, x, y-1, height, width);   
         }
         
         if(x+1<height-1 && board[x+1][y]=='O')
         {
                   reverseTravel(board, x+1, y, height, width);   
         }
         
         if(x-1>0 && board[x-1][y] == 'O')
         {
                   reverseTravel(board, x-1, y, height, width);  
         } 
    }       
};

int main()
{
    int in1 =5;
    int in2 =7;
    vector<char> v(in1, 'X');
    vector<vector<char> > board(in2, v);
    Solution *slt = new Solution();
    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[4][4] = 'O';
    board[3][4] = 'O';
    board[3][3] = 'O';
    int i, j;
    for(i=0; i<in2; i++)
    {
             for(j=0; j<in1; j++)
             {
                      cout<<board[i][j]<<' ';
             }
             cout<<endl;
    }
    slt->solve(board);
    cout<<endl;
    for(i=0; i<in2; i++)
    {
             for(j=0; j<in1; j++)
             {
                      cout<<board[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>in1;
    return 0;
}
