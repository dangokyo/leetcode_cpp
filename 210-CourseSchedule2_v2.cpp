#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    	vector<int> indegree(numCourses, 0);
    	vector<int> ans;
    	vector<bool> isVisited(numCourses, false);
    	vector<vector<bool> > graph(numCourses, isVisited);
    	queue<int> myqueue;
    	int i, j, t;
    	bool flag;
		for(vector<pair<int, int> >::iterator VI=prerequisites.begin(), VE=prerequisites.end(); VI!=VE; VI++)
    	{
            if(graph[VI->second][VI->first]) continue;
    		graph[VI->second][VI->first] = true;
    		indegree[VI->first]++;
    	}
    	for(i=0; i<numCourses; i++)
    	{
                 if(indegree[i]==0) myqueue.push(i);
        }
        while(!myqueue.empty())
        {
                               t = myqueue.front();
                               isVisited[t] = true;
                               myqueue.pop();
                               ans.push_back(t);
                               for(i=0; i<numCourses; i++)    
                               {
                                        if(graph[t][i])
                                        {
                                                       indegree[i]--;
                                                       if(indegree[i]==0 && !isVisited[i]) myqueue.push(i);
                                        }
                               }
        }
        if(ans.size() < numCourses)
        {
                          ans.clear();
        }              
        return ans;
    }
};

int main()
{
	pair<int, int>  t1(5, 8);
	pair<int, int>  t2(3, 5);
	pair<int, int>  t3(1, 9);
	pair<int, int>  t4(4, 5);
	pair<int, int>  t5(0, 2);
	pair<int, int>  t6(1, 9);
	pair<int, int>  t7(7, 8);
	pair<int, int>  t8(4, 9);
	vector<pair<int, int> > in;
	vector<int> result;
	Solution *slt = new Solution();
	in.push_back(t1);
	in.push_back(t2);
	in.push_back(t3);
	in.push_back(t4);
	in.push_back(t5);
	in.push_back(t6);
	in.push_back(t7);
	in.push_back(t8);
	
	result = slt->findOrder(10, in);
	for(int i=0; i<result.size(); i++)
	{
            cout<<result[i]<<' ';
    }
    cout<<endl;
    getchar();
	return 0;
}
