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
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL || head->next==NULL) return head;
    	ListNode *end = head;
    	ListNode *t;
    	vector<ListNode*> vec; 
    	int i;
    	int length;
		while(end!=NULL) 
		{
			vec.push_back(end);
			end = end->next;
		}
		length = vec.size();
		for(i=length-1; i>=0; i--)
		{
			if(i>0)
			{
				vec[i]->next = vec[i-1];
			}
			else if(i==0)
			{
				vec[i]->next = NULL;
			}
		}
        return vec[length-1];
    }
};

int main()
{
	
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
	ListNode *l6 = new ListNode(6);
	ListNode *l7 = new ListNode(7);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	Solution *slt = new Solution();
	ListNode *p;
	
	p = slt->reverseList(l1);
	int count = 0;
	while(p!=NULL && count<=10)
	{
		cout<<p->val<<' ';
		p = p->next;
		count++;
	}
	cin>>count;
	return 0;
}
