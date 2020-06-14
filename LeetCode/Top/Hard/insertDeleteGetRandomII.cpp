#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int,unordered_set<int>> numToIndex;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) { // O(1)
        nums.push_back(val);
        numToIndex[val].insert((int)nums.size()-1);
        return numToIndex[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) { // O(1)
        if (numToIndex[val].size() == 0) 
            return false;
                
        int targetIndex = *numToIndex[val].begin();
        numToIndex[val].erase(targetIndex);
        
        int lastIndex = nums.size()-1;
        if (targetIndex != lastIndex){ // if it's not at the last index
            numToIndex[nums.back()].erase(lastIndex);
            numToIndex[nums.back()].insert(targetIndex);
            swap(nums[targetIndex],nums[lastIndex]);
        }

        nums.pop_back();
        return true;  
    }
    
    /** Get a random element from the collection. */
    int getRandom() { // O(1)
        if (nums.size() == 0)
            return -1;
        int randonIndex = rand() % nums.size();
        return nums[randonIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedCollection* obj = new RandomizedCollection();
    obj->insert(1) ? cout << "true\n" : cout << "false\n";
    obj->remove(1) ? cout << "true\n" : cout << "false\n";
    cout << obj->getRandom() << endl;

    return 0;
}