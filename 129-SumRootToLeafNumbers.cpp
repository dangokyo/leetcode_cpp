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
    int sumNumbers(TreeNode *root) {
        int ans = 0;
        if(root == NULL) return ans;
        int sum = 0;
        sumSolver(root, ans, sum);
        return ans;
    }
    
    void sumSolver(TreeNode *node, int &ans, int sum)
    {
         int tmp;
         if(node->left == NULL && node->right == NULL) ans += sum * 10 + node->val;
         if(node->left != NULL)
         {
                       tmp = sum * 10 + node->val;
                       sumSolver(node->left, ans, tmp);
         }
         
         if(node->right != NULL)
         {
                        tmp = sum*10 + node->val;
                        sumSolver(node->right, ans, tmp);
         }             
    }
};

int main()
{
    Solution *slt = new Solution();
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left=t2;
    t1->right= t3;
    
    cout<<slt->sumNumbers(t1);
    int i;
    cin>>i;
    return 0;
}
