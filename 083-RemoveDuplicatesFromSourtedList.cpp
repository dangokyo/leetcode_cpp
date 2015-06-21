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
    ListNode *deleteDuplicates(ListNode *head) {
             ListNode *t = head;
             ListNode *cur;
             int tmp;
             while(t!=NULL)
             {
                           tmp = t->val;
                           if(t->next == NULL)
                           {
                                      break;
                           }
                           else
                           {
                               cur = t ->next;
                               while(cur != NULL)
                               {
                                         if(cur->val == tmp)
                                         {
                                                     cur = cur->next;
                                                     continue;
                                         }
                                         else if(cur->val != tmp)
                                         {
                                              t->next = cur;
                                              t = t->next;
                                              break;
                                         }
                               }
                               if(cur== NULL)
                               {
                                        t->next = cur;
                                        break;
                               }
                           }
             }
             return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(2);
    ListNode *t4 = new ListNode(3);
    ListNode *t5 = new ListNode(3);
    ListNode *t6 = new ListNode(3);
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
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
