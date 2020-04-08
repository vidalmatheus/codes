#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution_TimeLimitExceeded {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[matrix.size()-1][matrix[0].size()-1]<target || target<matrix[0][0])
            return false;
        
        for (vector<int> line:matrix){
            if (binarySearch(line,target))
                return true;
        }

        return false;   
    }

    bool binarySearch (vector<int> &nums, int target){
        if (nums[nums.size()-1]<target || target<nums[0])
            return false;
        
        int low = 0;
        int high = nums.size()-1;

        while (low <= high){
            int mid = low+(high-low)/2;
            if (target < nums[mid])
                high = mid-1;
            else if (target > nums[mid])
                low = mid +1;
            else return true;
        }

        return false;
    }
};
// Time: O(m*log(n))
// Space: O(1)

class Solution { 
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[matrix.size()-1][matrix[0].size()-1]<target || target<matrix[0][0])
            return false;

        int row = matrix.size()-1;
        int col = 0;

        while (row>=0 && col<matrix[0].size()){
            if (target > matrix[row][col])
                col++;
            else if (target < matrix[row][col])
                row--;
            else return true;
        }
        
        return false;
    }
};
// Time: O(n+m)
// Space: O(1)

int main(){

    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 20;

    Solution sol;
    sol.searchMatrix(matrix,target) ? cout << "true\n" : cout << "false\n";

    return 0;
}