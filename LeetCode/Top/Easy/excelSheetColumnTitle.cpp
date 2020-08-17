#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define  endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
"ABC"
    
A ... Z : + 26
AA AB AC AD ... AZ: + 26
BA BB BC BD ... BZ: + 26 
.
.
.
ZA ZB ZC ZD ... ZY ZZ: + 26
AAA AAB AAC ... AAZ: + 26
ABA ABB ABC: + 3
*/

class RecursiveSolution {
private:
    vector<string> dict;
public:
    RecursiveSolution(){
        dict.resize(27);
        for (int i=0;i<26;i++){
            char c = 'A'+i;
            dict[i+1].push_back(c);
        }
    }
    
    string convertToTitle(int n) {
        if (n == 0)
            return 0;
        
        return recZ7(n);
    }
    
    string recZ1(int n){
        return dict[n];
    }        
    
    string recZ2(int n) {
        if (n <= 26)
            return recZ1(n);
        
        return dict[n/26] + recZ1(n%26);
    }
    
    string recZ3(int n) {
        if (n <= 26 + round(exp(2*log(26))))
            return recZ2(n);
        
        return dict[n/(int)round(exp(2*log(26)))] + recZ2(n%(int)round(exp(2*log(26))));
    }
    
    string recZ4(int n) {
        if (n <= 26 + round(exp(3*log(26))))
            return recZ3(n);
        
        return dict[n/(int)round(exp(3*log(26)))] + recZ3(n%(int)round(exp(3*log(26))));
    }
    
    string recZ5(int n) {
        if (n <= 26 + round(exp(4*log(26))))
            return recZ4(n);
        
        return dict[n/(int)round(exp(4*log(26)))] + recZ4(n%(int)round(exp(4*log(26))));
    }
    
    string recZ6(int n) {
        if (n <= 26 + round(exp(5*log(26))))
            return recZ5(n);
        
        return dict[n/(int)round(exp(5*log(26)))] + recZ5(n%(int)round(exp(5*log(26))));
    }

    string recZ7(int n) {
        if (n <= 26 + round(exp(6*log(26))))
            return recZ6(n);
        
        return dict[n/(int)round(exp(6*log(26)))] + recZ6(n%(int)round(exp(6*log(26))));
    }
};
// Time: O(1)
// Space: O(1)

class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0)
            return 0;
        
        string ans = "";
        while (n != 0){
            ans.push_back((n-1)%26 + 'A');
            n = (n-1)/26;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
// Time: O(1)
// Space: O(1)

int main(){
    Solution sol;

    assert(sol.convertToTitle(1) == "A");
    assert(sol.convertToTitle(28) == "AB");
    assert(sol.convertToTitle(701) == "ZY");

    cout << "Passed!" << endl;

    return 0;
}
