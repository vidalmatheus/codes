#include<bits/stdc++.h>

using namespace std;

static auto speedUp(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}

class Solution {
public:
    list<int> KMPMatch(string &haystack, string &needle){
        if (needle.empty()) return {};
        if (needle.size()>haystack.size()) return {};
        list<int> ans;
        vector<int> F(needle.size()); // preprocessing wich cost (Space: O(m))
        FailureFunction(needle,F);    // preprocessing wich cost (Time: O(m))
        for (auto e:F) cout << e << " ";
        cout << endl;
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
};
// TIME: O(n+m)
// SPACE: O(m)


int main(){
    string haystack, needle;
    getline(cin, haystack);
    cin >> needle;
    Solution sol;
    list<int> ans = sol.KMPMatch(haystack, needle);
    
    if (ans.size()==0)
        cout << "No matches" << endl;
    else {
        for (auto i:ans)
            cout << "Pos: " << i << endl;
    }

    return 0;
}
