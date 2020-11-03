#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


void FailureFunction(string &needle, vector<int> &F){
    F[0]=0;
    int i = 0; // index that goes through the prefixes
    int j = 1; // index that goes thorugh the sufixes
    while (j<needle.size()){
        if (needle[i]==needle[j]){
            F[j++]=++i;
        }
        else {
            if (i==0)
                F[j++]=0;
            else i=F[i-1]; // recursive call
        }
    }
}

vector<int> KMPMatch(string &haystack, string &needle){
    if (needle.empty()) return {};
    if (needle.size()>haystack.size()) return {};
    vector<int> ans;
    vector<int> F(needle.size()); // preprocessing wich cost (Space: O(m))
    FailureFunction(needle,F);    // preprocessing wich cost (Time: O(m))
    int i=0; // goes through haystack
    int j=0; // goes thorugh needle
    while (i<haystack.size()){
        if (haystack[i]==needle[j]){ // if we have a letter match
            if (j == needle.size()-1) // if we achieved the end of the needle, then just return the begin's index in the haystack
                ans.push_back(i-j);
            else i++; j++; // increment i and j, just like on the naive approach
            // j is incremented at maximum n times
        }
        else {  // if we have a mismatch
            if (j!=0)
                j = F[j-1]; // executed at maximum n times as well
            else i++;
        }
    }
    return ans;
}


int main(){
    string str;
    cin >> str;
    string pattern = "happiness";
    vector<int> ans = KMPMatch(str,pattern);

    if (ans.size() >= 3)
        cout << "NO" << endl;
    else if (ans.size() == 2) {
        cout << "YES" << endl;
        cout << ans[0]+1 << " " << ans[1]+2 << endl;
    }
    else if (ans.size() == 1){
        cout << "YES" << endl;
        cout << ans[0]+1 << " " << ans[0]+2 << endl;
    }
    else {
        // find two equal letters
        unordered_map<char, int> seen;
        for (int i=0;i<str.size();i++){
            char c = str[i];
            if (seen.find(c) != seen.end()){
                cout << "YES" << endl;
                cout << seen[c]+1 << " " << i+1 << endl;
                return 0;
            }
            seen[c] = i;
        }
        
        // all characters are different
        cout << "YES" << endl;
        cout << "1 2" << endl;
    }

    return 0;
}