#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int l1 = nums1.size();
           int l2 = nums2.size();
           int k = (l1+l2)/2;
           double ans;
           if(l1 == 0 && l2 >0)
           {
                 if(l2%2 == 1) return nums2[l2/2];
                 else return (nums2[l2/2-1] + nums2[l2/2])/2.0;
           }
           else if(l1 > 0 && l2 == 0)
           {
                if(l1%2 == 1) return nums1[l1/2];
                else return (nums1[l1/2-1] + nums1[l1/2])/2.0;
           }
           else if((l1 + l2)%2 == 0)
           {
                  ans =(SortedArraySolver(0, l1-1, 0, l2-1, nums1, nums2, k-1) + SortedArraySolver(0, l1-1, 0, l2-1, nums1, nums2, k))/2.0;
           }
           else
           {
               ans = SortedArraySolver(0, l1-1, 0, l2-1, nums1, nums2, k);
           }
           return ans;
    }
    
    int SortedArraySolver(int left1, int right1, int left2, int right2, vector<int>& nums1, vector<int>& nums2, int k)
    {
           int middle1 = (left1 + right1)/2;
           int middle2 = (left2 + right2)/2;
           double ans;
           int t;
           //cout<<left1<<" "<<right1<<endl<<left2<<" "<<right2<<endl<<k<<endl<<endl;
           //return 0;
           if(k == 0) return min(nums1[left1], nums2[left2]);
           
           
           if(left1 == right1 && left2 < right2)
           {
                    t = nums2[left2 + k];
                    if(t < nums1[left1]) return t;
                    else return max(nums1[left1], nums2[left2+k-1]);        
           }
           else if(left1 < right1 && left2 == right2)
           {
                    t = nums1[left1 + k];
                    if(t < nums2[left2]) return t;
                    else return max(nums2[left2], nums1[left1+k-1]); 
           }
           else if(left1 == right1 && left2 == right2)
           {
                if(k>=1) return max(nums1[left1], nums2[left2]);
                else return min(nums1[left1], nums2[left2]);     
           }
           //cout<<"length:"<<middle1 - left1 + 1 + middle2 - left2 + 1<<endl;
           if(middle1 - left1 + 1 + middle2 - left2 + 1 >= k + 1)
           {
                      //cout<<"drop right"<<endl;
                      if(nums1[middle1] >= nums2[middle2])
                      {
                                        ans = SortedArraySolver(left1, middle1, left2, right2, nums1, nums2, k);
                      }
                      else
                      {
                          ans = SortedArraySolver(left1, right1, left2, middle2, nums1, nums2, k);
                      }           
           }
           else //if(middle1 -left1 + 1 + middle2 < k)
           {
                if(nums1[middle1] <= nums2[middle2])
                {
                                  ans = SortedArraySolver(middle1+1, right1, left2, right2, nums1, nums2, (k -(middle1 - left1 + 1)));    
                }
                else
                {
                    ans = SortedArraySolver(left1, right1, middle2+1, right2, nums1, nums2, (k-(middle2- left2+1))); 
                }
           }
           return ans;
    }
};

int main()
{
    vector<int> in1;
    vector<int> in2;
    in1.push_back(1);
    //in1.push_back(1);
    //in1.push_back(5);
    //in1.push_back(5);
    
    in2.push_back(2);
    in2.push_back(3);
    in2.push_back(4);
    Solution *slt = new Solution();
    cout<<slt->findMedianSortedArrays(in1, in2)<<endl;
    getchar();
    return 0;
}
