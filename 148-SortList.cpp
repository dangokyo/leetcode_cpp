#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
    	int length = 0;
    	int interval;
		ListNode *p = head;
		ListNode *t;
    	while(p!=NULL)
    	{
    		length++;
    		p=p->next;
    	}
    	ListNode *newNode = new ListNode(0);
    	newNode->next = head;
    	ListNode *left, *right;
    	for(interval=1; interval<length; interval = interval*2)
    	{
    		p = newNode;
    		left = newNode->next;
    		right = newNode->next;
    		t = p->next;
    		while(left!=NULL && right!=NULL)
    		{
    			int i = 0;
    			while(i<interval&& right!=NULL)
    			{
    				right = right->next;
    				i++;
    			}
    			//cout<<"test1:"<<left->val<<" "<<right->val<<endl;
    			int leftcount = 0, rightcount = 0;
    			while(leftcount < interval && rightcount<interval && left!=NULL && right!=NULL)
    			{
    				if(left->val < right->val)
    				{
    					p->next = left;
    					p = p->next;
    					left = left->next;
    					leftcount++;
    				}
    				else
    				{
    					p->next = right;
    					p = p->next;
    					right = right->next;
    					rightcount++;
    				}
    			}
    			
    			while(left!=NULL&& leftcount<interval)
    			{
    				p->next = left;
    				p = p->next;
    				left = left->next;
    				leftcount++;
    			}
    			
    			while(right!=NULL && rightcount<interval)
    			{
    				p->next = right;
    				p=p->next;
    				right = right->next;
    				rightcount++;
    			}
    			p->next = right;
    			left =right;
    		}
    	}
    	return newNode->next;
    }
};

int main()
{
	ListNode *t1 = new ListNode(3);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(5);
	ListNode *t4 = new ListNode(1);
	ListNode *t5 = new ListNode(4);
	ListNode *t6 = new ListNode(6);
	ListNode *t7 = new ListNode(8);
	ListNode *t8 = new ListNode(7);
	ListNode *t9 = new ListNode(9);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;
	t5->next = t6;
	t6->next = t7;
	t7->next = t8;
	t8->next = t9;
	Solution *slt=new Solution();
	ListNode *p = slt->sortList(t1);
	while(p!=NULL)
	{
		cout<<p->val<<' ';
		p= p->next;
	}
	cout<<endl;
	return 0;
}
