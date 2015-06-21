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
         TreeLinkNode *uplevel = root;
         TreeLinkNode *leftmost = getBottomLeftMostNode(uplevel);
         TreeLinkNode *t1, *t2;
         while(leftmost!=NULL)
         {
                              t1 = uplevel;
                              while(t1!=NULL)
                              {
                                             if(t1->left == leftmost)
                                             {
                                                         t2 = t1->left;
                                                         cout<<"found left:"<<t2->val<<endl;
                                                         if(t1->right != NULL)
                                                         {
                                                                      t2->next = t1->right;
                                                                      t2 = t2->next;
                                                         }
                                                         t1 = t1->next;
                                                         while(t1 != NULL)
                                                         {
                                                                  if(t1->left != NULL)
                                                                  {
                                                                              t2->next =t1->left;
                                                                              t2 = t2->next;
                                                                  }
                                                                  if(t1->right != NULL)
                                                                  {
                                                                               t2->next = t1->right;
                                                                               t2 = t2->next;
                                                                  }
                                                                  t1 = t1->next;
                                                         }
                                                         break;
                                             }
                                             else if(t1->right == leftmost)
                                             {
                                                  t2 = t1->right;
                                                  cout<<"found right:"<<t2->val<<endl;
                                                  t1 = t1->next;
                                                  while(t1 != NULL)
                                                  {
                                                           if(t1->left != NULL)
                                                           {
                                                                       t2->next =t1->left;
                                                                       t2 = t2->next;
                                                           }
                                                           if(t1->right != NULL)
                                                           {
                                                                        t2->next = t1->right;
                                                                        t2 = t2->next;
                                                           }
                                                           t1 = t1->next;
                                                  }
                                                  break;
                                             }
                                             else t1= t1->next;
                              }
                              uplevel = leftmost;
                              leftmost = getBottomLeftMostNode(uplevel);                                    
         }
        
    }
    
    TreeLinkNode *getBottomLeftMostNode(TreeLinkNode *uplevel)
    {
                 TreeLinkNode *t = uplevel;
                 while(t!=NULL)
                 {
                               if(t->left!=NULL)
                               {
                                                return t->left;
                               }
                               else if(t->left==NULL && t->right!=NULL)
                               {
                                    return t->right;
                               }
                               else
                               {
                                   t = t->next;
                               }
                 }
                 return NULL;
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
    //t2->next = t3;
    //t2->left = t4;
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
    t = t5;
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
    
