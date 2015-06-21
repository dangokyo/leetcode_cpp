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
    int maxDepth(TreeNode *root) {
        if(root == NULL)  return 0;
        int l, r;
        l = maxDepth(root->left) + 1;
        r = maxDepth(root->right) + 1;
        if(l>=r)
        {
                return l;
        }
        else return r;
        
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
    cout<<slt->maxDepth(t1)<<endl;
    int i;
    cin>>i;
    return 0;
}
