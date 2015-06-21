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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p;
        ListNode *q;
        int count = 0;
        int i = 0;
        p = head;
        
        while(p!=NULL)
        {
            p = p->next;
            count++;
        }
        cout<<count<<endl;
        
        if(count ==n)
        {
            head = head->next;
            return head;
        }
        
        p = head;
        while(i < count-n-1)
        {
            p = p->next;
            i++;
        }
        q = p;
        p = p->next;
        cout<<"here"<<endl;
        q->next = p->next;
        delete p;
        
        return head;
    }
};

int main()
{
    Solution *slt = new Solution();
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *p, *q;
    
    q = slt->removeNthFromEnd(head, 1);
    //p = head;
    while(q!=NULL)
    {
                  cout<<q->val<<endl;
                  q = q->next;
    }
    
    
    char x;
    cin>>x;
    return 0;
}
