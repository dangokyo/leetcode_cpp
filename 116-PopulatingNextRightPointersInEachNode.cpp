#include<iostream>

using namespace std;

struct TreeLinkNode {
       int val;
       TreeLinkNode *left, *right, *next;
       TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
         if(root == NULL) return;
         TreeLinkNode *t = root;
         while(t->left!=NULL)
         {
                              levelConnect(t);
                              t = t->left;
         }
         return;
    }
    
    void levelConnect(TreeLinkNode *level)
    {
                          TreeLinkNode *t = level;
                          while(t!=NULL)
                          {
                                        t->left->next =t->right;
                                        cout<<"test"<<t->val<<endl;
                                        if(t->next!=NULL)
                                        {
                                                         cout<<"test"<<t->next->val<<endl;
                                                         t->right->next =t->next->left;
                                        }
                                        t = t->next;      
                          }         
                          return;
    }
};

int main()
{
    TreeLinkNode *t1 = new TreeLinkNode(1);
    TreeLinkNode *t2 = new TreeLinkNode(2);
    TreeLinkNode *t3 = new TreeLinkNode(3);
    TreeLinkNode *t4 = new TreeLinkNode(4);
    TreeLinkNode *t5 = new TreeLinkNode(5);
    TreeLinkNode *t6 = new TreeLinkNode(6);
    TreeLinkNode *t7 = new TreeLinkNode(7);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    Solution *slt = new Solution();
    slt->connect(t1);
    TreeLinkNode *t = t1;
    while(t!=NULL)
    {
                  cout<<t->val<<' ';
                  t = t->next;
    }
    cout<<endl;
    t= t2;
    while(t!=NULL)
    {
                  cout<<t->val<<' ';
                  t = t->next;
    }
    t = t4;
    cout<<endl;
    while(t!=NULL)
    {
                  cout<<t->val<<' ';
                  t = t->next;
    }
    cout<<endl;
    int i;
    cin>>i;
    return 0;
}
