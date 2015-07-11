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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode* > path1, path2;
        TreeNode *t, *ans;
        t = root;
        while(true){
                    //cout<<"path1:"<<t->val<<endl;
                    if(t == NULL) break;
                    if(t->val == p->val){
                              path1.push_back(t);
                              break;          
                    }            
                    else if(t->val < p->val){
                         path1.push_back(t);
                         t = t->right;
                    }
                    else if(t->val > p->val){
                         path1.push_back(t);
                         t = t->left;
                    }
        }
        
        t = root;
        while(true){
                    //cout<<"path2:"<<t->val<<endl;
                    if(t == NULL)
                         break;
                    if(t->val == q->val){
                              path2.push_back(t);
                              break;          
                    }            
                    else if(t->val < q->val){
                         path2.push_back(t);
                         t = t->right;
                    }
                    else if(t->val > q->val){
                         path2.push_back(t);
                         t = t->left;
                    }
        }
        for(int i=0; i<path1.size() && i<path2.size(); i++){
                if(path1[i]->val == path2[i]->val){
                                 ans = path1[i];
                }        
                else {
                     break;
                }
        }
        return ans;
    }
};

int main()
{
    TreeNode *t1 = new TreeNode(6);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(8);
    TreeNode *t4 = new TreeNode(0);
    TreeNode *t5 = new TreeNode(4);
    TreeNode *t6 = new TreeNode(7);
    TreeNode *t7 = new TreeNode(9);
    TreeNode *t8 = new TreeNode(3);
    TreeNode *t9 = new TreeNode(5);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    t5->left = t8;
    t5->right = t9;
    Solution *slt = new Solution();
    TreeNode *r = slt->lowestCommonAncestor(t1, t4, t8);
    cout<<r->val<<endl;
    getchar();
    return 0;
}
