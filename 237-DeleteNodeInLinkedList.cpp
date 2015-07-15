#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
         ListNode *t = node;
         while(true){
                     t->val = t->next->val;
                     if(t->next->next == NULL){
                                      t->next = NULL;
                                      break;                             
                     }
                     else{
                          t= t->next;     
                     }
         }
         return;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution *slt = new Solution();
    slt->deleteNode(l3);
    ListNode *p = l1;
    while(p!=NULL){
                   cout<<p->val<<' ';
                   p = p->next;
    }
    getchar();
    return 0;
}
