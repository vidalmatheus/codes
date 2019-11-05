#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool anagrama(string& s1,string& s2) {
        if (s1.size()!=s2.size())
            return false;
        sort(s1.begin(),s1.end());  // O(nlogn)
        sort(s2.begin(),s2.end());  // O(nlogn)
        if (s1==s2) return true;
        else return false;
    }
}; 

int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    Solution sol;
    if (sol.anagrama(s1,s2)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}