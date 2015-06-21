#include<iostream>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {end = false; for(int i=0; i<26; i++) next[i]=NULL;}
    //map<char, TrieNode*> next;
    TrieNode *next[26];
    bool end;
};

class WordDictionary {
public:

	WordDictionary() {root = new TrieNode();}

    // Adds a word into the data structure.
    void addWord(string word) {
        int length = word.size();
        int i;
        TrieNode *cur = root;
        for(i=0; i<length; i++)
        {
                          if(cur->next[word[i]-'a'] != NULL )
                          {
                                                   cur = cur->next[word[i]-'a'];
                          }
                          else
                          {
                              TrieNode* tmp = new TrieNode();
                              cur->next[word[i]-'a'] = tmp;
                              cur = cur->next[word[i]-'a'];
                          }
        }
        cur->end = true;
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	return SearchSolver(root, word);
    }
    
    bool SearchSolver(TrieNode* t, string s)
    {
    	int length = s.size();
    	if(length == 0) return t->end;
    	
    	int i;
    	TrieNode *cur = t;
    	for(i=0; i<length; i++)
    	{
    		if(s[i] == '.')
    		{
    			string t = s.substr(i+1, length-i);
    			for(int j=0; j<26; j++)
				{
					if(cur->next[j] != NULL)
					{
						if(SearchSolver(cur->next[j], t)) return true;
					}
				}
				return false;
    		}
    		else
    		{
					if(cur->next[s[i]-'a'] != NULL)
                  	{
                    	cur = cur->next[s[i]-'a'];
                  	}
                  	else
                  	{
                    	return false;
                  	}
    		}
    	}
    	return cur->end;
    }
    
private:
	TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");




int main()
{
	WordDictionary dict;
	dict.addWord("bad");
	dict.addWord("dad");
	dict.addWord("mad");
	dict.addWord("bap");
	cout<<dict.search("pad")<<endl;
	cout<<dict.search("bad")<<endl;
	cout<<dict.search(".ad")<<endl;
	cout<<dict.search("b..")<<endl;
	cout<<dict.search(".a.")<<endl;
	
	return 0;
}
