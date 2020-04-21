#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BinaryMatrix {
private:
    vector<vector<int>> mat;
public:
    BinaryMatrix(vector<int>& values, int n, int m){
        mat.resize(n,vector<int>(m,0));

        int index = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                mat[i][j] = values[index++];
    }

    int get(int x, int y);
    vector<int> dimensions();
};

int BinaryMatrix::get(int x, int y){
    return mat[x][y];
}

vector<int> BinaryMatrix::dimensions(){
    return {(int)mat.size(),(int)mat[0].size()};
}

class BinarySearchSolution { // Binary Search Solution
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
        
        if (n==0 || m==0)
            return -1;
        
        int left = 0;
        int right = m-1;
        while (left<right){
            int mid = left + (right-left)/2;
            bool foundOne = false;
            for (int i=0;i<n;i++){
                if (binaryMatrix.get(i,mid)){
                    foundOne = true;
                    right = mid;
                    break;
                }
            }
            if (!foundOne) 
                left = mid+1;
        }
        
        for (int i=0;i<n;i++)
            if (binaryMatrix.get(i,left))
                return left;
                
        return -1;
    }
};
// Time: O(n*log m)
// Space: O(1)

class Solution { // Optimal Approach
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
        
        if (n==0 || m==0)
            return -1;


        int i = 0;
        int j = m-1;
        int ans = -1;
        while (i<n && j>=0){
            if (!binaryMatrix.get(i,j))
                i++;
            else {
                ans = j;
                j--;
            }
        }

        return ans;
    }
};
// Time: O(n+m)
// Space: O(1)

int main(){
    vector<int> values = {0,0,0,1,0,0,1,1,0,1,1,1};
    int n = 3;
    int m = 4;

    BinaryMatrix matrix(values,n,m);

    Solution sol;
    cout << sol.leftMostColumnWithOne(matrix) << endl;

    return 0;
}

