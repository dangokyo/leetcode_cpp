#include<iostream>
#include<map>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
    	map<char, int> expectCount;
    	map<char, int> realCount;
    	map<char, queue<int> > myMap;
    	queue<char> charQueue;
    	string ans;
    	int ans_length = INT_MAX;
    	int slength = s.size();
    	int tlength = t.size();
    	if(slength==0 || tlength==0) return ans;
    	
    	int i;
    	int left, right, visited =0 , count = 0;
    	char frontChar;
    	for(i=0; i<tlength; i++)
    	{
    		realCount[t[i]] = 0;
    		count++;
    		if(expectCount.count(t[i]) > 0)
    		{
    			expectCount[t[i]]++;
    		}
    		else expectCount[t[i]]=1;
    	}
    	
    	/*for(i=0; i<tlength; i++)
    	{
    		cout<<t[i]<<':'<<expectCount[t[i]]<<' '<<realCount[t[i]]<<endl;
    	}*/
    	
    	left = 0;
    	while(realCount.count(s[left]) == 0) left++;
    	
    	//cout<<"left:"<<left<<endl;
    	for(i=left; i<slength; i++)
    	{
    		if(expectCount.count(s[i]) > 0)
    		{
    			//cout<<"processing:"<<i<<endl;
    			//cout<<"visited:"<<visited<<endl;
    			if(expectCount[s[i]] > realCount[s[i]])
    			{
    				realCount[s[i]]++;
    				visited++;
    				myMap[s[i]].push(i);
    				charQueue.push(s[i]);
    				//cout<<"push:"<<i<<' '<<s[i]<<endl;
    				if(visited == count && (i - left + 1 < ans_length) )
    				{
						ans_length = i-left+1;
						//cout<<"subString:"<<i<<' '<<left<<' '<<ans_length<<endl;
						ans = s.substr(left, ans_length);
					}
    			}
    			else if(expectCount[s[i]] <= realCount[s[i]])
    			{
    				frontChar = charQueue.front();
    				realCount[s[i]]++;
    				charQueue.push(s[i]);
    				myMap[s[i]].push(i);
    				while(expectCount[frontChar] < realCount[frontChar])
    				{
    					realCount[frontChar]--;
    					myMap[frontChar].pop();
    					charQueue.pop();
    					frontChar = charQueue.front();
    				}
    				//cout<<"leftmost char"<<frontChar<<endl;
    				left = myMap[frontChar].front();
    				if(visited == count && (i - left + 1 < ans_length) )
    				{
						ans_length = i-left+1;
						//cout<<"subString:"<<i<<' '<<left<<' '<<ans_length<<endl;
						ans = s.substr(left, ans_length);
					}
    			}
    			//cout<<"ans:"<<ans<<endl;
    		}
    		else continue;
    	}
    	return ans;
        
    }
};

int main()
{
	Solution *slt= new Solution();
	string s1 = "ADOBECODEBANC";
	string s2 = "ABCD";
	cout<<slt->minWindow(s1, s2)<<endl;
	return 0;
}
