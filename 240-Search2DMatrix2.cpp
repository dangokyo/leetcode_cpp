#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int height = matrix.size();
        if(height==0) return false;
        int width = matrix[0].size();
        if(width ==0) return false;
        
        int row = 0;
        int endIndex = width - 1;
        int i;
        while(row < height && endIndex >=0){
                  //cout<<row<<' '<<endIndex<<endl;
                     if(matrix[row][endIndex] < target){
                                                row++;
                                                continue;
                     }
                     else if(matrix[row][0] > target){
                          break;
                     }
                     else {
                          if(endIndex == 0) {
                                      if(matrix[row][0] == target) {
                                                        return true;
                                      }
                                      else {
                                           row++;
                                           break;
                                      }           
                          }
                          endIndex = searchSolver(matrix, row, target,0, endIndex);
                          if(matrix[row][endIndex] == target){
                                                   return true;
                          }
                          else if(matrix[row][endIndex] > target){
                               endIndex--;
                          }
                          row++;
                     }
        }
        return false; 
    }
    
    int searchSolver(vector<vector<int> >& matrix, int row, int target, int left, int right){
        if(left+1 == right){
                  if(matrix[row][left] == target) return left;
                  else return right;
        }
        
        int middle = (left + right)/2;
        if(target <= matrix[row][middle]){
                  return searchSolver(matrix, row, target, left, middle);
        }         
        else return searchSolver(matrix, row, target, middle, right);          
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> t;
    t.push_back(1);
    t.push_back(4);
    t.push_back(7);
    t.push_back(11);
    t.push_back(15);
    matrix.push_back(t);
    t.clear();
    t.push_back(2);
    t.push_back(5);
    t.push_back(8);
    t.push_back(12);
    t.push_back(19);
    matrix.push_back(t);
    t.clear();
    t.push_back(3);
    t.push_back(6);
    t.push_back(9);
    t.push_back(16);
    t.push_back(22);
    matrix.push_back(t);
    t.clear();
    t.push_back(10);
    t.push_back(13);
    t.push_back(14);
    t.push_back(17);
    t.push_back(24);
    matrix.push_back(t);
    t.clear();
    t.push_back(18);
    t.push_back(21);
    t.push_back(23);
    t.push_back(26);
    t.push_back(30);
    matrix.push_back(t);
    t.clear();
    for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++)
                    cout<<matrix[i][j]<<' ';
            cout<<endl;        
    }
    Solution *slt = new Solution();
    cout<<slt->searchMatrix(matrix, 5)<<endl;
    getchar();
    return 0;
}
