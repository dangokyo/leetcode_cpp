#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();
        if(length == 0) return NULL;
        else if(length == 1) return lists[0];
        
        ListNode *ans = new ListNode(0);
        ans = mergeLists(0, length-1, lists);
        return ans;
    }
    
    ListNode* mergeLists(int left, int right, vector<ListNode*>& lists)
    {
    	if(left == right) 
		{
			return lists[left];
		}
		else if(left == right -1)
		{
			return mergeTwoLists(lists[left], lists[right]);
		}
		else
		{
			int middle = (left + right)/2;
			ListNode *p1, *p2;
			p1 = mergeLists(left, middle, lists);
			p2 = mergeLists(middle+1, right, lists);
			return mergeTwoLists(p1, p2);
		}
    }
    
    ListNode* mergeTwoLists(ListNode *p1, ListNode *p2)
    {
    	ListNode *ans =  new ListNode(0);
    	ListNode *p = ans;
    	ListNode *t1 = p1;
    	ListNode *t2 = p2;
    	while(t1!=NULL && t2 != NULL)
    	{
    		if(t1->val <= t2->val)
    		{
    			p->next = t1;
    			p = p->next;
    			t1 = t1->next;
    		}
    		else if(t1->val > t2->val)
    		{
    			p->next = t2;
    			p = p->next;
				t2 = t2->next;
    		}
    	}
    	
    	if(t1 != NULL)
  		{
  			p->next = t1;
  			t1 = t1->next;
  		}  	
  		else if(t2 != NULL)
  		{
  			p->next = t2;
  			t2 = t2->next;
  		}
  		return ans->next;
    }
};

int main()
{
	Solution *slt = new Solution();
	ListNode *t1 = new ListNode(2);
	ListNode *t2 = new ListNode(4);
	ListNode *t3 = new ListNode(16);
	ListNode *t4 = new ListNode(1);
	ListNode *t5 = new ListNode(3);
	ListNode *t6 = new ListNode(5);
	ListNode *t7 = new ListNode(11);
	ListNode *t8 = new ListNode(13);
	ListNode *t9 = new ListNode(15);
	t1->next = t2;
	t2->next = t3;
	t4->next = t5;
	t5->next = t6;
	t7->next = t8;
	t8->next = t9;
	vector<ListNode*> in;
	in.push_back(t1);
	in.push_back(t4);
	in.push_back(t7);
	ListNode *p = slt->mergeKLists(in);
	while(p!=NULL)
	{
		cout<<p->val<<' ';
		p = p->next;
	}
	return 0;
}
