#include<iostream>
#include<unordered_set> 
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    	wordDict.erase(beginWord);
    	wordDict.insert(endWord);
    	
    	queue<pair<string, int> > myQueue;
    	
    	myQueue.push(make_pair(beginWord, 1));
    	int i, len;
    	while(!myQueue.empty())
    	{
    		string t = myQueue.front().first;
    		len = myQueue.front().second;
    		myQueue.pop();
    		vector<string> candidates;
    		candidates = findNeighbor(t, wordDict);
    		for(i=0; i<candidates.size(); i++) 
			{
				myQueue.push(make_pair(candidates[i], len+1));
			}
		}
        return len;
    }
    
    vector<string> findNeighbor(string s, unordered_set<string>& dict)
    {
    	vector<string> ans;
    	int i, j, length = s.size();
    	for(i=0; i<length; i++)
    	{
    		char t = s[i];
    		for(j=0; j<26; j++)
    		{
    			if(t == 'a'+j) continue;
    			s[i] = 'a'+j;
    			if(dict.count(s))
    			{
    				//cout<<"push:"<<s<<endl;
    				ans.push_back(s);
    				dict.erase(s);
    			}
    		}
    		s[i] = t;
    	}
    	return ans;
    }
};

int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	Solution *slt = new Solution();
	cout<<slt->ladderLength(beginWord, endWord, dict)<<endl;
	return 0;
} 
