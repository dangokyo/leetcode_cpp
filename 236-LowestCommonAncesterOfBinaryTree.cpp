#include<iostream>
#include<map>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              map<TreeNode*, TreeNode*> nodeMap;
              nodeMap[root] = NULL;
              traverseTree(root, nodeMap);
              stack<TreeNode*> pStack, qStack;
              TreeNode *t, *ans;
              t= p;
              while(t!=NULL){
                             pStack.push(t);
                             t = nodeMap[t];               
              }
              t = q;
              while(t!=NULL){
                             qStack.push(t);
                             t = nodeMap[t];
              }
              while(!pStack.empty() && !qStack.empty()){
                                    if(pStack.top() == qStack.top()){
                                                    ans = pStack.top();
                                                    pStack.pop();
                                                    qStack.pop();               
                                    }      
                                    else break;
                                    
              }
              return ans;
    }
    
    void traverseTree(TreeNode* node, map<TreeNode*, TreeNode*>& map)
    {
        if(node == NULL) return;
        
        if(node->left != NULL) 
        {
                      map[node->left] = node;
                      traverseTree(node->left, map);
        }
        if(node->right != NULL)
        {
                       map[node->right] = node;
                       traverseTree(node->right, map);
        }
        return;    
    }
};

int main()
{
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(2);
    TreeNode *t6 = new TreeNode(0);
    TreeNode *t7 = new TreeNode(8);
    TreeNode *t8 = new TreeNode(7);
    TreeNode *t9 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    t5->left = t8;
    t5->right = t9;
    Solution *slt = new Solution();
    cout<<slt->lowestCommonAncestor(t1, t5, t8)->val<<endl;
    getchar();
    return 0;
}
