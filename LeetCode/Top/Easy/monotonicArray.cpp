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
    bool isMonotonic(vector<int>& A) {
        int size = A.size();
        int increasing = 0;
        int decreasing = 0;
        for (int i=1;i<size;i++){
            if (A[i-1] <= A[i])
                increasing++;
            if (A[i-1] >= A[i])
                decreasing++;
        }
        
        return increasing == size-1 || decreasing == size-1;
    }
};
// Time: O(n)
// Space: O(1)

class BetterSolution {
public:
    bool isMonotonic(vector<int>& A) {
        int size = A.size();
        bool increasing = false;
        bool decreasing = false;
        int i = 1;
        while (i < size && !increasing && !decreasing){
            if (A[i-1] < A[i]){
                increasing = true;
                break;
            }
            
            if (A[i-1] > A[i]){
                decreasing = true;
                break;
            }
            i++;
        }

        while (i < size && (increasing || decreasing)){
            if (increasing && A[i-1] > A[i])
                return false;

            if (decreasing && A[i-1] < A[i])
                return false;    
            i++;
        }
        
        return true;
    }
};
// Time: O(n)
// Space: O(1)


int main(){
    vector<int> nums{1,2,2,3};

    Solution sol;
    sol.isMonotonic(nums) ? cout << "true\n" : cout << "false\n";

    return 0;
}
