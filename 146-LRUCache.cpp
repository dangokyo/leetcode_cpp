#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
class LRUCache{
public:
    LRUCache(int capacity): size(capacity) { }
    
    int get(int key) {
    	int value;
    	unordered_map<int, list<pair<int, int> >::iterator >::iterator PI = map.find(key);
    	if(PI != map.end())
    	{
    		value = PI->second->second;
    	}
    	else return -1;
    	
    	list<pair<int, int> >::iterator LI = PI->second;
    	lruCache.erase(LI);
    	lruCache.push_front(make_pair(key, value));
    	map[key] = lruCache.begin();
    	return value;
        
    }
    
    void set(int key, int value) {
    	unordered_map<int, list<pair<int, int> >::iterator >::iterator PI = map.find(key);
    	
    	if(PI == map.end())
    	{
    		lruCache.push_front(make_pair(key, value));
    		map[key] = lruCache.begin();
    		if(lruCache.size() > this->size) 
			{
				map.erase(lruCache.back().first);
				lruCache.pop_back(); 
			}   		
    	}
    	else
    	{
    		list<pair<int, int> >::iterator LI = PI->second;
    		lruCache.erase(LI);
    		lruCache.push_front(make_pair(key, value));
    		map[key] = lruCache.begin();
    	}
    	return;
    }
    
private:
	int size;
	list<pair<int, int> > lruCache;
	unordered_map<int, list<pair<int, int> >::iterator > map;
};
int main()
{
	LRUCache cache(10);
	cache.set(2, 6);
	cache.set(4, 5);
	cout<<cache.get(2)<<endl;
	cache.set(2, 8);
	cout<<cache.get(2)<<endl;
	return 0;
}
