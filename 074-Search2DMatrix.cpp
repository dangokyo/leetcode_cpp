#include <vector>
#include<string>
#include<iostream>
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row, col;
        row = matrix.size();
        if(row == 0) return false;
        col = matrix[0].size();
        if(col == 0) return false;
        
        if(target < matrix[0][0]) return false;
        
        int start, end, mid;
        int r;
        start = 0;
        end = row - 1;
        
        while(start <= end)
        {
            mid = (start + end) /2;
            if(matrix[mid][0] > target){
                end = mid - 1;
            }
            else if(matrix[mid][0] < target){
                start = mid + 1;
            }
            else if(matrix[mid][0] == target){
                return true;
            }
            
        }
        r = end;
        
        start = 0;
        end = col - 1;
        while(start<=end)
        {
            mid = (start + end)/2;
            if(matrix[r][mid] > target){
                end = mid - 1;
            }
            else if(matrix[r][mid] < target){
                start = mid + 1;
            }
            else if(matrix[r][mid] == target){
                return true;
            }
                
        }
        
        return false;
    }
};
using namespace std;

int main()
{
    return 0;
}
