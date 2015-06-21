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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
                       vector<vector<int> > ans;
                       vector<int> sol;
                       if(root == NULL) return ans;
                       pathSolver(root, 0, sum, sol, ans);
                       return ans;
    }
    
    void pathSolver(TreeNode* node, int cur, int sum, vector<int> sol, vector<vector<int> > &ans)
    {
         int tmp = cur + node->val;
         sol.push_back(node->val);
         if(node->left == NULL && node->right == NULL)
         {
                       if(tmp == sum){
                              ans.push_back(sol);
                              return;
                       }
                       else return;
         }
         
         if(node->left!=NULL) pathSolver(node->left, tmp, sum, sol, ans);
         if(node->right!=NULL) pathSolver(node->right, tmp, sum, sol, ans);
         return;
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
    int in = 9;
    int i, j;
    vector<vector<int> > result;
    result = slt->pathSum(t1, in);
    for(i=0; i<result.size(); i++)
    {
             for(j=0; j<result[i].size(); j++)
             {
                      cout<<result[i][j]<<' ';
             }
             cout<<endl;
    }
    cin>>in;
    return 0;
}
