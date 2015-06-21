#include<iostream>

using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(head == NULL) return false;
         ListNode *one_step, *two_step;
         one_step = head;
         two_step = head;
         do
         {
                        one_step = one_step->next;
                        two_step = two_step->next;
                        if(two_step == NULL)
                        {
                                    return false;
                        }
                        else
                        {
                            two_step = two_step->next;
                        }
         }while(one_step != two_step && one_step!= NULL && two_step!=NULL);
         if(one_step == two_step)
         {
                     return true;
         }
         else
         {
             return false;
         }
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
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = t7;
    t7->next = t3;
    
    Solution *slt = new Solution();
    cout<<slt->hasCycle(t1)<<endl;
    int i;
    cin>>i;
    return 0;
}
