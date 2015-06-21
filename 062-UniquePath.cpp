#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
                return 0;
        vector<vector<int> > map;
        vector<int> row;
        int i, j;
        for(i=0; i<n; i++)
                 row.push_back(0);
        for(i=0; i<m; i++)
                 map.push_back(row);
        for(i=0; i<n; i++)
                 map[0][i] = 1;
        for(i=0; i<m; i++)
                 map[i][0] = 1;
        
        for(j = 1; j < m; j++)
        {
              for(i=1; i<n; i++)
              {
                       map[j][i] = map[j-1][i] + map[j][i-1];
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
