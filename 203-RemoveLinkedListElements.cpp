#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	if(head==NULL) return head;
    	ListNode *p = head;
    	while(p!=NULL)
    	{
    		if(p->val == val)
    		{	
				p = p->next;
    		}
			else break;	
    	}
    	if(p==NULL) return p;
    	ListNode *t = p;
    	ListNode *p1, *p2;
    	while(t->next != NULL)
    	{
    		p1 = t->next;
    		if(p1->val == val)
    		{
    			p2 = p1->next;
    			t->next = p2;
    		}
    		else
    		{
    			t = t->next;	
    		}
    	}
    	return p;
    }
};

int main()
{
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(6);
	ListNode *l4 = new ListNode(3);
	ListNode *l5 = new ListNode(4);
	ListNode *l6 = new ListNode(5);
	ListNode *l7 = new ListNode(6);
	//l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	Solution *slt = new Solution();
	ListNode *p = slt->removeElements(l1, 1);
	while(p!=NULL)
	{
		cout<<p->val<<' ';
		p = p->next;
	}
	return 0;
}
