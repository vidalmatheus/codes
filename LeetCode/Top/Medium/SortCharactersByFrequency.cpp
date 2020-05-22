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
    string frequencySort(string s) {
        if (s.size()==0)
            return "";
        
        // build a frequency map
        unordered_map<char,int> freq;
        freq.reserve(s.size()/2);
        for (int i=0;i<s.size();i++)
            freq[s[i]]++;
        
        // build a max_heap
        vector<pair<int,char>> container;
        container.reserve(freq.size());
        priority_queue<pair<int,char>, vector<pair<int,char>>> pq(less<pair<int,char>>(),move(container)); // max_heap
        for (auto elem:freq)
            pq.push({elem.second,elem.first});
        
        // build answer
        string ans ="";
        while (!pq.empty()){
            pair<int,char> top = pq.top();
            for (int i=0;i<top.first;i++)
                ans += top.second;
            pq.pop();
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    string s = "tree";

    Solution sol;
    cout << sol.frequencySort(s) << endl;

    return 0;
}
