#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
                vector<int> ans;
                vector<int> v1, v2;
                int i, j, k;
                int length = input.size();
                for(i=0; i<length; i++){
                         if(input[i] == '+' || input[i] == '-' || input[i]=='*')
                         {
                                     string str1 = input.substr(0, i);
                                     string str2 = input.substr(i+1);
                                     v1 = diffWaysToCompute(str1);
                                     v2 = diffWaysToCompute(str2);            
                         }
                         for(j=0; j<v1.size(); j++){
                                  for(k=0; k<v2.size(); k++){
                                           if(input[i] == '+'){
                                                       ans.push_back(v1[j] + v2[k]);
                                           }
                                           else if(input[i] == '-'){
                                                       ans.push_back(v1[j] - v2[k]);
                                           }
                                           else if(input[i] == '*'){
                                                       ans.push_back(v1[j] * v2[k]);
                                           }
                                  }
                         }
                 }
                 
                 if(ans.size()==0){
                                 ans.push_back(atoi(input.c_str()));
                 }
                 return ans;
    }
};

int main(){
	string in = "2*3-4*5";
	Solution *slt = new Solution();
	vector<int> result =  slt->diffWaysToCompute(in);
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<' ';
	}
	return 0;
}
