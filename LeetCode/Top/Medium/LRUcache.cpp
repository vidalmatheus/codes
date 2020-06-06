#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SlowLRUCache {
private:
  int capacity;
  unordered_map<int,int> m;
  list<int> l;
public:
    SlowLRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) { // O(n)
        if (m.find(key)!=m.end()){ // found
            l.remove(key);
            l.push_back(key);
            return m[key];   
        }
        else return -1;
    }
    
    void put(int key, int value) { // O(n)
        if (m.find(key)!=m.end()){ // found
            l.remove(key);
        }
        else if (m.size()==capacity){ // not found and full of capacity
            int least = l.front();
            l.pop_front();
            m.erase(least);
        }
        m[key]=value;
        l.push_back(key);
    }
};

///////////////////////////

struct Node{
    int val;
    Node* prev, *next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class List{
private:
    Node* head = nullptr;
    Node* last = nullptr;
public:
    List(){}

    void remove(Node*& node){
        if (node == head)
            pop_front();
        
        else if (node == last)
            pop_back();

        else if (node->prev!=nullptr && node->next!=nullptr){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            free(node);
        }
    }

    void push_back(int x){
        if (head == nullptr){
            head = new Node(x);
            last = head;
        }
        else {
            last->next = new Node(x);
            last->next->prev=last;
            last=last->next;
        }
    }

    void pop_front(){
        Node* p = head;
        head=head->next;
        if (head!=nullptr)
            head->prev=nullptr;
        free(p);
    }

    void pop_back(){
        Node* p = last;
        last=last->prev;
        if (last!=nullptr)
            last->next=nullptr;
        free(p);
    }

    Node* front(){
        return head;
    }

    Node* back(){
        return last;
    }
};

class LRUCache {
private:
  int capacity;
  unordered_map<int,int> m;
  unordered_map<int,Node*> pos;
  List l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) { // O(1)
        if (m.find(key)!=m.end()){ // found
            l.remove(pos[key]);
            l.push_back(key);
            pos[key]=l.back();
            return m[key];   
        }
        else return -1;
    }
    
    void put(int key, int value) { // O(1)
        if (m.find(key)!=m.end()){ // found
            l.remove(pos[key]);
        }
        else if (m.size()==capacity){ // not found and full of capacity
            int least = l.front()->val;
            l.pop_front();
            m.erase(least);
        }
        m[key]=value;
        l.push_back(key);
        pos[key]=l.back();
    }
};

int main(){
    LRUCache cache = LRUCache( 2 /* capacity */ );

    // cache.put(1, 1);
    // cache.put(2, 2);
    // cout << cache.get(1) << endl;       // returns 1
    // cache.put(3, 3);                    // evicts key 2
    // cout << cache.get(2) << endl;       // returns -1 (not found)
    // cache.put(4, 4);                    // evicts key 1
    // cout << cache.get(1) << endl;       // returns -1 (not found)
    // cout << cache.get(3) << endl;       // returns 3
    // cout << cache.get(4) << endl;       // returns 4

    cout << cache.get(2) << endl;
    cache.put(2,6);
    cout << cache.get(1) << endl;
    cache.put(1,5);
    cache.put(1,2);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;

    return 0;
}
