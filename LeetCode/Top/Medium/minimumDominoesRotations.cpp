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
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int minSwaps = min(
            numSwaps(A[0],A,B),
            numSwaps(B[0],A,B)
        );
        minSwaps = min(minSwaps, numSwaps(B[0],B,A));
        minSwaps = min(minSwaps, numSwaps(A[0],B,A));
        
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
    
    int numSwaps (int target, const vector<int> &A, const vector<int> &B) {
        int numSwaps = 0;
        
        for (int i=0;i<A.size();i++){
            if (A[i]!=target && B[i]==target)
                numSwaps++;
            else if (A[i]!=target && B[i]!=target)
                return INT_MAX;
        }
        
        return numSwaps;
    }
};
// Time: O(n)
// Space: O(1)

int main() {
    vector<int> A = {2,1,2,4,2,2};
    vector<int> B = {5,2,6,2,3,2};

    Solution sol;
    cout << sol.minDominoRotations(A,B) << endl;

    return 0;
}