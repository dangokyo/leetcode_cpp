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
    int minDepth(TreeNode *root) {
        int l_min, r_min;
        int ans;
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right == NULL) 
        {
                      return 1;
        }
        else if(root->left!=NULL && root->right != NULL)
        {
             l_min = minDepth(root->left);
             r_min = minDepth(root->right);
             if(l_min <= r_min)
             {
                      ans = l_min + 1;
             }
             else ans = r_min + 1;
        }
        else if(root->left!=NULL && root->right == NULL)
        {
             ans = minDepth(root->left) + 1;
        }
        else if(root->left == NULL && root->right != NULL)
        {
             ans = minDepth(root->right) + 1;
        }
        return ans;
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
    t4->right = t5;
    t2->left = t6;
    Solution *slt = new Solution();
    cout<<slt->minDepth(t1)<<endl;
    int i;
    cin>>i;
    return 0;
}
