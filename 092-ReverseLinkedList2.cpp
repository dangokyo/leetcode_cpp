#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	int count;
    	ListNode *p, *tstart, *tend, *t;
    	
    	if(m == 1)
    	{
    		tstart = head;
    		p = head;
    		count = 0;
    		while(count < n - m)
    		{
    			p = tstart->next;
    			tstart->next = p->next;
    			p->next = head;
    			head = p;
    			count++;
    			cout<<count<<endl;
    		}
    	}
    	else if(m > 1)
    	{
    		count = 1;
    		p = head;
    		cout<<"this part"<<endl;
    		while(p != NULL)
    		{
    			if(count == m - 1)
    			{
    				t = p;
    				p = p->next;
    				tstart = p;
    				tend = p;
    				break;
    			}
    			else
    			{
    				p=p->next;
    				count++;
    			}
    		}
    		
    		count = 0;
    		while(count < n - m)
    		{
    			p = tstart->next;
    			t->next = p;
    			tstart->next = p->next;
    			p->next = tend;
    			tend = p;
    			count++;
    		}
    	}
    	return head;
    }
};


int main()
{
	ListNode *head = new ListNode(1);
	ListNode *t1 = new ListNode(2);
	ListNode *t2 = new ListNode(3);
	ListNode *t3 = new ListNode(4);
	ListNode *t4 = new ListNode(5);
	head->next = t1;
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	Solution *slt = new Solution();
	ListNode *result = slt->reverseBetween(head, 2, 3);
	ListNode *p = result;
	while(p!=NULL)
	{
		cout<<p->val<<' ';
		p=p->next;
	}
	return 0;
} 
