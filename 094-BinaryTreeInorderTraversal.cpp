#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
       vector<int> inorderTraversal(TreeNode *root) 
       {
                   vector<int> ans;
                   inTraversal(root, ans);
                   return ans;
       }
    
       void inTraversal(TreeNode *node, vector<int> &ans)
       {
            if(node == NULL)
            {
                    return;
            }
            else
            {
                inTraversal(node->left, ans);
                ans.push_back(node->val);
                inTraversal(node->right, ans);
            }
       }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(5);
    root->left = t1;
    root->right = t2;
    t2->left = t3;
    t3->right =t4;
    vector<int> result;
    Solution *slt = new Solution();
    result = slt->inorderTraversal(root);
    int i;
    for(i=0; i< result.size();i++)
    {
             cout<<result[i]<<' ';
    }
    cin>>i;
    return 0;
}
    
