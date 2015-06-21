#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:        
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        int length = intervals.size();
        if(length <2) return intervals;
        sort(intervals.begin(), intervals.end(), IntervalCompare);
        int cur_start, cur_end;
        int last_start, last_end;
        int i;
        last_start = intervals[0].start;
        last_end = intervals[0].end;
        for(i=1; i<length;i++)
        {
                 cur_start = intervals[i].start;
                 cur_end = intervals[i].end;
                 if(cur_start > last_end)
                 {
                              Interval t(last_start, last_end);
                              ans.push_back(t);
                              last_start = cur_start;
                              last_end = cur_end;
                 }
                 else if(cur_start <= last_end)
                 {
                      last_end = max(last_end, cur_end);     
                 }         
        }
        Interval t(last_start, last_end);
        ans.push_back(t);
        return ans;
    }
    
    static bool IntervalCompare(Interval a, Interval b)
    {
         if(a.start < b.start)
         {
                    return true;
         }
         else if(a.start > b.start)
         {
              return false;
         }
         else
         {
             return a.end>b.end;
         }    
    } 
};

int main()
{
    Interval t1(1,3);
    //Interval t5(2,10);
    Interval t2(8,10);
    Interval t3(15,18);
    Interval t4(2,6);
    vector<Interval> in;
    vector<Interval> result;
    in.push_back(t1);
    in.push_back(t2);
    in.push_back(t3);
    in.push_back(t4);
    //in.push_back(t5);
    int i;
    for(i=0; i<in.size(); i++)
    {
             cout<<in[i].start<<' '<<in[i].end<<endl;
    }
    cout<<endl;
    Solution *slt = new Solution();
    result = slt->merge(in);
    for(i=0; i<result.size(); i++)
    {
             cout<<result[i].start<<' '<<result[i].end<<endl;
    }
    cout<<endl;
    cin>>i;
    return 0;
}
