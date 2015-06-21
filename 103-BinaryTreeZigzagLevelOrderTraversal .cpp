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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
                       vector<vector<int> > ans;
                       if(root == NULL) return ans;
                       int dir = 0, i;  //0 from left to right, 1 from right to left
                       vector<TreeNode*> level, tmp;
                       level.push_back(root);
                       while(level.size()!=0)
                       {
                                             vector<int> sol;
                                             if(dir == 0)
                                             {
                                                    for(i=0; i<level.size(); i++)
                                                    {
                                                             sol.push_back(level[i]->val);
                                                             if(level[i]->left != NULL) tmp.push_back(level[i]->left);
                                                             if(level[i]->right != NULL) tmp.push_back(level[i]->right);      
                                                    }
                                             }
                                             else if(dir == 1)
                                             {
                                                    for(i=0; i<level.size(); i++)
                                                    {
                                                             sol.push_back(level[level.size()-1-i]->val);
                                                             if(level[i]->left != NULL) tmp.push_back(level[i]->left);
                                                             if(level[i]->right != NULL) tmp.push_back(level[i]->right);      
                                                    }
                                                  
                                             }
                                             ans.push_back(sol);
                                             level = tmp;
                                             tmp.clear();
                                             dir = 1 - dir;
                       }
                       return ans;
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
    t3->right = t5;
    t2->left = t6;
    Solution *slt = new Solution();
    vector<vector<int> > result;
    result = slt->zigzagLevelOrder(t1);
    
    int i, j;
    cout<<result.size()<<endl;
    for(i=0; i<result.size(); i++)
    {
             for(j=0; j<result[i].size(); j++)
             {
                      cout<<result[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>i;
}
    
