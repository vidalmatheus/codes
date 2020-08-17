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

class Solution {
private:
    vector<int> dict;
public:
    Solution(){
        dict.resize(26,0);
        for (int i=0;i<26;i++)
            dict[i] = i+1;
    }
    
    int titleToNumber(string s) {
        if (s.size() == 0)
            return 0;
        
        return recZ7(s);
    }
    
    int recZ1(string s){
        return dict[s[0] - 'A'];
    }        
    
    int recZ2(string s) {
        if (s.size() < 2)
            return recZ1(s);
        
        return 26*dict[s[0] - 'A'] + recZ1(s.substr(1));
    }
    
    int recZ3(string s) {
        if (s.size() < 3)
            return recZ2(s);
        
        return round(exp(2*log(26)))*dict[s[0] - 'A'] + recZ2(s.substr(1));
    }
    
    int recZ4(string s) {
        if (s.size() < 4)
            return recZ3(s);
        
        return round(exp(3*log(26)))*dict[s[0] - 'A'] + recZ3(s.substr(1));
    }
    
    int recZ5(string s) {
        if (s.size() < 5)
            return recZ4(s);
        
        return round(exp(4*log(26)))*dict[s[0] - 'A'] + recZ4(s.substr(1));
    }
    
    int recZ6(string s) {
        if (s.size() < 6)
            return recZ5(s);
        
        return round(exp(5*log(26)))*dict[s[0] - 'A'] + recZ5(s.substr(1));
    }

    int recZ7(string s) {
        if (s.size() < 7)
            return recZ6(s);
        
        return round(exp(6*log(26)))*dict[s[0] - 'A'] + recZ6(s.substr(1));
    }
};
// Time: O(1)
// Space: O(1)

class Solution {
public:
    int titleToNumber(string s) {
        if (s.size() == 0)
            return 0;
        
        int ans = 0;
        int n = s.size();
        for (int i=0;i<n;i++)
            ans += (s[i] - 'A' + 1)*pow(26,n-1-i);
        
        return ans;
    }

};
// Time: O(1)
// Space: O(1)

int main(){
    Solution sol;

    assert(sol.titleToNumber("A") == 1);
    assert(sol.titleToNumber("AB") == 28);
    assert(sol.titleToNumber("ZY") == 701);

    cout << "Passed!" << endl;

    return 0;
}
