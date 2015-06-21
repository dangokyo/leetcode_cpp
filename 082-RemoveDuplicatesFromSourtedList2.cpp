#include<iostream>

using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
             ListNode *p, *t;
             p = head;
             int tmp;
             //Locate head;
             while(p!=NULL)
             {
                           if(p->next == NULL)
                           {
                                      head = p;
                                      break;
                           }
                           
                           if(p->next->val == p->val)
                           {
                                           if(p->next->next == NULL){
                                                            head = NULL;
                                                            break;
                                           }
                                           else if(p->next->next->val == p->next->val){
                                                p = p->next;
                                           }
                                           else if(p->next->next->val != p->next->val){
                                                p = p->next->next;
                                           }
                           }
                           else{
                                head = p;
                                break;
                           }
                                                            
             }
             //return head;
             p = head;
             while(p!=NULL)
             {
                           if(p->next == NULL){
                                      break;
                           }
                           
                           t = p->next;
                           if(t->next == NULL){
                                      break;
                           }
                           if(t->next->val != t->val)
                           {
                                           p = t;
                           }
                           else if(t->next->val == t->val)
                           {
                                tmp = t->val;
                                while(t!=NULL && t->val == tmp)
                                {
                                              t = t->next;
                                }
                                p->next = t;
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
    ListNode *t3 = new ListNode(3);
    ListNode *t4 = new ListNode(4);
    ListNode *t5 = new ListNode(4);
    ListNode *t6 = new ListNode(5);
    ListNode *t7 = new ListNode(6);
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = t7;
    Solution *slt = new Solution();
    ListNode *result = slt->deleteDuplicates(head);
    ListNode *p = result;
    while(p!=NULL)
    {
                  cout<<p->val<<endl;
                  p = p->next;
    }
    int i;
    cin>>i;
    return 0;
}
