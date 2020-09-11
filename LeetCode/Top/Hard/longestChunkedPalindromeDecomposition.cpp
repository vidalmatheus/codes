#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution {
public:    
    int longestDecomposition(string text){
        if (text.size() == 0)
            return 0;
        
        int ans = INT_MIN;
        vector<string> curr = {};
        gen(text,ans,0,curr);

        return ans;
    }
    
    bool isPalindrome(vector<string>& s){ // O(n^2)
        for (int i=0,j=s.size()-1; i<j; i++,j--)
            if (s[i] != s[j])
                return false;
        return true;
    }

    void gen(string& s, int& ans, int start, vector<string>& curr){
        if (start == s.size()){
            if (isPalindrome(curr)){
                ans = max(ans,(int)curr.size());
            }
            return;
        }

        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            curr.push_back(s.substr(start, len));
            gen(s, ans, i+1, curr);
            curr.pop_back();
        }
    }    
};
// Time: O(n^2*n*2^(n-1))
// Space: O(n^2*n*2^(n-1))

int main(){
    BruteForceSolution bfsol;
    string s = "";
    
    s = "ghiabcdefhelloadamhelloabcdefghi";
    assert(bfsol.longestDecomposition(s) == 7);
    cout << "Teste1 - OK" << endl;

    s = "merchant";
    assert(bfsol.longestDecomposition(s) == 1);
    cout << "Teste2 - OK" << endl;

    s = "antaprezatepzapreanta";
    assert(bfsol.longestDecomposition(s) == 11);
    cout << "Teste3 - OK" << endl;

    s = "aaa";
    assert(bfsol.longestDecomposition(s) == 3);
    cout << "Teste4 - OK" << endl;

    cout << "Passed!" << endl;
    return 0;
}