#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool isSubsequence(string& s, string& p) {
    if (p.size()>s.size())
        return false;
    
    if (p.size()==0)
        return true;
    
    int index = 0; // goes through string s
    for (int j=0;j<s.size();j++){
        if (s[j]==p[index])
            index++;
        if (index==p.size())
            return true;
    }

    return false;
}

int main(){
    string s;
    int q;
    cin >> s;
    cin >> q;
    
    string p;
    string op;
    for (int i=0;i<q;i++){
        cin >> op;
        if (op[1] == 'u'){
            char c;
            cin >> c;
            p.push_back(c);
        }
        else p.pop_back();

        isSubsequence(s,p) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
