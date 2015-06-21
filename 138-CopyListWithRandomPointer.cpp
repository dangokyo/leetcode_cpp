#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head;
        RandomListNode *ans;
        unordered_map<RandomListNode*, RandomListNode*> nodeMap; //from old linked list to new linked list
        if(head == NULL) return NULL;
        
        ans = new RandomListNode(p->label);
        RandomListNode *newcur = ans;
        nodeMap[p] = newcur;
        p = p->next;
        while(p!=NULL)
        {
        	RandomListNode *newNode = new RandomListNode(p->label);
        	newcur->next = newNode;
        	newcur = newNode;
        	nodeMap[p] = newNode;
        	p = p->next;
        }
        
        p = head;
        while(p!=NULL)
        {
        	nodeMap[p]->random = nodeMap[p->random];	
        	p = p->next;
        }
        
        return ans;
    }
};

int main()
{
	RandomListNode *t1 = new RandomListNode(1);
	RandomListNode *t2 = new RandomListNode(3);
	RandomListNode *t3 = new RandomListNode(5);
	RandomListNode *t4 = new RandomListNode(9);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t1->random = t4;
	t3->random = t2;
	Solution *slt = new Solution();
	RandomListNode *p = slt->copyRandomList(t1);
	cout<<t1<<':'<<t1->label<<endl;
	cout<<t2<<':'<<t2->label<<endl;
	cout<<t3<<':'<<t3->label<<endl;
	cout<<t4<<':'<<t4->label<<endl;
	while(p!=NULL)
	{
		cout<<p<<':'<<p->label;
		if(p->random!=NULL) cout<<' '<<p->random->label<<endl;
		else cout<<endl;
		p=p->next;
	}
	return 0;
}
