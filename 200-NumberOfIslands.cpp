#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int i, j;
        int length, width;
        length = grid.size();
        if(length<1) return 0;
        width = grid[0].size();
        int ans = 0;
        if(width<1) return 0;
        
        vector<bool> v(width, false);
        vector<vector<bool> > Visited(length, v);
        
        vector<int> iv(width, 0);
        vector<vector<int> > IDMap(length, iv);
        for(i=0; i<length; i++)
        {
                 for(j=0; j<width; j++)
                 {
                       if(isLand(grid, i, j))
                       {
                                     if(!Visited[i][j])
                                     {
                                                       ans++;
                                                       cout<<"test:"<<i<<' '<<j<<endl;
                                                       MarkLand(grid, i, j, Visited);    
                                     }
                                     else continue;  
                       }
                       else continue;   
                 }
        }
        return ans;
    }
    
    int MarkLand(vector<vector<char> > &grid, int x, int y, vector<vector<bool> > &Visited)
    {
        cout<<"test1:"<<x<<' '<<y<<endl;
        Visited[x][y] = true;
        if(isLand(grid, x-1, y))
        {
                        if(!Visited[x-1][y]) MarkLand(grid, x-1, y, Visited);
        }
        if(isLand(grid, x+1, y))
        {
                        if(!Visited[x+1][y]) MarkLand(grid, x+1, y, Visited);
        }
        if(isLand(grid, x, y+1))
        {
                        if(!Visited[x][y+1]) MarkLand(grid, x, y+1, Visited);
        }
        if(isLand(grid, x, y-1))
        {
                        if(!Visited[x][y-1]) MarkLand(grid, x, y-1, Visited);
        }
        return 0;
    }
    
    bool isLand(vector<vector<char> > &grid, int x, int y)
    {
         int length = grid.size();
         int width = grid[0].size();
         
         if(x>=length || y >= width || x<0 || y<0) return false;
         if(grid[x][y] == '1')
         {
                       return true;
         }
         else return false;
    }
};

int main()
{
    vector<char> v(7, '0');
    vector<vector<char> > grid(7, v);
    int i, j;
    Solution *slt = new Solution();
    grid[0][0] = '1';
    grid[0][1] = '1';
    grid[0][2] = '1';
    grid[0][3] = '1';
    grid[0][4] = '1';
    grid[0][5] = '1';
    grid[0][6] = '1';
    grid[1][6] = '1';
    grid[2][0] = '1';
    grid[2][1] = '1';
    grid[2][2] = '1';
    grid[2][3] = '1';
    grid[2][4] = '1';
    grid[2][6] = '1';
    grid[3][0] = '1';
    grid[3][4] = '1';
    grid[3][6] = '1';
    grid[4][0] = '1';
    grid[4][2] = '1';
    grid[4][4] = '1';
    grid[4][6] = '1';
    grid[5][0] = '1';
    grid[5][2] = '1';
    grid[5][3] = '1';
    grid[5][4] = '1';
    grid[5][6] = '1';
    grid[6][0] = '1';
    grid[6][1] = '1';
    grid[6][2] = '1';
    grid[6][3] = '1';
    grid[6][4] = '1';
    grid[6][5] = '1';
    grid[6][6] = '1';
    for(i=0; i<grid.size();i++)
    {
             for(j=0; j<grid[i].size(); j++)
             {
                      cout<<grid[i][j]<<' ';
             }
             cout<<endl;
    }
    cout<<endl;
    cout<<slt->numIslands(grid)<<endl;
    cin>>i;
    return 0;
}
