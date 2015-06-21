#include<iostream>

using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
             if(head == NULL) return head;
             
             ListNode *p1, *p2;
             p1 = head;
             p2 = p1->next;
             
             if(p1!=NULL and p2!=NULL)
             {
                         p1->next = p2->next;
                         p2->next = p1;
                         head = p2;
             }
             else
             {
                 return head;
             }
             
             p2 = p2->next;
             p1 = p1->next;
             while(p1!=NULL && p2!=NULL && p1->next !=NULL)
             {
                            p2->next = p1->next;
                            p1->next = p1->next->next;
                            p2->next->next = p1;
                            p1 = p1->next;
                            p2 = p2->next->next;
             }
             return head;
    }
};

int main()
{
    Solution *slt = new Solution();
    ListNode *l1= new ListNode(1);
    ListNode *l2= new ListNode(2);
    ListNode *l3= new ListNode(3);
    ListNode *l4= new ListNode(4);
    ListNode *l5= new ListNode(5);
    ListNode *head = l1, *p;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    int x;
    p=head;
    while(p!=NULL)
    {
                  cout<<p->val<<endl;
                  p = p->next;
    }
    p = head;
    p = slt->swapPairs(p);
    while(p!=NULL)
    {
                  cout<<p->val<<endl;
                  p = p->next;
    }
    cin>>x;
    return 0;
}
