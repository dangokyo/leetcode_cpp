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
        
    }
};

int main()
{
    ListNode *t1 = new ListNode(4);
    ListNode *t2 = new ListNode(3);
    ListNode *t3 = new ListNode(1);
    ListNode *t4 = new ListNode(2);
    ListNode *t5 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    Solution *slt = new Solution();
    ListNode *t = slt->insertionSortList(t1);
    ListNode *p = t;
    while(p!=NULL)
    {
                  cout<<p->val<<' ';
                  p = p->next;
    }
    int i;
    cin>>i;
    return 0;
}
