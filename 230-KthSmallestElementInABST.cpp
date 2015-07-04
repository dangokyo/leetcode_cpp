#include<iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        if(root->left == NULL && root->right == NULL)
                      return root->val;
        
        stack<TreeNode*> myStack;
        TreeNode *p = root;
        TreeNode *cur;
        int counter = k;
        while(p!=NULL){
                       myStack.push(p);
                       p = p->left;               
        }
        while(counter > 1){
                      cur = myStack.top();
                      //p = myStack.top();
                      //cout<<"processing:"<<p->val<<endl;
                      if(cur->right == NULL){
                                    myStack.pop();
                                    cur = myStack.top();
                                    counter--;              
                      }
                      else {
                           p = cur->right;
                           myStack.pop();
                           counter--;
                           while(p!=NULL){
                                          myStack.push(p);
                                          p = p->left;             
                           }    
                      }
        }
        p = myStack.top();
        return p->val;
    }
};

int main()
{
    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(6);
    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(8);
    TreeNode *t6 = new TreeNode(9);
    TreeNode *t7 = new TreeNode(10);
    TreeNode *t8 = new TreeNode(11);
    TreeNode *t9 = new TreeNode(12);
    
    t6->left = t3;
    t6->right = t8;
    t3->left = t1;
    t3->right = t4;
    t1->right = t2;
    t4->right = t5;
    t8->left = t7;
    t8->right = t9;
    Solution *slt = new Solution();
    cout<<slt->kthSmallest(t6, 5)<<endl;
    getchar();
    return 0;
}
