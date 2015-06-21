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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
                       vector<vector<int> > ans, t;
                       vector<TreeNode* > level, tmp;
                       if(root== NULL) return ans;
                       level.push_back(root);
                       int i;
                       while(level.size()!=0)
                       {
                                             vector<int> sol;
                                             for(i=0; i<level.size(); i++)
                                             {
                                                          sol.push_back(level[i]->val);
                                                          if(level[i]->left != NULL) tmp.push_back(level[i]->left);
                                                          if(level[i]->right != NULL) tmp.push_back(level[i]->right);
                                             }
                                             ans.push_back(sol);
                                             level = tmp;
                                             tmp.clear();
                       }
                       t = ans;
                       ans.clear();
                       for(i=t.size()-1; i>=0; i--)
                       {
                                         ans.push_back(t[i]);
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
    t4->right = t5;
    t2->left = t6;
    Solution *slt = new Solution();
    int i, j;
    vector<vector<int> > result;
    result = slt->levelOrderBottom(t1);
    for(i=0; i<result.size(); i++)
    {
             for(j=0; j<result[i].size(); j++)
             {
                      cout<<result[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>i;
    return 0;
}
