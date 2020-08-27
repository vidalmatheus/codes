#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.size() == 0)
            return {};
        
        int left = 0;
        int right = A.size()-1;
        vector<int> ans(A.size(),0);
        for (int num : A){
            if (num % 2 == 0){
                ans[left] = num;
                left += 2;
            }
            else {
                ans[right] = num;
                right -= 2;
            }
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)

int main() {
    vector<int> A{4,2,5,7};

    Solution sol;
    vector<int> output = sol.sortArrayByParityII(A);

    for (int num : output)
        cout << num << " ";
    cout << endl;

    int n = A.size();
    bool passed = true;
    for (int i=0;i<n;i++)
        if ((output[i] % 2 == 0 && i % 2 != 0) || (output[i] % 2 != 0 && i % 2 == 0)){
            passed = false;
            break;
        }
    
    if (passed)
        cout << "Passed!" << endl;

    return 0;
}