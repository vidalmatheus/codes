#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[2,7,4,1,8,1]

max_heap: {2,4,1,1}
top: 
y:8
x:7
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size()==0)
            return 0;
        
        priority_queue<int> h;
        for (int i=0;i<stones.size();i++)
            h.push(stones[i]);
        
        while (h.size()>1){
            int y = h.top();
            h.pop();
            int x = h.top();
            h.pop();
            if (x<y)
                h.push(y-x);
        }
        
        return h.size()>0 ? h.top() : 0;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    
    Solution sol;
    cout << sol.lastStoneWeight(stones) << endl;

    return 0;
}
