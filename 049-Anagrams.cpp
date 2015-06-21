#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	map<long, vector<string> > amap;
    	vector<string> result;
    	int i, j;
    	int length = strs.size();
    	
    	if(length == 0)
    		return strs;
    	
    	long key;
    	for(i=0; i< length; i++)
    	{
    		key = str_hash(strs[i]);
    		amap[key].push_back(strs[i]);
    	}
    	
    	for(std::map<long, vector<string> >::const_iterator it = amap.begin(); it != amap.end(); ++it)
    	{
    		long key = it->first;
    		if(amap[key].size() <= 1)
			{
				continue;
			}
			else
			{
				for(j=0; j<amap[key].size(); j++)
				{
					result.push_back(amap[key][j]);
				}
			}	
    	}
    	
    	return result;
    }
    
    long str_hash(string str)
    {
    	int a[26];
    	int i, j;
    	long hash = 0;
    	
    	for(i=0; i<26; i++)
    	{
    		a[i] = 0;
    	}
    	
    	if(str.size()==0)
    	{
    		return 0;
    	}
    	
    	for(i=0; i<str.size();i++)
    	{
    		a[(int)(str[i]-'a')]++;
    	}
    	
    	for(i=0; i<26; i++)
    	{
    		hash = hash*17 + a[i];
    	}
    	
    	return hash;
    	
    }
    
};

int main()
{
	Solution *slt = new Solution();
	vector<string> result;
	vector<string> in;
	in.push_back("ape");
	in.push_back("and");
	in.push_back("cat");
	result = slt->anagrams(in);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	return 0;
}
