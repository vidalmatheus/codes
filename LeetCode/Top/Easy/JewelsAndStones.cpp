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
    int numJewelsInStones(string J, string S) {
        if (J.size()==0)
            return 0;
        
        unordered_set<char> jewels;
        for (char c:J)
            jewels.insert(c);
        
        int counter = 0;
        for (char c:S)
            if (jewels.find(c)!=jewels.end()) // found
                counter++;
        
        return counter;
    }
};
// Time: O(m)
// Space: O(n)

int main(){
    string J = "aA";
    string S = "aAAbbbb";

    Solution sol;
    cout << sol.numJewelsInStones(J,S) << endl;

    return 0;
}
