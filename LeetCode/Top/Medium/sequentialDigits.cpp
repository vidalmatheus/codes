#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

100 -> 123
       234

*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if (low > high)
            return {};
        
        vector<int> ans;
        string cur = "";
        string lowString = to_string(low);
        string highString = to_string(high);
        int minNumberOfDigits = lowString.size(); 
        int maxNumberOfDigits = highString.size(); 
        
        for (int amount = minNumberOfDigits; amount<=maxNumberOfDigits; amount++)
            for (int k=1;k<=9;k++)
                rec(ans, cur, 0, amount, k, low, high);
        return ans;
    }
    
    void rec(vector<int>& ans, string& cur, int pos, int n, int dig, int low, int high){
        int num = cur.size() == 0 ? INT_MIN : stoi(cur,nullptr,10);
        if (num > high || dig > 10)
            return;
        
        if (pos == n){
            if (num >= low)
                ans.push_back(num);
            return;
        }
        
        cur.push_back(dig+'0');
        rec(ans, cur, pos+1, n, dig+1, low, high);
        cur.pop_back();    
    }
};
// Time: O(10*9*n)e
// Space: O(n)

int main(){
    Solution sol;
    
    int low1 = 123;
    int high1 = 300;
    vector<int> ans1 = {123,234};
    assert(sol.sequentialDigits(low1,high1) == ans1);

    int low2 = 1000;
    int high2 = 13000;
    vector<int> ans2 = {1234,2345,3456,4567,5678,6789,12345};
    assert(sol.sequentialDigits(low2,high2) == ans2);

    cout << "Passed!" << endl;
    return 0;
}