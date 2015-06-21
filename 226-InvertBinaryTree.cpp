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
    TreeNode* invertTree(TreeNode* root) {
              if(root==NULL) return NULL;
              TreeNode *left = invertTree(root->left);
              TreeNode *right = invertTree(root->right);
              root->left = right;
              root->right = left; 
              return root;
    }
};

int Display(TreeNode* t)
{
    if(t==NULL) return 0;
    
    cout<<t->val<<endl;
    Display(t->left);
    Display(t->right);
    return 0;
}

int main()
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(7);
    
    
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    Solution *slt = new Solution();
    Display(t1);
    TreeNode *t = slt->invertTree(t1);
    cout<<endl;
    Display(t);
    getchar();
    return 0;
}
