#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
              return l2;
        if(l2 == NULL)
              return l1;
        
        ListNode *ans, *p;
        if(l1->val <= l2->val)
        {
                   ans = l1;
                   l1 = l1->next;
        }
        else if(l1->val > l2->val)
        {
             ans = l2;
             l2 = l2->next;
        }
        
        p = ans;
        while(l1!=NULL && l2!=NULL)
        {
                       if(l1->val <= l2->val)
                       {
                                  p->next = l1;
                                  l1 = l1->next;
                                  p = p->next;
                       }
                       else if(l1->val > l2->val)
                       {
                            p->next = l2;
                            l2 = l2->next;
                            p = p->next;
                       }
        }
        
        if(l1 != NULL)
        {
              p->next = l1;
        }
        else if(l2 != NULL)
        {
             p->next = l2;
        }
        
        return ans;
    }
};

int main()
{
    int x;
    ListNode *l1;
    ListNode *l2;
    ListNode *p, *result;
    Solution *slt = new Solution();
    l1 = new ListNode(5);
    l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(4);
    result = slt->mergeTwoLists(l1, l2);
    p = result;
    while(p!=NULL)
    {
                  cout<<p->val<<' ';
                  p = p->next;
    }
    cin>>x;
    return 0;
}
    
    
