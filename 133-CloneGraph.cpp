#include<iostream>
#include<vector>
#include<map>
using namespace std;


struct UndirectedGraphNode {
       int label;
       vector<UndirectedGraphNode *> neighbors;
       UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL) return NULL;
    	
        UndirectedGraphNode *t;
        map<UndirectedGraphNode*, UndirectedGraphNode*> mymap;
        t = CloneSolver(node, mymap);
        return t;
    }
    
    UndirectedGraphNode* CloneSolver(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> &mymap)
    {
    	if(mymap.count(node) > 0) return node;
    	UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    	mymap[node] = new_node;
    	int i, j;
    	int count;
    	int length = node->neighbors.size();
    	map<UndirectedGraphNode*, bool> isVisited;
    	for(i=0; i<length; i++)
    	{
    		if(mymap.count(node->neighbors[i]) > 0)
    		{
    			if(node->neighbors[i] == node)
    			{
    				new_node->neighbors.push_back(mymap.find(node->neighbors[i])->second);
    			}
    			else
    			{
    				if(isVisited.count(node->neighbors[i]) > 0) continue;
    				count = edgeCounter(node->neighbors, node->neighbors[i]);
    				//cout<<"num of edge"<<count<<" from "<<node->label<<" to "<<node->neighbors[i]->label<<endl;
    				for(j=0; j<count; j++)
    				{
    					new_node->neighbors.push_back(mymap.find(node->neighbors[i])->second);
    				}
    				isVisited[node->neighbors[i]] = true;
    			}
    		}
    		else
    		{
    			count = edgeCounter(node->neighbors, node->neighbors[i]);
    			UndirectedGraphNode *t_node = CloneSolver(node->neighbors[i], mymap);
    			if(isVisited.count(node->neighbors[i]) > 0) continue;
    			if(t_node == NULL) continue;
    			//cout<<"num of edge"<<count<<endl;
    			for(j=0; j<count; j++)
				{	
					new_node->neighbors.push_back(t_node);
				}
    			isVisited[node->neighbors[i]] = true;
    		}
    	}
    	return new_node;
    }
    
    int edgeCounter(vector<UndirectedGraphNode *> neighbors, UndirectedGraphNode *node)
    {
    	int ans = 0;
    	int length = neighbors.size();
    	int i;
    	for(i=0; i<length; i++)
    	{
    		if(node == neighbors[i]) ans++;
    	}
    	return ans;
    }
};

void traverseGraph(UndirectedGraphNode *node, map<UndirectedGraphNode*, bool> &visited)
{
	if(visited.count(node) > 0) return;
	
	cout<<node->label<<":"<<node->neighbors.size()<<endl;
	int i;
	visited[node] = true;
	for(i=0; i<node->neighbors.size(); i++)
	{
		traverseGraph(node->neighbors[i], visited);
	}
}
int main()
{
	UndirectedGraphNode *t0 = new UndirectedGraphNode(0);
	UndirectedGraphNode *t1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *t2 = new UndirectedGraphNode(2);
	UndirectedGraphNode *t3 = new UndirectedGraphNode(3);
	UndirectedGraphNode *t4 = new UndirectedGraphNode(4);
	UndirectedGraphNode *t5 = new UndirectedGraphNode(5);
	t0->neighbors.push_back(t1);
	t0->neighbors.push_back(t5);
	t1->neighbors.push_back(t0);
	t1->neighbors.push_back(t2);
	t1->neighbors.push_back(t5);
	t2->neighbors.push_back(t1);
	t2->neighbors.push_back(t3);
	t3->neighbors.push_back(t2);
	t3->neighbors.push_back(t4);
	t3->neighbors.push_back(t4);
	t4->neighbors.push_back(t3);
	t4->neighbors.push_back(t3);
	t4->neighbors.push_back(t5);
	t4->neighbors.push_back(t5);
	t5->neighbors.push_back(t4);
	t5->neighbors.push_back(t4);
	t5->neighbors.push_back(t1);
	t5->neighbors.push_back(t0);
	
	Solution *slt = new Solution();
	UndirectedGraphNode *t = slt->cloneGraph(t0);
	map<UndirectedGraphNode*, bool> visited;
	cout<<"hehe"<<endl;
	traverseGraph(t, visited);
    return 0;
}
