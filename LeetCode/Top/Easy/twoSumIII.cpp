#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class FirstTwoSum {
private:
    vector<int> nums;
    unordered_map<int,bool> cache;
public:
    /** Initialize your data structure here. */
    FirstTwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) { // T: O(1) & S: O(1)
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) { // T: O(n) & S: O(n)
        if (cache.find(value) != cache.end())
            return cache[value];
        
        unordered_set<int> seen;
        for (int num : nums){
            // prev + num = value
            if ((long)value-num > INT_MAX || (long)value-num < INT_MIN) continue;
            if (seen.find(value-num) != seen.end())
                return true;
            seen.insert(num);
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

class TwoSum {
private:
    multiset<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) { // T: O(log n) & S: O(1)
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) { // T: O(log n) & S: O(1)
        if (nums.size() == 0) return false;
        
        auto left = nums.begin();
        auto right = --nums.end();
        while (left != right){
            int sum = *left + *right;
            if (sum < value)
                left++;
            else if (sum > value)
                right--;
            else return true;
        }
        
        return false;
    }
};


int main(){
    TwoSum obj;
    obj.add(1);
    obj.add(2);
    obj.add(-3);
    assert(obj.find(3));

    cout << "Passed!" << endl;
    return 0;
}