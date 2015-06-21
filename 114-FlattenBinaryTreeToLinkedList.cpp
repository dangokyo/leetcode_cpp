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
    void flatten(TreeNode *root) {
         TreeNode *t = root;
         TreeNode *flattedSubTree;
         TreeNode *rightEndNode;
         while(t!=NULL)
         {
                       if(t->left != NULL)
                       {
                                  //cout<<t->val<<endl;
                                  flatten(t->left);
                                  flattedSubTree = t->left;
                                  rightEndNode = getLeftMostNode(flattedSubTree);
                                  rightEndNode->right = t->right;
                                  t->right = flattedSubTree;
                                  t->left = NULL;
                                  t = t->right;
                       }
                       else
                       {
                           //cout<<t->val<<endl;
                           t = t->right;
                       }
         }
         return;
    }
             
    
    TreeNode *getLeftMostNode(TreeNode *node)
    {
             TreeNode *t = node;
             while(t->right!=NULL)
             {
                                  t = t->right;
             }
             return t;
    }
};

int main()
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->right = t6;
    Solution *slt = new Solution();
    slt->flatten(t1);
    TreeNode *t = t1;
    while(t!=NULL)
    {
                   cout<<t->val<<' ';
                   t = t->right;
    }
    cout<<endl;
    int i;
    cin>>i;
    return 0;
}
    
