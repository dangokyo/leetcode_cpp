#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {               
		std::sort(num.begin(), num.end());
		vector<vector<int> > ans;
		
		
		int length = num.size();
		int ans_length;
		int i=0, j=0,k=0;
        int left, right, flag=1;
        int t_target;
        int sum;
        //cout<<ans_length<<endl;
        for(i=0; i < length - 3;i++)
        {
                 for(j= i+1; j< length-2; j++)
                 {
                        left = j+1;
                        right = length -1;
                        while(left < right)
                        {
                                   if(num[i] + num[j] + num[left] + num[right] == target)
                                   {
                                             vector<int> tmp;
                                             tmp.push_back(num[i]);
                                             tmp.push_back(num[j]);
                                             tmp.push_back(num[left]);
                                             tmp.push_back(num[right]);
                                             
                                             ans_length = ans.size();
                                             if(ans_length != 0)
                                             {
                                                           for(k=0; k< ans_length; k++)
                                                           {
                                                           if(num[i] == ans[k][0] && num[j] == ans[k][1] && num[left] == ans[k][2] && num[right] == ans[k][3]) 
                                                           {
                                                                     flag=0;
                                                                     break;
                                                           }
                                                           }
                                             }
                                             if(flag==0)
                                             {
                                                        flag = 1;
                                                        right--;
                                                        continue;
                                             }
                                             else
                                             {
                                                        //cout<<num[i]<<' '<<num[j]<<' '<<num[left]<<' '<<num[right]<<endl;
                                                        ans.push_back(tmp);
                                                        right--;
                                             }
                                   }
                                   else if(num[i] + num[j] + num[left] + num[right] > target)
                                   {
                                        right--;
                                   }
                                   else if(num[i] + num[j] + num[left] + num[right] < target)
                                   {
                                        left++;
                                   }
                        }
                 }
        }
        
        return ans;
    }
};

int main()
{
    //[-3,-2,-5,3,-4]
    vector<int> in;
    in.push_back(-5);
    in.push_back(-4);
    in.push_back(-3);
    in.push_back(-2);
    in.push_back(-1);
    in.push_back(0);
    in.push_back(0);
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    in.push_back(4);
    in.push_back(5);
    /*in.push_back(1);
    in.push_back(0);
    in.push_back(-1);
    in.push_back(0);
    in.push_back(-2);
    in.push_back(2);*/
    /*in.push_back(0);
    in.push_back(0);
    in.push_back(0);
    in.push_back(0);*/
    Solution *slt = new Solution();
    slt->fourSum(in, 0);
    
    char x;
    cin>>x;
    return 0;
}
