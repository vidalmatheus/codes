#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstUniqueFirstApproach {
private:
    vector<int> nums;
public:
    FirstUniqueFirstApproach(vector<int>& nums) {
        this->nums = nums;
    }
    
    int showFirstUnique() {
        unordered_map<int,pair<int,int>> hashMap;
        priority_queue<int,vector<int>,greater<int>> heap;
        int firstUnique = -1;
        for (int i=0;i<nums.size();i++){ // O(n)
            if (hashMap.find(nums[i])!=hashMap.end()) // found
                hashMap[nums[i]].first++;
            else {
                hashMap[nums[i]].first = 1;
                hashMap[nums[i]].second = i;
            }
        }
        
        int firstUniqueIndex = nums.size();
        for (auto elem:hashMap) // O(n)
            if (elem.second.first == 1)
                firstUniqueIndex = min(firstUniqueIndex,elem.second.second);
        
        return firstUniqueIndex < nums.size() ? nums[firstUniqueIndex] : -1;
    }
    
    void add(int value) {
        nums.emplace_back(value);
    }
};

class FirstUnique {
private:
    unordered_map<int,int> hashMap;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) { // Time: O(n) & Space: O(n)
        for (int i=0;i<nums.size();++i){ // O(n)
            if (hashMap.find(nums[i])!=hashMap.end()) // found
                hashMap[nums[i]]++;
            else{ 
                hashMap[nums[i]]= 1;
                q.push(nums[i]);
            }
        }
        
        
    }
    
    int showFirstUnique() { // T:O(n) & S:O(1)
        while (!q.empty()){
            int val = q.front();
            if (hashMap[val]==1)
                return val;
            else q.pop();
        }
        return -1;
    }
    
    void add(int value) { // T:O(1) & S:O(1)
        if (hashMap.find(value)!=hashMap.end())
            hashMap[value]++;
        else hashMap[value]=1;
        q.push(value);
    }
};

int main(){
    vector<int> nums{2,3,5};

    FirstUnique* obj = new FirstUnique(nums);
    cout << obj->showFirstUnique() << endl;
    obj->add(5);

    return 0;
}
