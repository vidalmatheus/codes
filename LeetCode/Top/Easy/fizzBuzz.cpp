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
    vector<string> fizzBuzz(int n) {
        if (n == 0)
            return {};
        
        vector<string> ans(n,"");
        for (int i=1;i<=n;i++){
            if (i % 3 == 0 && i % 15 != 0)
                ans[i-1] = "Fizz";
            else if (i % 5 == 0 && i % 15 != 0)
                ans[i-1] = "Buzz";
            else if (i % 15 == 0)
                ans[i-1] = "FizzBuzz";
            else ans[i-1] = to_string(i);
        }
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

class RecursiveSolution { // just for trainning
public:
    vector<string> fizzBuzz(int n) {
        if (n == 0)
            return {};
        
        string curr = "";
        if (n % 3 == 0 && n % 15 != 0)
            curr = "Fizz";
        else if (n % 5 == 0 && n % 15 != 0)
            curr = "Buzz";
        else if (n % 15 == 0)
            curr = "FizzBuzz";
        else curr = to_string(n);
        
        vector<string> ans = fizzBuzz(n-1);
        ans.push_back(curr);
        
        return ans;
    }
};
// Time: O(n^2)
// Space: O(n^2)

int main() {
    Solution sol;
    int n = 15;
    vector<string> ans{
            "1",
            "2",
            "Fizz",
            "4",
            "Buzz",
            "Fizz",
            "7",
            "8",
            "Fizz",
            "Buzz",
            "11",
            "Fizz",
            "13",
            "14",
            "FizzBuzz"
        };
    
    assert(sol.fizzBuzz(n) == ans);
    cout << "Passed!" << endl;
    return 0;
}
