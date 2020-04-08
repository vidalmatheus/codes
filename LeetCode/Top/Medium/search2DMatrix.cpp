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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[matrix.size()-1][matrix[0].size()-1]<target || target<matrix[0][0])
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = m*n-1;

        while (low <= high){
            int mid = low + (high-low)/2;
            if (target > matrix[mid/n][mid%n])
                low = mid+1;
            else if (target < matrix[mid/n][mid%n])
                high = mid-1;
            else return true;
        }
        
        return false;
    }
};
// Time: O(m*n)
// Space: O(1)

int main() {
    vector<vector<int>> matrix = {
        {1,3}
    };

    int target = 2;

    Solution sol;
    sol.searchMatrix(matrix,target) ? cout << "true\n" : cout << "false\n";

    return 0;
}