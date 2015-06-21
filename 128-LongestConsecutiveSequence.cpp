#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int, int>  mymap;  //<number, count> pair
        int i;
        int ans = 0;
        int length = num.size();
        int count, count1;
        for(i=0; i<length; i++)
        {
                 if(mymap.count(num[i]) > 0)
                 {
                                  continue;
                 }
                 else
                 {
                     mymap[num[i]] = 1;
                     if(mymap.count(num[i]-1) == 0 && mymap.count(num[i] + 1) == 0)
                     {
                                             continue;
                     }
                     else if(mymap.count(num[i]-1) == 0 && mymap.count(num[i] + 1) > 0)
                     {
                          count = mymap[num[i] + 1];
                          mymap[num[i]] = count + 1;
                          mymap[num[i]+count] = count+1;
                          if(ans < count + 1) ans = count + 1;
                     }
                     else if(mymap.count(num[i]-1) > 0 && mymap.count(num[i] + 1) == 0)
                     {
                          count = mymap[num[i]-1];
                          mymap[num[i]] = count + 1;
                          mymap[num[i] - count] = count + 1;
                          if(ans < count + 1) ans = count + 1;
                     }
                     else if(mymap.count(num[i]-1) > 0 && mymap.count(num[i] + 1) > 0)
                     {
                          count = mymap[num[i]+1];
                          count1 = mymap[num[i]-1];
                          mymap[num[i] + count] = count + count1 + 1;
                          mymap[num[i] - count1] = count + count1 + 1;
                          if(ans < count + count1 + 1) ans = count + count1 + 1;
                     }
                     
                 }
        }
        return ans;
    }
};

int main()
{
    int arr[] = {100, 4, 200, 1, 3, 2};
    int l = sizeof(arr)/4;
    int i;
    Solution *slt = new Solution();
    vector<int> in;
    for(i=0; i<l; i++)
    {
             in.push_back(arr[i]);
    }
    cout<<slt->longestConsecutive(in);
    cin>>i;
    return 0;
}
