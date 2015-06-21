#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
         vector<int> tmp;
         int i, length, t;
         int diff, target1, target2;
         int index1=-1, index2=-1; 
         length = num.size();
         for(i=0; i<length; i++)
         {
                  tmp.push_back(num[i]);
         }
         sort(tmp.begin(), tmp.end());
         for(i=0; i<length; i++)
         {
                  if(tmp[i]!=num[length - i-1]) break;
         }
         if(i == length)
         {
              for(i=0; i<length; i++)
              {
                  num[i] = tmp[i];
              }
              return;
         }
         for(diff=1; diff<length; diff++)
         {
                     for(target1=length-1; target1>length - diff - 1; target1--)
                     {
                                           for(target2 = target1 -1; target2> length - diff - 2; target2--)
                                           {
                                                       if(num[target1] > num[target2])
                                                       {
                                                                      index2 = target1;
                                                                      index1 = target2;
                                                                      break;
                                                       }
                                           }
                                           if(index2 != -1 && index1 != -1 )
                                           {
                                                     break;
                                           }
                     }
                     if(index2 != 0 && index1 != -1 )
                     {
                               break;
                     }
         }
         
         t = num[index1];
         num[index1] = num[index2];
         num[index2] = t;
         
         tmp.clear();
         for(i=index1+1; i<length; i++)
                         tmp.push_back(num[i]);
         std::sort(tmp.begin(), tmp.end());
         for(i=index1+1; i<length; i++)
                         num[i] = tmp[i-index1-1];
         //cout<<index1<<' '<<index2<<endl; 
    }
};

int main()
{
    vector<int> in;
    Solution *slt = new Solution();
    int i;
    in.push_back(5);
    in.push_back(2);
    in.push_back(1);
    //in.push_back(2);
    
    slt->nextPermutation(in);
    
    for(i=0; i< in.size(); i++)
    {
             cout<< in[i]<<' ';
    }
    
    cin>>i;
    return 0;
}
