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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;
        
        if(n == 0)
             return ans;
        
        if(n == 1)
        {
             TreeNode *node = new TreeNode(1);
             ans.push_back(node);
             return ans;
        }
        ans = TreeSolver(1, n);
        return ans;
    }
    
    vector<TreeNode *> TreeSolver(int start, int end)
    {
                    vector<TreeNode *> sol;
                    if(start > end)
                    {
                             sol.push_back(NULL);
                             return sol;
                    }
                    
                    int i, j, k;
                    for(i=start; i<=end; i++)
                    {
                                 vector<TreeNode *> LeftTreeSet = TreeSolver(start, i-1);
                                 vector<TreeNode *> RightTreeSet = TreeSolver(i+1, end);
                                 for(j=0; j<LeftTreeSet.size(); j++)
                                 {
                                          for(k=0; k<RightTreeSet.size(); k++)
                                          {    
                                               TreeNode *node = new TreeNode(i);
                                               node->left = LeftTreeSet[j];
                                               node->right = RightTreeSet[k];
                                               sol.push_back(node);
                                          }
                                 }
                    }
                    return sol;
    }
};


    
    void inTraversal(TreeNode *node, vector<int> &ans)
    {
         if(node == NULL)
         {
                 cout<<"hh";
                 return;
         }
         else
         {
             cout<<&node<<endl;
             inTraversal(node->left, ans);
             ans.push_back(node->val);
             inTraversal(node->right, ans);
         }
    }
    
    
    vector<int> inorderTraversal(TreeNode *root) 
    {
                vector<int> ans;
                inTraversal(root, ans);
                return ans;
    }

int main()
{
    int in = 2;
    Solution *slt = new Solution();
    vector<TreeNode *> result = slt->generateTrees(in);
    vector<int> t;
    cout<<result.size()<<endl;
    for(int i=0; i< result.size(); i++)
    {
            t = inorderTraversal(result[i]);
            cout<<result[i]->val<<endl;
            cout<<"hehe"<<endl;
    }
    cin>>in;
    return 0;
}
