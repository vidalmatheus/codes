#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct myComparator {
    bool operator() (pair<int,string>& e1, pair<int,string>& e2) {
        if (e1.first!=e2.first)
            return e1.first>e2.first; // true if the first element is greater than the next
        else return e1.second<e2.second; // true if the first element is smaller than the next
    }  
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if (k==0)
            return {};
        
        unordered_map<string,int> m;
        for (int i=0;i<words.size();i++){
            if (m.find(words[i])==m.end()) // not found
                m[words[i]]=1;
            else m[words[i]]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, struct myComparator> h; // min_heap
        
        for (auto e:m){
            if (h.size()<k)
                h.push(make_pair(e.second,e.first));
            else if (e.second>h.top().first || (e.second==h.top().first && e.first<h.top().second)){
                h.pop();
                h.push(make_pair(e.second,e.first));
            }
        }
        
        vector<string> ans(k);
        for (int i=k-1;i>=0;i--){
            ans[i]=(h.top().second);
            h.pop();
        }
        
        return ans;    
    }
};
// Time: O(n*log(k))
// Space: O(n), because of the hashmap

int main(){
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution sol;
    vector<string> ans = sol.topKFrequent(words,k);

    for (string w:ans)
        cout << w << " ";
    cout << endl;

    return 0;
}
