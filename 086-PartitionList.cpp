#include<iostream>

using namespace std;
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
             ListNode *start, *mid, *end;
             ListNode *ps, *pm, *pe, *p;
             if(head == NULL) return head;
             p = head;
             start = NULL;
             end = NULL;
             ps = NULL;
             pe = NULL;
             while(p!=NULL)
             {
                           if(p->val < x)
                           {
                                     if(ps == NULL)
                                     {
                                           ps = p;
                                           start = ps;
                                     }
                                     else{
                                          ps->next = p;
                                          ps = ps->next;
                                     }
                           }
                           else
                           {
                                     if(pe == NULL)
                                     {
                                           pe = p;
                                           end = pe;
                                     }
                                     else{
                                          pe->next = p;
                                          pe = pe->next;
                                     }
                           }
                           p = p->next;
             }
             
             if(start ==NULL  && end == NULL)
             {        
                      return start;
             }
             else if(start != NULL && end == NULL)
             {
                  ps->next = NULL;
                  return start;
             }
             else if(start != NULL && end !=NULL)
             {
                  ps->next = end;
                  pe->next = NULL;
                  return start;
             }
             else if(start == NULL && end != NULL)
             {
                  pe->next =NULL;
                  return end;
             }
    }
};

int main()
{
    ListNode *head = new ListNode(2);
    ListNode *t1 = new ListNode(1);
    /*ListNode *t2 = new ListNode(5);
    ListNode *t3 = new ListNode(5);
    ListNode *t4 = new ListNode(12);
    ListNode *t5 = new ListNode(4);
    ListNode *t6 = new ListNode(16);*/
    int in;
    in = 1;
    head->next = t1;
    /*t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;*/
    Solution *slt = new Solution();
    ListNode *result = slt->partition(head, in);
    ListNode *p = result;
    while(p!=NULL)
    {
                  cout<<p->val<<endl;
                  p = p->next;
    }
    cin>>in;
    return 0;
}
    
