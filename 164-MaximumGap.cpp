#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int length = num.size();
        if(length <=1) return 0;
        
        int i;
        double interval;
        int ans = INT_MIN;
        int min = INT_MAX, max = INT_MIN;
        int index;
        int tmp, t1, t2;
        vector<int> bucket_max(length, INT_MIN);
        vector<int> bucket_min(length, INT_MAX);
        vector<bool> bucket_visited(length, false);
        
        for(i=0; i<length; i++)
        {
                 if(num[i]<min) min = num[i];
                 if(num[i]>max) max = num[i];
        }
        interval = ((double)(max - min))/(length-1);
        if(interval < 1) interval = 1;
        
        for(i=0; i<length; i++)
        {
                 index = (num[i] - min) / interval;
                 if(bucket_max[index] < num[i]) bucket_max[index] = num[i];
                 if(bucket_min[index] > num[i]) bucket_min[index] = num[i];
                 bucket_visited[index] = true;
        }
        
        for(i=0; i<length; i++)
        {
                 if(i>=0 && i<length-1)
                 {
                         if(bucket_visited[i+1])
                         {
                                              t1 = bucket_max[i] - bucket_min[i];
                                              t2 = bucket_min[i+1] - bucket_max[i];
                                              tmp = (t1>t2)?t1:t2;
                                              if(tmp>ans) ans = tmp;
                         }
                         else
                         {
                             t1 = bucket_max[i];
                             while(!bucket_visited[i+1]) i++;
                             tmp = bucket_min[i+1] - t1;
                             if(tmp>ans) ans = tmp;
                         }
                 }
                 else if(i==length-1)
                 {
                      tmp = bucket_max[i] - bucket_min[i];
                      if(tmp>ans) ans = tmp;     
                 }
        }
        return ans;
    }
};

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(4);
    in.push_back(3);
    in.push_back(9);
    in.push_back(16);
    in.push_back(5);
    in.push_back(11);
    Solution *slt = new Solution();
    cout<<slt->maximumGap(in)<<endl;
    int i;
    cin>>i;
    return 0;
}
