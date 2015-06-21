#include<vector>
#include<string>
#include<climits>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int length, width;
        int i, j;
        int dir=0; // 0: right, 1:down, 2:left, 3:up
        int x, y;
        x = 1;
        y = 1;
        vector<int> ans;
        vector<vector<bool> > boundary;
        vector<bool> tb;
        length = matrix.size() + 2;
        if(length == 2)
        	return ans;
        width = matrix[0].size() + 2;
        if(length == 2 || width == 2)
        	return ans;
        for(i=0; i<width; i++)
        {
        	tb.push_back(true);
        }
        for(i=0; i<length; i++)
        {
        	boundary.push_back(tb);
        }
        for(i=0; i<width; i++)
        {
        	boundary[0][i] = false;
        	boundary[length - 1][i] = false;
        }
        for(i=0; i<length; i++)
        {
        	boundary[i][0] = false;
        	boundary[i][width - 1] = false;
        }
        
        while(boundary[x+1][y] || boundary[x-1][y] || boundary[x][y+1] || boundary[x][y-1])
        {
        	if(dir == 0)
        	{
				boundary[x][y] = false;
				ans.push_back(matrix[x-1][y-1]);
        		if(!boundary[x][y+1])
        		{
        			dir = 1;
        			x = x+1;
        			y = y;
        		}
        		else
        		{
        			x = x;
        			y = y+1;
        		}
        	}
        	else if(dir == 1)
        	{
				boundary[x][y] = false;
				ans.push_back(matrix[x-1][y-1]);
        		if(!boundary[x+1][y])
        		{
        			dir = 2;
        			x = x;
        			y = y - 1;
        		}
        		else
        		{
        			x = x + 1;
        			y = y;
        		}
        	}
        	else if(dir == 2)
        	{
				boundary[x][y] = false;
				ans.push_back(matrix[x-1][y-1]);
        		if(!boundary[x][y-1])
        		{
        			dir = 3;
        			x = x-1;
        			y = y;
        		}
        		else
        		{
        			x = x;
        			y = y-1;
        		}
        	}
        	else if(dir == 3)
        	{
				boundary[x][y] = false;
				ans.push_back(matrix[x-1][y-1]);
        		if(!boundary[x-1][y])
        		{
        			dir = 0;
        			x = x ;
        			y = y + 1;
        		}
        		else
        		{
        			x = x - 1;
        			y = y;
        		}
        	}
        	
        }
		ans.push_back(matrix[x-1][y-1]);
        return ans;
    }
};

int main()
{
	vector<vector<int> > in;
	vector<int> t,result;
	Solution *slt = new Solution();
	/*t.push_back(1);
	t.push_back(2);
	t.push_back(3);
	t.push_back(4);
	in.push_back(t);
	in.push_back(t);
	in.push_back(t);*/
	result = slt->spiralOrder(in);
	for(int i=0; i<result.size(); i++)
		cout<<i<<':'<<result[i]<<endl;
	cout<<endl;
	return 0;
}
