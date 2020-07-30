#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class PriorityQueueSolution { // greedy
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0)
            return 0;
        
        unordered_map<char,int> m;
        for (char t:tasks)
            m[t]++;
        
        priority_queue<int> h;
        for (auto elem:m)
            h.push(elem.second);
        
        int ans = 0;
        while (!h.empty()){
            vector<int> tmp;
            for (int i=0;i<n+1;i++){
                if (!h.empty()){
                    tmp.push_back(h.top()-1);
                    h.pop();
                }
            }
            
            for (auto val:tmp)
                if (val != 0)
                    h.push(val);
            ans += h.empty() ? tmp.size() : n+1;
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

/*
[A,A,A,B,B,B], n = 2

A B I A B I A B
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0)
            return 0;
        
        vector<int> charCounter(26,0);
        for (char c:tasks)
            charCounter[c-'A']++;

        sort(charCounter.begin(),charCounter.end());

        int max_ocurring_number = charCounter.back();

        int tail = 0;
        int i = (int)charCounter.size()-1;
        while (i >= 0 && charCounter[i--] == max_ocurring_number)
            tail++;
        
        int intervals = (max_ocurring_number-1)*(n+1) + tail;

        return max((int)tasks.size(),intervals);
    }
};
// Time: O(n)
// Space: O(log n)

int main(){
    vector<char> tasks{'A','A','A','B','B','B'};
    int n = 2;

    Solution sol;
    cout << sol.leastInterval(tasks,n) << endl;

    return 0;
}
