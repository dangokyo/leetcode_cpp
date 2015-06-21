#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
       TreeNode *cur;
       stack<TreeNode*> nodeStack;
       
       BSTIterator(TreeNode *root) {
                            cur = root;
       }

       /** @return whether we have a next smallest number */
       bool hasNext() {
            return (cur!=NULL || !nodeStack.empty());
       }

       /** @return the next smallest number */
       int next() {
           while(cur!=NULL)
           {
                                 nodeStack.push(cur);
                                 cur = cur->left;
           }
           cur = nodeStack.top();
           nodeStack.pop();
           int ans = cur->val;
           cur = cur->right;
           return ans;
       }
};


int main()
{
    TreeNode *t1 = new TreeNode(1);
    BSTIterator iter(t1);
    return 0;
}
