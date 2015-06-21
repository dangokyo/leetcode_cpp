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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
                     int length= intervals.size();
                     if(length < 1) 
                     {
                               intervals.push_back(newInterval);
                               return intervals;
                     }
                     vector<Interval> ans;
                     sort(intervals.begin(), intervals.end(), IntervalCompare);
                     int i;
                     int insert_start = newInterval.start;
                     int insert_end = newInterval.end;
                     int cur_start, cur_end;
                     for(i=0; i<length; i++)
                     {
                              cur_start = intervals[i].start;
                              cur_end = intervals[i].end;
                              //cout<<"get:"<<i<<':'<<cur_start<<' '<<cur_end<<endl;
                              if(insert_end < cur_start || cur_end < insert_start)
                              {
                                            ans.push_back(intervals[i]);
                                            continue;
                              }
                              else
                              {
                                  insert_start = min(insert_start, cur_start); 
                                  insert_end = max(insert_end, cur_end);
                                  //cout<<"insert:"<<insert_start<<' '<<insert_end<<endl;
                              }
                     }
                     Interval t(insert_start, insert_end);
                     ans.push_back(t);
                     sort(ans.begin(), ans.end(), IntervalCompare);
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
    Interval t2(6,9);
    Interval t3(15,18);
    Interval t(2,5);
    vector<Interval> in;
    vector<Interval> result;
    in.push_back(t1);
    in.push_back(t2);
    in.push_back(t3);
    //in.push_back(t4);
    Solution *slt = new Solution();
    int i;
    result = slt->insert(in, t);
    
    for(i=0; i<result.size(); i++)
    {
             cout<<i<<':'<<result[i].start<<' '<<result[i].end<<endl;
    }
    cin>>i;
    return 0;
}
