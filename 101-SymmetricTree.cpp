#include<iostream>

using namespace std;

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
         if(root == NULL) 
         {
                 return true;
         }
         else
             return SymmetricTree(root->left, root->right);
         
    }
    
    bool SymmetricTree(TreeNode *p, TreeNode *q)
    {
         if(p == NULL && q == NULL)
         {
              return true;
         }
         else if((p == NULL && q != NULL) || (p != NULL && q == NULL))
         {
              return false;
         }
         else if(p != NULL && q != NULL)
         {
              if(p->val == q->val)
              {
                        return SymmetricTree(p->left, q->right) && SymmetricTree(p->right, q->left);
              }
              else return false;
         }
    }
};

int main()
{
    
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(1);
    TreeNode *t5 = new TreeNode(2);
    TreeNode *t6 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    Solution *slt = new Solution();
    t4->left = t5;
    t4->right = t6;
    cout<<slt->isSymmetric(t1);
    int i;
    cin>>i;
    return 0;
}
    
