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
    bool hasPathSum(TreeNode *root, int sum) {
         if(root == NULL) return false;
         return verify(root, 0, sum);
    }
    
    bool verify(TreeNode *node, int current, int sum)
    {
         int tmp;
         bool f1 = false, f2 = false;
         tmp = current + node->val;
         
         if(node->left == NULL && node->right == NULL)
         {
                       if(tmp == sum){
                              return true;
                       }
                       else return false;
         }
         
         if(node->left != NULL)
                       f1 = verify(node->left, tmp, sum);
         if(node->right != NULL)
                        f2 = verify(node->right, tmp, sum);
         return (f1 || f2);
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
    t3->left = t4;
    t3->right = t5;
    t2->left = t6;
    Solution *slt = new Solution();
    int in = 8;
    cout<<slt->hasPathSum(t1, in);
    cin>>in;
    return 0;
}
