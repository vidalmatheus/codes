#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if (A.size() == 0)
            return 0;
    
        sort(A.begin(),A.end());
        
        int left = 0;
        int right = A.size()-1;
        int s = -1;
        while (left < right){
            if (A[left] + A[right] < K){
                s = max(s, A[left] + A[right]);
                left++;
            }
            else {
                right--;
            }
        }
        
        return s;
    }
};
// Time: O(n*log n)
// Space: O(log n) -> O(n), depending on the implementation of the sorting algorithm

int main(){
    Solution sol;

    vector<int> A1{34,23,1,24,75,33,54,8};
    int k1 = 60;
    assert(sol.twoSumLessThanK(A1,k1) == 58);

    vector<int> A2{10,20,30};
    int k2 = 15;
    assert(sol.twoSumLessThanK(A2,k2) == -1);

    cout << "Passed!" << endl;
    return 0;
}