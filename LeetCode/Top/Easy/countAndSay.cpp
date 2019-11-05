#include <bits/stdc++.h>

using namespace std;

static auto speedUp(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}

class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if (n==0) return "";
        if (n==1) return "1";
        int counter = 1;
        string prev = countAndSay(n-1);
        prev.push_back('0');
        for (int i=0;i<prev.size()-1;i++){
            if (prev[i]!=prev[i+1]){
                ans.append(to_string(counter));
                ans.push_back(prev[i]);
                counter = 1;
            }
            else counter++;
        }
        return ans;
    }
};
// TIME: O(n^2)
// SPACE: O(n) n layers of recursion on call stack

int main(){
    string ans;
    Solution sol;
    for (int n=0;n<10;n++)
        cout << sol.countAndSay(n) << endl;

}