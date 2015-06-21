// 2Add2Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

		ListNode *ans = NULL;
		ListNode *tmp = NULL;
		ListNode *cur = NULL;

		if (l1 == NULL)  
        {  
            return l2;  
        }  
        if (l2 == NULL)  
        {  
            return l1;  
        }

		int sum, carry;
		carry = 0;
		while(l1 != NULL && l2 != NULL)
		{
			sum = l1->val + l2->val + carry;
			carry = sum / 10;

			if(carry == 0)
			{
				tmp = new ListNode(sum);
			}
			else if(carry != 0)
			{
				tmp = new ListNode(sum - 10 * carry);
			}

			if(ans == NULL)
			{
				ans = tmp;
				cur = ans;
			}
			else
			{
				cur->next = tmp;
				cur = cur->next;
			}
			l1 = l1->next;
			l2 = l2->next;

			if(l1 == NULL && l2 != NULL)
			{
				l1 = new ListNode(0);
			}
			else if(l1 != NULL && l2 == NULL)
			{
				l2 = new ListNode(0);
			}
		} 
		if(carry != 0)
		{
			cur->next = new ListNode(carry);
		}

		return ans;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *l1, *l2, *result;
	Solution *slt = new Solution();
	char x;
	/*l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);*/
	l1 = new ListNode(1);
	l2 = new ListNode(9);
	l1->next = new ListNode(9);

	result = slt->addTwoNumbers(l1, l2);
	while(result != NULL)
	{
		cout<< result->val<<endl;
		result = result->next;
	}
	cin>>x;
	return 0;
}

