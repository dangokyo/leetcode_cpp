#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	int pattern_size = p.size();
    	vector<pair<char, bool> > pattern; //pair<character, isMultiple>
		int i;
		bool ans;
		char character, last_character;
		bool isMultiple, last_isMultiple;
		for(i=0; i<pattern_size; i++)
		{
			character = p[i];
			if(p[i+1] == '*')
			{
				isMultiple = true;
				i++;
			}
			else
			{
				isMultiple = false;
			}
			
			if(i==0)
			{
				pattern.push_back(make_pair(character, isMultiple));
				last_character = character;
				last_isMultiple = isMultiple;
			}
			else
			{
				if(character == last_character && last_isMultiple && isMultiple)
				{
					continue;
				}
				else
				{
					pattern.push_back(make_pair(character, isMultiple));
					last_character = character;
					last_isMultiple = isMultiple;
				}
			}
		} 
		/*for(i=0; i<pattern.size();i++)
		{
			cout<<pattern[i].first<<" "<<pattern[i].second<<endl;
		}*/
		if(s.size() == 0)
		{
			for(int i=0; i<pattern.size(); i++)
			{
				if(!pattern[i].second) return false;
			}
			return true;
		}
		else ans = matchSolver(0, 0, s, pattern);
        return ans;
    }
    
    bool matchSolver(int str_index, int pattern_index, string s, vector<pair<char, bool> >& pattern)
    {
    	if(pattern_index >= pattern.size()) return false;
    	char toMatch = pattern[pattern_index].first;
    	bool isMultiple = pattern[pattern_index].second;
    	bool flag, f1, f2, f3;
    	int i;
    	
    	//cout<<"processing:"<<str_index<<" "<<pattern_index<<" "<<toMatch<<" "<<isMultiple<<endl;
    	if(str_index == s.size()-1)
    	{
    		if(pattern_index == pattern.size()-1)
    		{
    			if(toMatch=='.' || (toMatch == s[str_index])) return true;
    			else return false;
    		}
    		
    		if(isMultiple)
    		{
    			f1 = matchSolver(str_index, pattern_index+1, s, pattern);
    			if(f1) return true;
    		}
    		
    		if(toMatch == '.')
			{
				if(pattern_index == pattern.size()-1) 
				{
					return true;
				}
				else
				{
					for(i=pattern_index+1; i<pattern.size(); i++)
					{
						if(!pattern[i].second) return false;
					}
					return true;
				}
			}
			else if(toMatch != '.')
			{
				if(toMatch == s[str_index])
				{
					if(pattern_index == pattern.size()-1) 
					{
						return true;
					}
					else
					{
						for(i=pattern_index+1; i<pattern.size(); i++)
						{
							if(!pattern[i].second) return false;
						}
						return true;
					}	
				}
				else return false;
			}	
    	}
    	
    	if(isMultiple)
    	{
    		if(toMatch == '.')
    		{
    			f1 = matchSolver(str_index+1,pattern_index, s, pattern );
    			f2 = matchSolver(str_index+1,pattern_index+1, s, pattern);
    			f3 = matchSolver(str_index, pattern_index+1, s, pattern);
    			return (f1||f2||f3);
    		}
    		else if(toMatch!= '.' && s[str_index] == toMatch)
    		{
    			f1 = matchSolver(str_index+1,pattern_index, s, pattern );
    			f2 = matchSolver(str_index+1,pattern_index+1, s, pattern);
    			f3 = matchSolver(str_index, pattern_index+1, s, pattern);
    			return (f1||f2||f3);
    		}
    		else if(toMatch!= '.' && s[str_index] != toMatch)
    		{
    			return matchSolver(str_index, pattern_index+1, s, pattern);
    		}
    	}
    	else if(!isMultiple && toMatch == '.') // || s[str_index] == toMatch) 
		{
			return matchSolver(str_index+1, pattern_index+1, s, pattern);
		}
		else if(!isMultiple &&  s[str_index] == toMatch && toMatch != '.')
		{
			return matchSolver(str_index+1, pattern_index+1, s, pattern);
		}
    	else return false;
    }
};

int main()
{
	Solution *slt = new Solution();
	string s = /*"abbbcd";//"ab";/*"ab";"aaa";"aaaccbccbcbaabcaa";*/"aaaaaaaaaaaaab";
	string p = /*"ab*bbbcd";//".*..c*";/*".*..";".*";"c*a*.*a*.*c*.c*.a*c";*/"a*a*a*a*a*a*a*a*a*a*a*a*b";
	cout<<slt->isMatch(s, p)<<endl;
	return 0;
}
