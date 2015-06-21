#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        if(n==0) return 0;
        
        vector<vector<int> > map;
        vector<int> row;
        int i, j;
        for(i=0; i<n; i++)
                 row.push_back(0);
        for(i=0; i<m; i++)
                 map.push_back(row);
                 
        map[0][0] = grid[0][0];
        for(i=1; i<n; i++)
                 map[0][i] = grid[0][i] + map[0][i-1];
        for(i=1; i<m; i++)
                 map[i][0] = grid[i][0] + map[i-1][0];
        
        for(i=1; i<m; i++)
        {
                 for(j=1; j<n; j++)
                 {
                          map[i][j] = grid[i][j] + min(map[i-1][j], map[i][j-1]);
                 }
        }
        return map[m-1][n-1];      
    }
    
    int min(int a, int b)
    {
        if(a >= b)
             return b;
        else
            return a;
    }
};

int main()
{
    int x = 3, y = 4;
    vector<vector<int> > in;
    vector<int> t;
    Solution *slt = new Solution();
    int i;
    for(i=0; i<x; i++)
             t.push_back(i+1);
    for(i=0; i<y; i++)
             in.push_back(t);
    cout<<slt->minPathSum(in)<<endl;
    
    cin>>x;
    return 0;
}
    
