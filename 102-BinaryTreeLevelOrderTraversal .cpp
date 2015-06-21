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
    vector<vector<int> > levelOrder(TreeNode *root) {
                       vector<vector<int> > ans;
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
                       return ans;
        
    }
};

int main()
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    Solution *slt = new Solution();
    vector<vector<int> > result;
    result = slt->levelOrder(t1);
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
    return 0;
}
