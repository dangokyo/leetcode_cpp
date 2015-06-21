#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    	vector<int> v(numCourses, 0);
    	vector<int> discover(numCourses, 0);
    	vector<int> finish(numCourses, 0);
    	stack<int> mystack;
    	vector<int> toVisit;
    	vector<bool> isVisited(numCourses, false);
    	vector<vector<bool> > graph(numCourses, isVisited);
    	int i, j;
    	int time = 1;
    	int tmp;
    	bool flag;
		for(vector<pair<int, int> >::iterator VI=prerequisites.begin(), VE=prerequisites.end(); VI!=VE; VI++)
    	{
    		graph[VI->second][VI->first] = true;
    	}
    	for(i=0; i<numCourses; i++)
    	{
    		if(isIsolated(i, numCourses, graph))
    		{
    			//start to do DFS
    			flag = DFS(i, time, graph, discover, finish);
    			if(!flag) return false;
    		}	
    	}
    	for(i=0; i<numCourses; i++)
    	{
    		if(discover[i] == 0) return false;
    	}
        return true;
    }
    
    bool DFS(int v, int &time, vector<vector<bool> >& graph, vector<int>& discover, vector<int>& finish)
    {
    	discover[v] = time;
    	time++;
    	vector<int> toVisit;
    	bool flag = FindNextVisited(v, toVisit, graph, discover, finish);
    	if(!flag) return false;
    	for(int i=0; i<toVisit.size(); i++)
    	{
    		flag = DFS(toVisit[i], time, graph, discover, finish);
    		if(!flag) return false;
    	}
    	finish[v] = time;
    	time++;
    	
    	return true;
    }
    
    bool FindNextVisited(int v, vector<int> &toVisit, vector<vector<bool> >& graph, vector<int>& discover, vector<int>& finish)
    {
    	int size = discover.size();
    	for(int i=0; i<size; i++)
    	{
    		if(graph[v][i])
    		{
    			//cout<<v<<" "<<i<<" "<<discover[v]<<" "<<finish[v]<<" "<<discover[i]<<" "<<finish[i]<<endl;
    			if(discover[i]>0 && finish[i]==0)
    			{
    				return false;
    			}
    			else if(discover[i]==0 && finish[i]==0)
    			{
    				toVisit.push_back(i);
    			}
    			else if(discover[i]==0 && finish[i]==0)
    			{
    				continue;
    			}
    		}
    	}
    	return true;
    }
    
    bool isIsolated(int v, int& num, vector<vector<bool> >& graph)
    {
    	for(int i=0; i<num; i++)
    	{
    		if(graph[i][v]) return false;
    	}
    	return true;
    }
};

int main()
{
	pair<int, int>  t1(1, 0);
	pair<int, int>  t2(1, 7);
	pair<int, int>  t3(7, 0);
	pair<int, int>  t4(0, 5);
	pair<int, int>  t5(2, 6);
	pair<int, int>  t6(6, 4);
	vector<pair<int, int> > in;
	Solution *slt = new Solution();
	in.push_back(t1);
	in.push_back(t2);
	in.push_back(t3);
	in.push_back(t4);
	in.push_back(t5);
	in.push_back(t6);
	
	cout<<slt->canFinish(8, in)<<endl;
	return 0;
}
