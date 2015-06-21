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
    int maxPathSum(TreeNode *root) {
        int ans;
        int tmp = INT_MIN;
        if(root == NULL) return 0;
        ans = maxPathSumSolver(root, tmp);
        return ans;
    }
    
    int maxPathSumSolver(TreeNode *node, int &side) // return the maximum value of the tree (node as root), side store one-side maximum
    {
        int lt, rt;
        int lside, rside;
        int ans;
        if(node == NULL)
        {
                side = -1000000;
                return -1000000;
        }
        ans = node->val;
        lt = maxPathSumSolver(node->left, lside);
        rt = maxPathSumSolver(node->right, rside);
        cout<<ans<<' '<<lt<<' '<<rt<<' '<<lside<<' '<<rside<<endl;
        if(lside > 0) ans += lside;
        if(rside > 0) ans += rside;
        side = max(node->val, max(node-> val + lside, node->val + rside));
        ans = max(ans, max(lt, rt));
        return ans;
    }
};


int main()
{
    //TreeNode *t = new TreeNode(-3);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(-1);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t1->left =t2;
    //t1->right = t3;
    //t2->left= t4;
    //t2->right = t5;
    Solution *slt = new Solution();
    
    cout<<slt->maxPathSum(t1);
    int i;
    cin>>i;
    return 0;
}
