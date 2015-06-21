#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
                TreeNode *cur = root;
                TreeNode *curNode = NULL;
                stack<TreeNode*> myStack;
                vector<int> ans;
                while(cur!=NULL || !myStack.empty())
                {
                                while(cur!=NULL)
                                {
                                                myStack.push(cur);
                                                cur = cur->left;
                                }
                                cur = myStack.top();
                                
                                if(cur->right == NULL || cur->right == curNode)
                                {
                                              myStack.pop();
                                              ans.push_back(cur->val);
                                              curNode = cur;
                                              cur=NULL;
                                              
                                }
                                else cur = cur->right;
                }
                return ans;
    }
};

int main()
{
    vector<int> result;
    Solution *slt = new Solution();
    TreeNode *t1 = new TreeNode(1);
    result = slt->postorderTraversal(t1);
    for(int i=0; i<result.size(); i++) cout<<result[i]<<' ';
    getchar();
    return 0;
}
