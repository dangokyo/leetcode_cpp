#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
    	vector<int> vals;
    	vector<TreeNode*> nodes;
    	InorderTraversal(root, vals, nodes);
    	sort(vals.begin(), vals.end());
        int length = vals.size();
        int i;
		for(i=0; i<length; i++) nodes[i]->val = vals[i];
		return;
    }
    
    int InorderTraversal(TreeNode* t, vector<int>& vals, vector<TreeNode*>& nodes)
    {
    	if(t==NULL) return 0;
    	InorderTraversal(t->left, vals, nodes);
    	vals.push_back(t->val);
    	nodes.push_back(t);
    	InorderTraversal(t->right, vals,nodes);
    	return 0;
    }
};


int InorderDisplay(TreeNode *t)
{
	if(t==NULL) return 0;
	InorderDisplay(t->left);
	cout<<t->val<<endl;
	InorderDisplay(t->right);
	return 0;
}

int main()
{
	TreeNode *t0 = new TreeNode(8);
	TreeNode *t1 = new TreeNode(7);
	TreeNode *t2 = new TreeNode(12);
	TreeNode *t3 = new TreeNode(4);
	TreeNode *t4 = new TreeNode(18);
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t6 = new TreeNode(9);
	TreeNode *t7 = new TreeNode(3);
	TreeNode *t8 = new TreeNode(13);
	TreeNode *t9 = new TreeNode(21);
	t0->left = t1;
	t0->right = t2;
	t1->left = t3;
	t3->left = t4;
	t3->right = t5;
	t2->left =t6;
	t2->right =t7;
	t7->left = t8;
	t7->right = t9;
	InorderDisplay(t0);
	
	Solution *slt = new Solution();
	slt->recoverTree(t0);
	InorderDisplay(t0);
	return 0;
}
