#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
             vector<int> num;
             ListNode *p = head;
             TreeNode *node;
             while(p != NULL)
             {
                     num.push_back(p->val);
                     p=p->next;
             }
             int length = num.size();
             if(length == 0) return NULL;
             node = BuildArrayToBST(num, 0, length-1);
             return node;
    }
    
    
    TreeNode *BuildArrayToBST(vector<int> &num, int start, int end)
    {
             if(start > end) return NULL;
             int mid = (end - start) / 2 + start;
             TreeNode *node = new TreeNode(num[mid]);
             TreeNode *leftTree = BuildArrayToBST(num, start, mid-1);
             TreeNode *rightTree = BuildArrayToBST(num, mid+1, end);
             node->left = leftTree;
             node->right = rightTree;
             return node;
    }
             
};

int main()
{
    TreeNode *root;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    
    Solution *slt = new Solution();
    root = slt->sortedListToBST(l1);
    int i;
    cin>>i;
    return 0;
}
