#include<iostream>
using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
         int length = 0;
         int count;
         ListNode *p, *q;
         p = head;
         while(p!=NULL)
         {
                       length++;
                       p=p->next;
         }
         if(length <=2 ) return;
         
         ListNode *midh = head;
         ListNode *mide;
         count = 0;
         while(count < (length - 1)/2 )
         {
                     midh = midh->next;
                     count++;
         }
         
         mide = midh->next;
         midh->next = NULL;
         midh =mide;
         while(mide->next!=NULL)
         {
                                p = mide->next;
                                mide->next = p->next;
                                p->next = midh;
                                midh = p;
         }
         
         p = head;
         while(midh!=NULL)
         {
                          q = midh;
                          midh = midh->next;
                          q->next = p->next;
                          p->next = q;
                          p = q->next;
         }
         return;
    }
};

int main()
{
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(3);
    ListNode *t4 = new ListNode(4);
    ListNode *t5 = new ListNode(5);
    ListNode *t6 = new ListNode(6);
    ListNode *t7 = new ListNode(7);
    ListNode *t8 = new ListNode(8);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = t7;
    t7->next = t8;
    
    Solution *slt = new Solution();
    slt->reorderList(t1);
    int count = 0;
    while(t1!=NULL)
    {
                   cout<<t1->val<<' ';
                   t1 = t1->next;
                   count++;
    }
    int i;
    cin>>i;
    return 0;
}
