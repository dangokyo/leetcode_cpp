#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(n == 0) return 0;
        
        vector<vector<int> > map;
        vector<int> row;
        int i, j;
        for(i=0; i<n; i++)
                 row.push_back(0);
        for(i=0; i<m; i++)
                 map.push_back(row);
        map[0][0] = 1 - obstacleGrid[0][0]; 
        for(i=1; i<n; i++)
                 map[0][i] = map[0][i-1] * (1 - obstacleGrid[0][i]);
        for(i=1; i<m; i++) 
                 map[i][0] = map[i-1][0] * (1 - obstacleGrid[i][0]);
        
        
        for(j = 1; j < m; j++)
        {
              for(i=1; i<n; i++)
              {
                       map[j][i] = (map[j-1][i] + map[j][i-1]) * (1 - obstacleGrid[j][i]);
              }
        }
        
        return map[m-1][n-1];
        
    }
};

int main()
{
    int in1, in2;
    Solution *slt = new Solution();
    in1 = 3;
    in2 = 4;
    cout<<slt->uniquePaths(in1, in2)<<endl;
    cin>>in1;
    return 0;
}
