#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int length = num.size();
        if(length ==1) return 0;
        
        if(num[0] > num[1]) return 0;
        if(num[length-2]< num[length-1]) return length-1;
        
        int left = 1, right = length-1;
        int mid = (left + right)/2;
        while(mid!=left && mid!=right)
        {
                        if(num[mid]>num[mid-1] && num[mid]>num[mid+1])
                        {
                                               return mid;
                        }
                        else if(num[mid]<num[mid+1])
                        {
                             left = mid;
                        }
                        else if(num[mid]<num[mid-1])
                        {
                             right = mid;
                        }
                        mid = (left+right)/2;
        }
    }
};

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(2);
    //in.push_back(1);
    Solution *slt = new Solution();
    int i = slt->findPeakElement(in);
    cout<<i<<endl;
    cin>>i;
    return 0;
}
