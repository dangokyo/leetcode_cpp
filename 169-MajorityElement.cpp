#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int length = num.size();
        int cur = num[0];
        int i, counter = 1;
        for(i=1; i<length; i++)
        {
               if(counter == 0)
               {
                          cur = num[i];
                          counter++;
                          continue;
               }
               
               if(cur == num[i])
               {
                      counter++;
               }
               else if(cur != num[i])
               {
                    counter--;
               }               
        }
        return cur;
    }
};


int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(3);
    in.push_back(5);
    in.push_back(1);
    in.push_back(1);
    in.push_back(1);
    in.push_back(4);
    Solution *slt = new Solution();
    cout<<slt->majorityElement(in);
    int i;
    cin>>i;
    return 0;
}
