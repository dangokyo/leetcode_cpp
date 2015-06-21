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
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
             if(inorder.size()==0 ) return NULL;
             int length = inorder.size();
             TreeNode *root = buildSubTree(inorder, postorder, 0, length-1, 0, length-1);
             return root;
    }
    
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int poststart, int postend)
    {
              TreeNode *node, *leftTree, *rightTree;
              
              if(poststart > postend) return NULL;
              int nodeval = postorder[postend];
              int pos;
              node = new TreeNode(nodeval);
              pos = SearchIndex(inorder, nodeval);
              int leftsize = pos - instart;
              int rightsize = inend - pos;
              
              cout<<"pos:"<<pos<<" "<<nodeval<<endl;
              cout<<"post:"<<poststart<<" "<<postend<<endl;
              cout<<"in:  "<<instart<<" "<<inend<<endl;
              cout<<leftsize<<" "<<rightsize<<endl<<endl;
              
              leftTree = buildSubTree(inorder, postorder, instart, pos-1, poststart, poststart+leftsize-1);
              rightTree = buildSubTree(inorder, postorder, pos+1, inend, postend-rightsize , postend-1);
              node->left = leftTree;
              node->right = rightTree;
              return node;
    }
    
    
    int SearchIndex(vector<int> vec, int target)
    {
        int i;
        for(i=0; i<vec.size(); i++)
        {
                 if(vec[i]== target)
                 {
                             break;
                 }
        }
        return i;
    }
};


int main()
{
    vector<int> inorder;
    vector<int> postorder;
    inorder.push_back(6);
    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(4);
    inorder.push_back(3);
    inorder.push_back(5);
    
    postorder.push_back(6);
    postorder.push_back(2);
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(3);
    postorder.push_back(1);
    
    Solution *slt = new Solution();
    TreeNode *root = slt->buildTree(inorder, postorder);
    int i;
    cin>>i;
    return 0;
}
