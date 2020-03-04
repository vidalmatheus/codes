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
    string reverseOnlyLetters(string S) {
        if (S.size() == 0)
            return "";
        int low = 0;
        int high = S.size()-1;
        while (low < high) {
            if (isalpha(S[low]) && isalpha(S[high])) {
                swap(S[low],S[high]);
                low++;
                high--;
            }
            while (!isalpha(S[low]))
                low++;
            while (!isalpha(S[high]))
                high--;
        }
        return S;
    }
};

int main() {
    string S = "7_28]";

    Solution sol;
    cout << sol.reverseOnlyLetters(S) << endl;

    return 0;
}