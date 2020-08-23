#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        
        int n = s.size();
        int i;
        for (i=n-1;i>=0 && s[i]==' ';i--);
        if (i<0) return 0;
        int end = i;
        for (;i>=0 && s[i]!=' ';i--);
        
        return end-i;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string s = "Hello world";
    Solution sol;
    assert (sol.lengthOfLastWord(s) == 5);
    cout << "Passed!" << endl;

    return 0;
}
