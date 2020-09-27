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

X
XX
XXX
XL

       i
XX V II

int num = 20 + 5 + 2 = 27

*/

class Solution {
private:
    unordered_map<char,int> val;
    
public:
    Solution(){
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
    }
    
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        
        return rec(s,0);
    }
    
    int rec(string& s, int pos){
        if (pos == s.size())
            return 0;
        
        if (pos+2 < s.size() &&s[pos] == s[pos+1] && s[pos+1] == s[pos+2])
            return val[s[pos]]*3 + rec(s,pos+3);
        else if (pos+1<s.size() && s[pos] == s[pos+1])
            return val[s[pos]]*2 + rec(s,pos+2);
        else if (s[pos] == 'I'){
            if (s[pos+1] == 'V')
                return 4+rec(s,pos+2);
            else  if (s[pos+1] == 'X')
                return 9+rec(s,pos+2);
            else return val[s[pos]]+rec(s,pos+1);
        }
        else if (s[pos] == 'X'){
            if (s[pos+1] == 'L')
                return 40+rec(s,pos+2);
            else if (s[pos+1] == 'C')
                return 90+rec(s,pos+2);
            else return val[s[pos]]+rec(s,pos+1);
        }
        else if (s[pos] == 'C'){
            if (s[pos+1] == 'D')
                return 400+rec(s,pos+2);
            else if (s[pos+1] == 'M')
                return 900+rec(s,pos+2);
            else return val[s[pos]]+rec(s,pos+1);
        }
        else return val[s[pos]]+rec(s,pos+1);
    }
};
// Time: O(n)
// Space: O(n)


class BestSolution {
public:    
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        
        int n = s.size();
        int ans = val(s[n-1]);
        for (int i=n-2;i>=0;i--){
            if (val(s[i]) >= val(s[i+1]))
                ans += val(s[i]);
            else ans -= val(s[i]);
        }
        
        return ans;
    }
    
    int val(char c){
        if (c =='I') return 1;
        if (c =='V') return 5;
        if (c =='X') return 10;
        if (c =='L') return 50;
        if (c =='C') return 100;
        if (c =='D') return 500;
        if (c =='M') return 1000;
        return 0;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    BestSolution sol;
    
    assert(sol.romanToInt("LVIII") == 58);
    assert(sol.romanToInt("III") == 3);
    assert(sol.romanToInt("MCMXCIV") == 1994);
    assert(sol.romanToInt("IX") == 9);
    cout << "Passed!" << endl;
    return 0;
}