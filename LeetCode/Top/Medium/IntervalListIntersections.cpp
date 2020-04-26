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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size()==0 || B.size()==0)
            return {};
        
        int i = 0;
        int j = 0;
        
        vector<vector<int>> ans;
        ans.reserve(max(A.size(),B.size()));
        while (i < A.size() && j < B.size()){
            if (A[i][1]<B[j][0]) // not overlaps (A then B)
                i++;
            else if (B[j][1]<A[i][0]) // not overlaps (B then A)
                j++;
            else {
                int begin = max(A[i][0],B[j][0]);
                int end = min(A[i][1],B[j][1]);
                vector<int> interval{begin,end};
                
                ans.emplace_back(interval);

                if (A[i][1] <= ans.back()[1])
                    i++;
                if (B[j][1] <= ans.back()[1])
                    j++;                 
            } 
         }
        
        return ans;
    }
};
// Time: O(max(n,m))
// Space: O(1), without extra space

int main(){
    vector<vector<int>> A{{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B{{1,5},{8,12},{15,24},{25,26}};

    Solution sol;
    vector<vector<int>> ans = sol.intervalIntersection(A,B);

    for (auto e:ans)
        cout << "[" << e[0] << "," << e[1] << "]" << " ";

    return 0;
}
