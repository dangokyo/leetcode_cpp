#include<iostream>
#include<unordered_set>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > ans;
        dict.insert(start);
		dict.insert(end);
		int size = dict.size();
		bool findEnd = false;
		int i=0, j;
		int curLevel = 1;
        vector<string> nextLevelStrings;
		
		unordered_set<string> curLevelSet;
		unordered_set<string> nextLevelSet;
		vector<string> vec;
		unordered_map<string, unordered_set<string> >inverseMap;
		vector<string> sol;
		string t1, t2;
		i=0;
		
		for(unordered_set<string>::iterator SI=dict.begin(), SE=dict.end(); SI!=SE; SI++)
		{
			vec.push_back(*SI);
		}
        //dict.erase(end);
        curLevelSet.insert(end);
        while(!findEnd && !dict.empty() && !curLevelSet.empty())
        {
        	for(unordered_set<string>::iterator SI=curLevelSet.begin(), SE=curLevelSet.end(); SI!=SE; SI++)
        	{
        		//t1 = *SI;
        		//cout<<"processing:"<<t1<<endl;
        		nextLevelStrings = findNeighbor(*SI, dict);
        		//cout<<"level "<<curLevel<<endl;
        		for(j=0; j<nextLevelStrings.size(); j++)
        		{
        			//t2 = nextLevelStrings[j]; 
        			nextLevelSet.insert(nextLevelStrings[j]);
        			inverseMap[nextLevelStrings[j]].insert(*SI);
        			//cout<<"processing:"<<nextLevelStrings[j]<<" to "<<*SI<<endl;
        			if(nextLevelStrings[j] == end) findEnd = true;
        		}
        	}
        	for(unordered_set<string>::iterator SII=nextLevelSet.begin(), SIE=nextLevelSet.end(); SII!=SIE; SII++)
        	{
        		dict.erase(*SII);
        	}
        	curLevelSet.clear();
        	curLevelSet = nextLevelSet;
        	nextLevelSet.clear();
        	dict.erase(end);
        }
        
        sol.clear();
        findLadderSolver(start, end, sol, inverseMap, vec, ans);
        return ans;
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
    				ans.push_back(s);
    			}
    		}
    		s[i] = t;
    	}
    	return ans;
    }
    
    int findLadderSolver(string& cur, string& end, vector<string> &sol,unordered_map<string, unordered_set<string> >& inverseMap,vector<string>& candidates, vector<vector<string> >& ans)
    {
    	sol.push_back(cur);
    	if(cur == end)
    	{
    		ans.push_back(sol);
    		sol.pop_back();
    		return 0;
    	}
    	
    	int length = candidates.size();
    	string ts;
    	for(unordered_set<string>::iterator SI=inverseMap[cur].begin(), SE=inverseMap[cur].end(); SI!=SE; SI++)
    	{
    		ts = *SI;
    		findLadderSolver(ts, end, sol, inverseMap, candidates, ans);
    	}
    	sol.pop_back();
    	return 0;
    }
};



int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict;
	/*dict.insert("bot");
	dict.insert("cig");
	dict.insert("cog");
	dict.insert("dit");
	dict.insert("dog");
	dict.insert("dot");
	dict.insert("dut");
	dict.insert("hot");
	dict.insert("hit");
	dict.insert("log");
	dict.insert("lot");*/
	
	//dict.insert("hit");
	//dict.insert("dog");
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("hit");
	dict.insert("lot");
	dict.insert("log");
	
	Solution *slt = new Solution();
	vector<vector<string> > result;
	result = slt->findLadders(start, end, dict);
	
	//cout<<result.size()<<endl;
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
		{
			cout<<result[i][j]<<' ';
		}
		cout<<endl;
	}
	 
	return 0;
} 
