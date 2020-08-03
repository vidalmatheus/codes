#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

"a,b,c,a,b,c"
 
  ij
[0,0,0,1,2,3]

*/

void failureFunction(string& p, vector<int>& F){
    F.resize(p.size(),0);
    int i = 0; // prefix
    int j = 1; // suffix
    while (j < p.size()){
        if (p[i] == p[j]){
            F[j] = i+1; // elements
            i++;
            j++;
        }
        else {
            if (i>0)
                i = F[i-1];
            else {   
                F[j] = 0;
                j++;
            }
        }
    }
}

bool kmp(string& s, string& p){
    if (p.size() == 0)
        return true;

    if (p.size() > s.size())
        return false;
    
    vector<int> F;
    failureFunction(p,F);
    int i = 0; // text
    int j = 0; // pattern
    while (i < s.size()){
        if (s[i] == p[j]){
            j++;
            if (j == p.size())
                return true;
            i++;
        }
        else {
            // i = i-j+1; -> Brute force
            // j = 0; -> Brute force
            if (j!=0) j = F[j-1];
            else i++;
        }
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

        cout << p << endl;
        kmp(s,p) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
