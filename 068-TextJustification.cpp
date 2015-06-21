#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	vector<string> ans;
		int length = words.size();
		
		int cursize = 0;
		vector<string> curline; 
		int i;
		for(i=0; i<length; i++)
		{
			cursize += words[i].size();
			if(cursize<=maxWidth)
			{
				curline.push_back(words[i]);
				cursize++;
			}
			else
			{
				ans.push_back(CreateLine(curline, maxWidth));
				curline.clear();
				i--;
				cursize = 0;
			}
		}
		if(i==length && curline.size()!=0) ans.push_back(CreateFinalLine(curline, maxWidth));
		return ans;    
    }
    
    string CreateLine(vector<string> line, int maxWidth)
    {
    	string ans;
    	int numWords = line.size();
    	int i, numSpace;
    	int length = 0;
    	for(i=0; i<numWords; i++) length += line[i].size();
    	numSpace = maxWidth- length;
    	if(numWords == 1)
    	{
    		string t;
    		for(i=0; i<numSpace; i++) t += ' ';
    		ans = line[0] + t;
    	}
    	else if(numWords == 2)
    	{
    		string t;
    		for(i=0; i<numSpace; i++) t+=' ';
    		ans = line[0]+t+line[1];
    	}
    	else
    	{
    		string left;
    		string right;
    		int leftIndex = numSpace - (numSpace/(numWords-1))*(numWords-1); 
    		int rightNum = numSpace/(numWords-1);
    		int leftNum = rightNum+1;
    		for(i=0; i<leftNum; i++) left +=' ';
    		for(i=0; i<rightNum; i++) right +=' ';
    		//ans = line[0] + left;
    		for(i=0; i<numWords-1; i++)
    		{
    			if(i<leftIndex)
    			{
    				ans = ans + line[i] + left;
    			}
    			else ans = ans + line[i] + right;
    		}
    		ans = ans + line[numWords-1];
    	}
    	return ans;
    }
    
    string CreateFinalLine(vector<string> line, int maxWidth)
    {
    	string ans;
    	int numWords = line.size();
    	int i, numSpace;
    	int length = 0;
    	for(i=0; i<numWords; i++) length += line[i].size();
    	numSpace = maxWidth- length;
    	if(numWords == 1)
    	{
    		string t;
    		for(i=0; i<numSpace; i++) t += ' ';
    		ans = line[0] + t;
    	}
    	else
    	{
    		string left = " ";
    		string right;
    		for(i=0; i<numSpace - numWords+1; i++) right += ' ';
    		for(i=0; i<numWords-1; i++)
    		{
    			ans = ans + line[i] + left; 
    		}
    		ans = ans + line[numWords-1] + right;
    	}
    	return ans;
    }
};

int main()
{
	vector<string> in;
	in.push_back("ehat");
	in.push_back("must");
	in.push_back("be");
	in.push_back("shall");
	in.push_back("be.");
	//in.push_back("text");
	//in.push_back("justi");
	
	//in.push_back("be.");
	//in.push_back("");
	int width = 12;
	Solution *slt = new Solution();
	vector<string> result;
	result = slt->fullJustify(in, width);
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<<":"<<result[i].size()<<endl;
	}
	return 0;
}
