#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;

        int n = A.size();
        vector<int> freqA(26,0);
        vector<int> freqB(26,0);
        bool repeatedA = false;
        bool repeatedB = false;
        for (int i=0;i<n;i++){
            freqA[A[i]-'a']++;
            freqB[B[i]-'a']++;
            if (freqA[A[i]-'a'] > 1)
                repeatedA = true;
            if (freqB[B[i]-'a'] > 1)
                repeatedB = true;
        }

        if (freqA != freqB)
            return false;

        vector<int> pos;
        for (int i=0;i<n;i++){
            if (A[i] != B[i]){
                pos.push_back(i);
            }
        }

        if (pos.size() == 2 && A[pos[0]] == B[pos[1]] && B[pos[0]] == A[pos[1]])
            return true;

        if (A == B and repeatedA and repeatedB)
            return true;

        return false;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    Solution sol;

    string A = "ab";
    string B = "ba";
    assert(sol.buddyStrings(A,B) == true);

    A = "ab";
    B = "ab";
    assert(sol.buddyStrings(A,B) == false);

    A = "aaaaaaabc";
    B = "aaaaaaacb";
    assert(sol.buddyStrings(A,B) == true);

    A = "";
    B = "a";
    assert(sol.buddyStrings(A,B) == false);

    cout << "Passed!" << endl;
    return 0;
}