#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,bool> map;
    int index;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        index = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) { // O(1)
        if (map.find(val) == map.end()){ // not found
            map[val] = true;
            nums.push_back(val);
            return true;
        }
        else if (map.find(val) != map.end() && !map[val]) {
            map[val] = true;
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) { // O(1)
        if (map.find(val) != map.end() && map[val]){ // found
            map[val] = false;
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() { // O(1)
        int randonIndex;
        int val;
        do {
            randonIndex = rand() % nums.size();
            val = nums[randonIndex];            
        } while (!map[val]);
        
        return val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedSet* obj = new RandomizedSet();
    obj->insert(1) ? cout << "true\n" : cout << "false\n";
    obj->remove(2) ? cout << "true\n" : cout << "false\n";
    cout << obj->getRandom() << endl;

    return 0;
}