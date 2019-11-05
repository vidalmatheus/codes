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
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (needle.size()>haystack.size()) return -1;
        for (int i=0;i<=haystack.size()-needle.size();i++){
            bool found = true;
            for (int j=0;j<needle.size();j++){
                if (needle[j]!=haystack[i+j]){
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        return -1; // not founded
    }
};
// TIME: O(n*m) --> KMP does in O(n+m)
// SPACE: O(1) 

int main()
{   
    string haystack,needle;
    cin >> haystack;
    cin >>  needle;
    Solution sol;
    cout << "Mine: " << sol.strStr(haystack,needle) << endl;
    const char * h = "hello";
    const char * n = "ll";
    cout << "strStr: " << strstr(h,n) << endl;
    return 0;
}