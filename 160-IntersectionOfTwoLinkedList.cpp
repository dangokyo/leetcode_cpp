#include<iostream>
using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};  

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
             
             if(headA==NULL || headB == NULL) return NULL;
             ListNode *p = headA;
             ListNode *q = headB;
             ListNode *Atail;
             ListNode *Btail;
             
             Atail = NULL;
             Btail = NULL;
             while(p!=q)
             {
                        if(p->next == NULL) Atail = p;
                        if(q->next == NULL) Btail = q;
                        if(Atail!=NULL && Btail!=NULL && Atail!=Btail) return NULL;
                        
                        p=p->next;
                        q=q->next;
                        
                        if(p==NULL) p = headA;
                        if(q==NULL) q = headB;
             }                 
             return p;
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
    //t3->next = t6;
    
    t4->next = t5;
    t5->next = t6;
    //t6->next = t7;
    //t7->next = t8;
    Solution *slt = new Solution();
    ListNode *result = slt->getIntersectionNode(t1, t4);
    
    ListNode *p =result;
    while(p!=NULL)
    {
                  cout<<p->val<<' ';
                  p = p->next;
    }
    cout<<endl;
    
    int i;
    cin>>i;
    return 0;
}
