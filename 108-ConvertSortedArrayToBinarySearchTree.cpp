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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *node;
        int length = num.size();
        if(length == 0) return NULL;
        node = BuildArrayToBST(num, 0, length-1);
        return node;
    }
    
    TreeNode *BuildArrayToBST(vector<int> &num, int start, int end)
    {
             if(start > end) return NULL;
             
             int mid = (end - start) / 2 + start;
             TreeNode *node = new TreeNode(num[mid]);
             TreeNode *leftTree = BuildArrayToBST(num, start, mid-1);
             TreeNode *rightTree = BuildArrayToBST(num, mid+1, end);
             node->left = leftTree;
             node->right = rightTree;
             return node;
    }           
};

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(4);
    
    Solution *slt = new Solution();
    TreeNode *root;
    root = slt->sortedArrayToBST(in);
    int i;
    cin>>i;
    return 0;
}
