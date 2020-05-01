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
    string addBinary(string a, string b) {
        if (a.size()==0)
            return b;
        
        if (b.size()==0)
            return a;

        int nA = a.size();
        int nB = b.size();
        
        int n = max(nA,nB);
        
        if (n==nA)
            for (int i=0;i<n-nB;i++)
                b = '0' + b;
        else 
            for (int i=0;i<n-nA;i++)
                a = '0' + a; 
        
        string ans = "";
        ans.resize(n);
        int carry = 0;
        for (int i=n-1;i>=0;i--){
            int bitA = (a[i]-'0');
            int bitB = (b[i]-'0');
            ans[i] = (bitA^bitB^carry + '0');
            carry = bitA&bitB | carry&(bitA^bitB);
        }
        
        char finalCarry = (carry+'0');
        return carry==1 ? finalCarry + ans : ans;
    }
};
// Time: O(MAX)
// Space: O(MAX)

int main(){
    string a = "11";
    string b = "01";

    Solution sol;
    cout << sol.addBinary(a,b) << endl;

    return 0;
}
