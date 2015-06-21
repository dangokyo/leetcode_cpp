#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == NULL) return NULL;
    	
    	if(k==1) return head;
    	
		//cout<<"hehe"<<endl;
    	int i = 0;
		ListNode *p1 = head;
		ListNode *rbegin, *rend, *tstart, *t;
		ListNode *ans = new ListNode(0);
		ans->next = head;
		tstart = ans;
		while(p1!= NULL)
    	{
    		//cout<<"test:"<<p1->val<<endl;
    		i = 0;
    		rend = p1;
    		rbegin = p1;
    		while(i < k && rend!=NULL)
    		{
    			i++;
    			rend = rend->next;
    		}
    		if(i < k) return ans->next;
    		
    		//cout<<rbegin->val<<' '<<rend->val<<endl;
    		while(rbegin->next != rend)
    		{
    			t = rbegin->next;
    			rbegin->next = t->next;
    			t->next =tstart->next;
    			tstart->next = t;
    		}
    		
    		tstart = rbegin;
    		p1 = rend;
    	}
        return ans->next;
    }
};

int main()
{
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(4);
	ListNode *t5 = new ListNode(5);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	//t4->next = t5;
	Solution *slt = new Solution();
	ListNode *result = slt->reverseKGroup(t1, 3);
	ListNode *p = result;
	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p = p->next;
	}
	
	return 0;
}
