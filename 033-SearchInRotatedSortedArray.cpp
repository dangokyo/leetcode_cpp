#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        vector<int> tmp;
        int i;
        int ans = -1;
        for(i=0; i< n; i++)
                 tmp.push_back(A[i]);
        for(i=0; i< n; i++)
                 tmp.push_back(A[i]);
        int start, end, mid;
        start = 0;
        end = n - 1;
        while(start < end - 1)
        {
                    cout<<start<<" "<<end<<endl;
                    mid = (start + end) /2 ;
                    if(A[mid] > A[end]){
                              start = mid;
                    }
                    else if(A[mid] < A[start]){
                         end = mid;
                    }
                    else{
                         break;
                    }
        }
        if(A[start] > A[end]){
             start = start + 1;
        }
        end = start + n - 1;
        while(start < end - 1)
        {
                    cout<<start<<" "<<end<<endl;
                    if(tmp[start] == target){
                                   ans = start%n;
                                   break;
                    }
                    if(tmp[end] == target){
                                ans = end % n;
                                break;
                    }
                    mid = (start + end) /2;
                    if(tmp[mid]< target){
                                 start = mid;
                    }
                    else if(tmp[mid] > target){
                         end = mid;
                    }
                    else if(tmp[mid] == target){
                         ans = mid % n;
                         break;
                    }
        }
        
        if(tmp[start] == target){
                      ans = start%n;
        }
        if(tmp[end] == target){
                    ans = end % n;
        }
        return ans;
        
    }
};

int main()
{
    Solution *slt = new Solution();
    int i;
    int A[1] = {1};
    //int A[8] = {3, 4, 5, 6, 7, 0, 1, 2};
    //int A[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    cout<<slt->search(A, 1, 1);
    cin>>i;
    return 0;
}
