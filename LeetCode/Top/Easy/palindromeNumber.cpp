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
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i=0,j=(int)s.size()-1;i<j;i++,j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
// Time: O(log x)
// Space: O(1)

class FasterSolution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x%10 == 0 && x != 0))
            return false;
        
        int reverted = 0;
        while (x > reverted){
            reverted = reverted*10+x%10;
            x /= 10;
        }
        
        return reverted == x || reverted/10 == x;
    }
};
// Time: O(log x)
// Space: O(1)


int main(){
    int x = 121;
    Solution sol;
    sol.isPalindrome(x) ? cout << "true\n" : cout << "false\n";

    return 0;
}
