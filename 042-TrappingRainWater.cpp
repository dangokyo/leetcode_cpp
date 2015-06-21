#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	int length = height.size();
    	int i, left, right;
    	int occupied = 0;
    	int ans = 0;
    	left = 0;
    	bool isOptimal;
    	while(left < length-1)
    	{
    		while(left < length-1 && height[left] <height[left+1]) left++;
    		
    		right = left+1;
    		while(right < length)
    		{
    			if(height[right] <= height[left] && height[right] < height[right+1])
    			{
    				right++;
    			}
    			else if(height[right] <= height[left] && height[right] >= height[right+1])
    			{
                     for(i=right+1; i<length; i++)
                     {
                                    if(height[i] > height[right] && height[i] < height[left])
                                    {
                                               right = i;
                                               continue;
                                    }
                                    else if(height[i] > height[right] && height[i] >= height[left]) 
                                    {
                                         right = i;
                                         break;
                                    }
                     }
                     break;		
    			}
    			else if(height[right] > height[left] && height[right] <= height[right+1])
    			{
    				right++;
    			}
    			else if(height[right] > height[left] && height[right] > height[right+1])
    			{
    				isOptimal = true;
    				break;
    			}
    		}
    		//cout<<left<<' '<<right<<endl;
    		
    		ans = ans + getV(left, right, height);
    		//cout<<"now:"<<ans<<endl;
    		left = right;
    	}
        return ans;
    }
    
    int getV(int left, int right, vector<int>& height)
    {
    	int sol = 0;
    	int length = height.size();
    	if(left >=length-2) return 0;
    	
    	int i, h;
    	if(right == length) right= right-1;
    	h = min(height[left], height[right]);
    	for(i=left; i<right; i++)
    	{
    		sol = sol + max(0, h - height[i]);
    	}
    	return sol;
    }
};

int main()
{
    Solution *slt = new Solution();
    vector<int> in;
    /*in.push_back(5);
    in.push_back(4);
    in.push_back(1);
    in.push_back(2);*/
    
    /*in.push_back(5);
    in.push_back(1);
    in.push_back(2);
    in.push_back(1);
    in.push_back(2);
    in.push_back(5);*/
    
    in.push_back(0);
    in.push_back(1);
    in.push_back(0);
    in.push_back(2);
    in.push_back(1);
    in.push_back(0);
    in.push_back(1);
    in.push_back(3);
    in.push_back(2);
    in.push_back(1);
    in.push_back(2);
    in.push_back(1);
    cout<<slt->trap(in)<<endl;
    getchar();
    return 0;
}
