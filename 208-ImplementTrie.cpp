#include<iostream>
#include<vector>
#include<map>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {end = false; for(int i=0; i<26; i++) next[i]=NULL;}
    //map<char, TrieNode*> next;
    TrieNode *next[26];
    bool end;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        int length = s.size();
        int i;
        TrieNode *cur = root;
        for(i=0; i<length; i++)
        {
                          if(cur->next[s[i]-'a'] != NULL )
                          {
                                                   cout<<"exist:"<<i<<":"<<s[i]<<endl;
                                                   cur = cur->next[s[i]-'a'];
                          }
                          else
                          {
                              TrieNode* tmp = new TrieNode();
                              cout<<"new:"<<i<<":"<<s[i]<<endl;
                              cur->next[s[i]-'a'] = tmp;
                              cur = cur->next[s[i]-'a'];
                          }
        }
        cur->end = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
         int length = key.size();
         int i;
         TrieNode *cur = root;
         for(i=0; i<length; i++)
         {
                  //cout<<i<<":"<<key[i]<<endl;
                  if(cur->next[key[i]-'a'] != NULL)
                  {
                                           cur = cur->next[key[i]-'a'];
                  }
                  else
                  {
                      return false;
                  }
         }
         if(cur->end) return true;
         else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
         int length = prefix.size();
         int i;
         TrieNode *cur = root;
         for(i=0; i<length; i++)
         {
                  if(cur->next[prefix[i]-'a'] != NULL)
                  {
                                           cur = cur->next[prefix[i]-'a'];
                  }
                  else
                  {
                      return false;
                  }
         }
         return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
    Trie trie;
    trie.insert("ab");
    trie.insert("sometime");
    trie.insert("soma");
    cout<<trie.search("a")<<endl;
    cout<<trie.startsWith("a")<<endl;
    cout<<trie.search("some")<<endl;
    cout<<trie.startsWith("som")<<endl;
    getchar();
    return 0;
}
