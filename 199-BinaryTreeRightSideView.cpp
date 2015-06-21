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
    vector<int> rightSideView(TreeNode* root) {
                vector<int> ans;
                if(root==NULL) return ans;
                SideViewSolver(ans, 1, root);
                return ans;
    }
    
    int SideViewSolver(vector<int> &vec, int level, TreeNode *t)
    {
        if(t==NULL) return 0;
        if(level>vec.size())
        {
                            vec.push_back(t->val);
        }
        SideViewSolver(vec, level+1, t->right);
        SideViewSolver(vec, level+1, t->left);
        return 0;
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
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(8);
    TreeNode *t9 = new TreeNode(9);
    /*t1->left = t2;
    t1->right = t3;
    t2->right = t5;
    t3->right = t4;
    t5->left =t6;
    t4->left =t7;
    t7->left = t8;
    t4->right = t9;*/
    t6->left =t1;
    t1->right = t3;
    t3->left =t2;
    t3->right = t5;
    t5->left = t4;
    Solution *slt = new Solution();
    vector<int> result = slt->rightSideView(t6);
    int i;
    for(i=0; i<result.size(); i++)
    {
             cout<<result[i]<<' ';
    }
    cout<<endl;
    cin>>i;
    return 0;
}
