#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        int length = s.size();
        int count = words.size();
        int i, j, k, word_length;
        int start;
		map<string, int> expectCount;
        map<string, int> realCount;
        string t;
        
        if(length == 0) return ans;
        if(count == 0) return ans;
        word_length = words[0].size();
        
        
        for(i=0; i<count; i++)
        {
            if(expectCount.count(words[i]) > 0)
            {
				expectCount[words[i]]++;
            }
            else expectCount[words[i]] = 1;
        }
        int interval = length - count*word_length +1;
        for(j=0; j<interval;j++)
        {
        	start = j;
        	realCount.clear();
        	for(i=0; i<count; i++)
        	{
        		t = s.substr(start, word_length);
        		start += word_length;
        		//cout<<t<<endl;
        		if(expectCount.count(t) > 0)
        		{
        			if(realCount[t] >= expectCount[t])
        			{
        				break;
        			}
        			else
        			{
        				realCount[t]++;
        			}
        		}
        		else
        		{
        			break;
        		}
        	}
        	
        	if(i==count) ans.push_back(j);
        }
     	return ans;   
    }
};

int main()
{
    //string s = "barfoothefoobarman";
    //string s = "abababab";
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    //string s = "aaa";
    vector<string> words;
    //words.push_back("a");
    words.push_back("barr");
    words.push_back("fooo");
    words.push_back("wing");
    words.push_back("ding");
    words.push_back("wing");
    Solution *slt = new Solution();
    vector<int> result = slt->findSubstring(s, words);
    for(int i=0; i<result.size(); i++)
    {
            cout<<result[i]<<' ';
    }
    cout<<endl;
    cin>>s;
    return 0;
}
