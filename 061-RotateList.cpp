#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
       ListNode *rotateRight(ListNode *head, int k) { 
                if(head == NULL || k ==0) return head;  
                int len =1;  
                ListNode* p = head,*pre;  
                while(p->next!=NULL)  
                {  
                   p = p->next;  
                   len++;      
                }  
                k = len-k%len;  
                p->next = head;  
                int step =0;  
                while(step< k)  
                {  
                   p = p->next;  
                   step++;  
                }  
                head = p->next;  
                p->next = NULL;  
                return head;  
       }  
};   

int main()
{
    ListNode *head =  new ListNode(0);
    ListNode *l1 = new ListNode(1);
    /*ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);*/
    ListNode *result, *p;
    Solution *slt = new Solution();
    int in =3;
    head->next = l1;
    /*head->next->next = l2;
    head->next->next->next = l3;
    head->next->next->next->next = l4;
    head->next->next->next->next->next = l5;*/
    result = slt->rotateRight(head, in);
    p = result;
    while(p!=NULL)
    {
                  cout<<p->val<<' '<<endl;
                  p = p->next;
    }
    
    cin>>in;
    
    return 0;
}
