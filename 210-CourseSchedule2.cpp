#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    	vector<int> v(numCourses, 0);
    	vector<int> discover(numCourses, 0);
    	vector<int> finish(numCourses, 0);
    	vector<int> ans;
    	vector<bool> isVisited(numCourses, false);
    	vector<vector<bool> > graph(numCourses, isVisited);
    	int i, j;
    	int time = 1;
    	bool flag;
		for(vector<pair<int, int> >::iterator VI=prerequisites.begin(), VE=prerequisites.end(); VI!=VE; VI++)
    	{
    		graph[VI->second][VI->first] = true;
    	}
    	for(i=0; i<numCourses; i++)
    	{
    		if(isIsolated(i, numCourses, graph))
    		{
    			flag = DFS(i, time, graph, discover, finish, ans);
    			if(!flag) 
                {
                          ans.clear();
                          return ans;
                }
    		}	
    	}
    	for(i=0; i<numCourses; i++)
    	{
    		if(discover[i] == 0 || finish[i] == 0) 
            {
                           ans.clear();
                           return ans;
            }
    	}
    	reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool DFS(int v, int &time, vector<vector<bool> >& graph, vector<int>& discover, vector<int>& finish, vector<int> &ans)
    {
    	discover[v] = time;
    	time++;
    	vector<int> toVisit;
    	bool flag = FindNextVisited(v, toVisit, graph, discover, finish);
    	if(!flag) return false;
    	for(int i=0; i<toVisit.size(); i++)
    	{
    		flag = DFS(toVisit[i], time, graph, discover, finish, ans);
    		if(!flag) return false;
    	}
    	finish[v] = time;
    	ans.push_back(v);
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
	pair<int, int>  t2(2, 1);
	pair<int, int>  t3(1, 2);
	pair<int, int>  t4(4, 0);
	pair<int, int>  t5(5, 4);
	pair<int, int>  t6(6, 5);
	vector<pair<int, int> > in;
	vector<int> result;
	Solution *slt = new Solution();
	in.push_back(t1);
	in.push_back(t2);
	in.push_back(t3);
	in.push_back(t4);
	in.push_back(t5);
	in.push_back(t6);
	
	result = slt->findOrder(6, in);
	for(int i=0; i<result.size(); i++)
	{
            cout<<result[i]<<' ';
    }
    cout<<endl;
    getchar();
	return 0;
}
