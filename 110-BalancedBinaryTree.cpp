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
    bool isBalanced(TreeNode *root) {
         if(root == NULL) return true;
        int left_height, right_height;
        if(verify(root->left, left_height) && verify(root->right, right_height))
        {
                                 int dif = abs(left_height - right_height);
                                 if(dif <= 1)
                                 {
                                        return true;
                                 }
                                 else return false;
        }
        else return false;
    }
    
    bool verify(TreeNode *node, int &height)
    {
         if(node == NULL)
         {
                 height = 0;
                 return true;
         }
         
         int l_height, r_height;
         if( verify(node->left, l_height) && verify(node->right, r_height) )
         {
             int dif = abs(l_height - r_height);
             if(dif <= 1)
             {
                    if(l_height >= r_height)
                    {
                                height = 1 + l_height;
                    }
                    else height = 1 + r_height;
                    return true;
             }
             else return false;
         }
         else return false;  
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
    //t2->left = t6;*/
    Solution *slt = new Solution();
    cout<<slt->isBalanced(t1)<<endl;
    int i;
    cin>>i;
    return 0;
}
