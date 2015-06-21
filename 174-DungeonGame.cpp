#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int height = dungeon.size();
        if(height<1) return 0; 
        
        int width = dungeon[0].size();
        if(width<1) return 0;
        vector<int> dp(width, 0);
        int i, j;
        int t;
        dp[width-1] = max(1, 1-dungeon[height-1][width-1]);
        for(i=width-2; i>=0; i--)
        {
                     dp[i] = max(1, dp[i+1]-dungeon[height-1][i]);                 
        }
        //for(i=0; i<width; i++) cout<<dp[i]<<' ';
        //cout<<endl;
        
        for(i = height-2; i>=0; i--)
        {
              dp[width-1] = max(1, dp[width-1] - dungeon[i][width-1]);
              for(j=width-2; j>=0; j--)
              {
                   t = min(dp[j], dp[j+1]);    
                   dp[j] = max(1, t-dungeon[i][j]);
              }
              
        }
        return dp[0];
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int> v(3, 0);
    vector<vector<int> > dungeon(3, v);
    dungeon[0][0] = -2;
    dungeon[0][1] = -3;
    dungeon[0][2] = 3;
    dungeon[1][0] = -5;
    dungeon[1][1] = -10;
    dungeon[1][2] = 1;
    dungeon[2][0] = 10;
    dungeon[2][1] = 30;
    dungeon[2][2] = -5;
    cout<<slt->calculateMinimumHP(dungeon)<<endl;
    getchar();
    return 0;
}
