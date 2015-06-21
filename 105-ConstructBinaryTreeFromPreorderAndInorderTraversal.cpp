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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
             if(preorder.size()==0 ) return NULL;
             int length = preorder.size();
             TreeNode *root = buildSubTree(preorder, inorder, 0, length-1, 0, length-1);
             return root;
    }
    
    TreeNode * buildSubTree(vector<int> &preorder, vector<int> &inorder, int prestart, int preend, int instart, int inend)
    {
             TreeNode *node, *leftTree,*rightTree;
             int nodeval = preorder[prestart];
             node = new TreeNode(nodeval);
             
             if(prestart > preend) return NULL;
             
             
             int pos = SearchIndex(inorder, nodeval);
             int leftsize = pos-instart;
             int rightsize = inend - pos;
             /*cout<<nodeval<<endl;
             cout<<"pre:"<<prestart<<" "<<preend<<endl;
             cout<<"in: "<<instart<<" "<<inend<<endl;
             cout<<leftsize<<" "<<rightsize<<endl;*/
             leftTree = buildSubTree(preorder, inorder, prestart+1, prestart+leftsize, instart, pos-1);
             rightTree = buildSubTree(preorder, inorder, prestart+leftsize+1, preend, pos+1, inend);
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
    vector<int> preorder;
    inorder.push_back(6);
    inorder.push_back(2);
    inorder.push_back(1);
    inorder.push_back(4);
    inorder.push_back(3);
    inorder.push_back(5);
    
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(6);
    preorder.push_back(3);
    preorder.push_back(4);
    preorder.push_back(5);
    
    Solution *slt = new Solution();
    TreeNode *root = slt->buildTree(preorder, inorder);
    int i;
    cin>>i;
    return 0;
}
