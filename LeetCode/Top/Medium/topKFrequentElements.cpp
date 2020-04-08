#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size()==1 && k==1)
            return {nums[0]};
        
        unordered_map<int,int> counter;
        
        for (int i=0;i<nums.size();i++){
            if (counter.find(nums[i])==counter.end()) // not found
                counter[nums[i]]=1;
            else counter[nums[i]]++; // found, just count one more ocurrency            
        }

        for (unordered_map<int,int>::iterator it=counter.begin();it!=counter.end();++it)
            cout << "counter[" << it->first << "]: " << it->second << endl;

        vector<int> keys;
        for (unordered_map<int,int>::iterator it=counter.begin();it!=counter.end();++it)
            keys.push_back(it->first);

        priority_queue<pair<int,int>> pq; // max_heap
        // priority_queue <int, vector<int>, greater<int> > pq;  // min_heap

        for (int key:keys){
            pq.push({counter[key],key});
        }

        vector<int> ans;

        for (int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
// Time: O(nlog k)
// Space: O(n)

int main(){
    vector<int> nums = {6,0,1,4,9,7,-3,1,-4,-8,4,-7,-3,3,2,-3,9,5,-4,0};
    int k = 6;

    Solution sol;
    vector<int> ans = sol.topKFrequent(nums,k);

    cout << "[ ";
    for (int e:ans)
        cout << e << " ";
    cout << "]\n";

    return 0;
}