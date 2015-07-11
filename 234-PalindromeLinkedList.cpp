#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;
        
        ListNode *p = head;
        ListNode *t1, *t2;
        int length=0, counter = 0;
        int len;
        while(p!=NULL){
                       length++;
                       p = p->next;               
        }
        if(length == 1)return true;
        if(length % 2 == 1){
                  len = length/2 + 1;          
        }
        else {
             len = length/2;
        }
        p = head;
        while(counter < len){
                     p = p->next;
                     counter++;
        }
        if(p->next !=NULL){
                   t1 = p;
                   p = p->next;
                   t1->next = NULL;
                   if(p->next != NULL){
                                     t2 = p->next;
                                     while(t2 != NULL){
                                              p->next = t1;
                                              t1 = p;
                                              p = t2;
                                              t2 = p->next;
                                     }    
                   }                        
                   p->next = t1;      
        }
        t1 = head;
        for(int i=0; i<length/2; i++)
        {
                if(t1->val != p->val) 
                {
                           return false;
                }
                else {
                     t1 = t1->next;
                     p = p->next;
                }
        }
        return true;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(0);
    ListNode *l6 = new ListNode(2);
    ListNode *l7 = new ListNode(2);
    ListNode *l8 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    Solution *slt = new Solution();
    cout<<slt->isPalindrome(l1);
    getchar();
    return 0;
}
