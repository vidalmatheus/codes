#include <bits/stdc++.h>
using namespace std;
/*
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.

The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

capacity = 3
set(1, 10)
set(5, 12)
set(4,8)
get(5)        returns 12
get(1)        returns 10
get(10)       returns -1
set(6, 14)    this pushes out key = 5 as LRU is full. 
get(5)        returns -1 
*/

/*
capacity: 3
[1]:<10> 
[5]:<12>
[4]:<8>

<key,node>

         h     p     e
list: { [4]<->[5]<->[1]<->null}

stack: { [1] [5] [1] }

hash_map: < key:int, value:int >, fast look-up O(1)

l.front() -> head
l.back()
l.push_front();
l.push_back();
l.remove(int val);
l.pop_front();
l.pop_back();
*/

class LRUCache{
private:
  int capacity;
  unordered_map<int,int> m;
  list<int> l;
public:
  LRUCache(int capacity);
  int get(int key);
  void set(int key, int value);
};

LRUCache::LRUCache(int capacity) {
  this->capacity = capacity;
}

int LRUCache::get(int key) {
  if (m.find(key)!=m.end()){ // found
      l.remove(key);
      l.push_back(key);
      return m[key];   
  }
  else return -1;
}

void LRUCache::set(int key, int value) {

}
