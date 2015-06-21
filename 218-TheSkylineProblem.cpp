#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
    	vector<pair<int, int> >  ans;
    	int length = buildings.size();
    	if(length == 0) return ans;
    	ans = getSkylineSolver(0, length-1, buildings);
    	return ans;
    }
    
    vector<pair<int, int> > getSkylineSolver(int left, int right, vector<vector<int> >& buildings)
    {
    	//cout<<"start to solve"<<left<<' '<<right<<endl;
    	vector<pair<int, int> > sol;
    	if(left == right) 
		{
			sol = SkylineScan(left, buildings);
		}
		else
		{
			int middle = (left + right)/2;
			vector<pair<int, int> > left_part = getSkylineSolver(left, middle, buildings);
			vector<pair<int, int> > right_part = getSkylineSolver(middle+1, right, buildings);
			sol = SkylineMerge(left_part, right_part);
		}
		return sol;
    }
    
    vector<pair<int, int> > SkylineScan(int pos, vector<vector<int> >& buildings)
    {
    	vector<int> vec = buildings[pos];
    	vector<pair<int, int> > sol;
    	pair<int, int> p1 = make_pair(vec[0], vec[2]);
    	pair<int, int> p2 = make_pair(vec[1], 0);
    	sol.push_back(p1);
    	sol.push_back(p2);
    	return sol;
    }
    
    vector<pair<int, int> > SkylineMerge(vector<pair<int, int> > left, vector<pair<int, int> > right)
    {
    	vector<pair<int, int> >::iterator left_start = left.begin();
    	vector<pair<int, int> >::iterator left_end = left.end();
    	vector<pair<int, int> >::iterator right_start = right.begin();
    	vector<pair<int, int> >::iterator right_end = right.end();
    	vector<pair<int, int> > sol;
    	int height = 0, current_height=0;
    	int left_height = 0, right_height = 0;
    	int left_index, right_index, index;
    	for(left_start, right_start ;left_start!= left_end || right_start!=right_end ;)
    	{
    		if(left_start == left_end && right_start != right_end)
    		{
    			while(right_start!= right_end)
    			{
    				//cout<<"left finished, processing right:"<<(*right_start).first<<endl;
    				sol.push_back(*right_start);
    				right_start++;
    			}
    		}
    		else if(left_start != left_end && right_start == right_end)
    		{
    			while(left_start!= left_end)
    			{
    				//cout<<"right finished, processing left:"<<(*left_start).first<<endl;
    				sol.push_back(*left_start);
    				left_start++;
    			}
    		}
    		else
    		{
    			left_index = (*left_start).first;
    			right_index = (*right_start).first;
    			//cout<<"normal processing:"<<left_index<<' '<<right_index<<endl;
    			if(left_index < right_index)
    			{
    				index = left_index;
    				left_height = (*left_start).second;
    				height = max(left_height, right_height);
    				left_start++;
    			}
    			else if(left_index > right_index)
    			{
    				index = right_index;
    				right_height = (*right_start).second;
    				height = max(left_height, right_height);
    				right_start++;
    			}
    			else if(left_index == right_index)
    			{
    				index = left_index;
    				left_height = (*left_start).second;
    				right_height = (*right_start).second;
    				height = max(left_height, right_height);
    				left_start++;
    				right_start++;
    			}
    			
    			//cout<<"add height:"<<height<<" "<<current_height<<endl;
    			if(height == current_height) continue;
    			else
    			{
    				pair<int, int> p = make_pair(index, height);
    				current_height = height;
    				sol.push_back(p);
    			}
    			
    			
    		}
    	}
    		
    	return sol;
    }
};

int main()
{
	vector<int> in1;
	vector<int> in2;
	vector<vector<int> > in;
	vector<pair<int, int> > result;
	Solution *slt = new Solution();
	in1.push_back(2);
	in1.push_back(11);
	in1.push_back(9);
	in2.push_back(3);
	in2.push_back(13);
	in2.push_back(10);
	in.push_back(in1);
	in.push_back(in2);
	result = slt->getSkyline(in);
	for(vector<pair<int, int> >::iterator VI = result.begin(); VI!=result.end(); VI++)
	{
		cout<<(*VI).first<<' '<<(*VI).second<<endl;
	}
	return 0;
}
