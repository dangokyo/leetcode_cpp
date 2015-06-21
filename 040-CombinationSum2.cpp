#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: 	
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
 		vector<vector<int> > result;  
    	vector<int> solution;  
    	int sum=0;  
    	std::sort(candidates.begin(), candidates.end());  
    	CombinationSolver(candidates,sum, 0, target, solution, result);  
      	return result;  
	}
	  
    void CombinationSolver(  vector<int>& candidates,  int& sum,  int level,  int target,  vector<int>& solution,  vector<vector<int> >& result)  
    {
		if(sum > target) return;  
      	if(sum == target)  
      	{  
        	result.push_back(solution);  
        	return;  
      	}  
      	for(int i =level; i< candidates.size(); i++)  
      	{  
        	sum+=candidates[i];  
        	solution.push_back(candidates[i]);  
        	CombinationSolver(candidates, sum, i+1, target, solution, result);  
        	solution.pop_back();  
        	sum-=candidates[i];   
			while(i < candidates.size()-1 && candidates[i]== candidates[i+1]) i++;     
      	}  
	} 
};


int main()
{
    vector<int> in;
    Solution *slt = new Solution();
    int i, j;    
    vector<vector<int>  >  result;
    in.push_back(10);
    in.push_back(1);
    in.push_back(2);
    in.push_back(7);
	in.push_back(6);
	in.push_back(1);
	in.push_back(5);           
    
    result = slt->combinationSum(in , 8);
    
    for(i=0; i<result.size(); i++)
    {
             for(j=0; j< result[i].size(); j++)
             {
                      cout<<result[i][j]<<' ';
             }
             cout<<endl;
    }
    return 0;
}
