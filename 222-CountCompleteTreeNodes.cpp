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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root != NULL && root->left == NULL && root->right == NULL) return 1;
        int base;
        int ans = 0;
        int height = 0;
        int cur_height;
        TreeNode *p = root;
        TreeNode *p1, *p2;
        while(p != NULL)
        {
                height++;
                p = p->left;
        }
        base = (1<<(height-1)) - 1;
        
        p = root;
        cur_height = 1;
        while(cur_height <= height-1)
        {
                         //cout<<cur_height<<endl;
                         p1 = p->left;
                         p2 = p->right;
                         if(cur_height == height-1)
                         {
                                    if(p1 != NULL && p2 != NULL)
                                    {
                                          ans += 2;
                                    }
                                    else if(p1 != NULL && p2 == NULL)
                                    {
                                         ans += 1;
                                    }
                                    break;   
                         }
                         else if(cur_height < height-1)
                         {
                              while(p1!=NULL && p2 != NULL)
                              {
                                             p1 = p1->left;
                                             p2 = p2->left;
                              }
                              if(p1 == NULL && p2 == NULL)
                              {
                                    ans = (ans + 1)<<1;
                                    cur_height++;
                                    p = p->right;
                              }
                              else if(p1 != NULL && p2 == NULL)
                              {
                                   ans = ans<<1;
                                   cur_height++;
                                   p = p->left;
                              }            
                         }
        }
        return base + ans;
    }
};

int main()
{
    TreeNode *t0 = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(6);
    TreeNode *t6 = new TreeNode(7);
    TreeNode *t7 = new TreeNode(8);
    TreeNode *t8 = new TreeNode(8);
    TreeNode *t9 = new TreeNode(9);
    TreeNode *t10 = new TreeNode(10);
    t0->left = t1;
    t0->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;
    t3->left = t7;
    t3->right = t8;
    t4->left = t9;
    t4->right = t10;
    Solution *slt= new Solution();
    cout<<slt->countNodes(t0)<<endl;
    getchar();
    return 0;
}
