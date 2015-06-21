#include<iostream>
#include<iomanip>

using namespace std;

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
         bool ans;
         if(root == NULL) return true;
         int cur = root->val;
         ans = verify(root->left, (double)INT_MIN-1, cur) && verify(root->right, cur, (double)INT_MAX+1);
         return ans;
    }
    
    bool verify(TreeNode *node, double l, double r)
    {
         if(node == NULL) return true;
         int value = node->val;
         
         if(value < r && value > l &&verify(node->left, l, value) && verify(node->right, value, r))
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
    cout<<setprecision(11);
    TreeNode *t1 = new TreeNode(2147483647);
    TreeNode *t2 = new TreeNode(-2147483648);
    TreeNode *t3 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(7);
    Solution *slt = new Solution();
    t1->left = t2;
    //t1->right = t3;
    //t2->right = t4;
    //t3->left = t5;
    cout<<slt->isValidBST(t1);
    int i;
    cin>>i;
    return 0;
}
