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
    bool isHappy(int n) {
        if (n==1)
            return true;
        
        int next = squareDigits(n);
        unordered_set<int> s;
        while (next!=1){
            next = squareDigits(next);
            if (s.find(next)==s.end()) // not found
                s.insert(next);
            else return false;
        }
        
        return true;
    }
    
    int squareDigits(int n){
        int sum = 0;
        while (n!=0){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        
        return sum;
    }
    
};
// Time : O(N*m)
// Space: O(m)

int main(){
    int n = 19;

    Solution sol;
    sol.isHappy(n) ? cout << "true\n" : cout << "false\n";

    return 0;
}