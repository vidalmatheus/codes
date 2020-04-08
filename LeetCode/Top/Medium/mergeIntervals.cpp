#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==1)
            return intervals;
        
        for (int i=0;i<intervals.size();i++){
            for (int j=i+1;j<intervals.size() && i>=0;j++){
                if (overlaps(intervals[i],intervals[j])){
                    vector<int> range;
                    mergeIntervals(range,intervals[i],intervals[j]);
                    intervals[i]=range;
                    intervals[j]={};
                    i--;
                }
            }
        }    
        
        vector<vector<int>> ans;
        for (int i=0;i<intervals.size();i++){
            if (intervals[i].size()!=0)
                ans.push_back(intervals[i]);
        }
        
        return ans;
    }
    
    bool overlaps(const vector<int>& A, const vector<int>& B){
        if ( A.size()==0 || B.size()==0 || (A[0]<B[0] && A[1]<B[0]) || (B[0]<A[0] && B[1]<A[0]) )
            return false;
        return true;
    }
    
    void mergeIntervals(vector<int>& range, const vector<int>& A, const vector<int>& B){
        range = {min(A[0],B[0]),max(A[1],B[1])};
    }
}; 
// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==1)
            return intervals;
        
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i=1;i<intervals.size();i++){
            if (!overlaps(intervals[i],ans.back()))
                ans.push_back(intervals[i]);
            else {
                vector<int> range;
                mergeIntervals(range,intervals[i],ans.back());
                ans.pop_back();
                ans.push_back(range);
            }
        }

        return ans;
    }
    
    bool overlaps(const vector<int>& A, const vector<int>& B){
        if ( A.size()==0 || B.size()==0 || (A[0]<B[0] && A[1]<B[0]) || (B[0]<A[0] && B[1]<A[0]) )
            return false;
        return true;
    }
    
    void mergeIntervals(vector<int>& range, const vector<int>& A, const vector<int>& B){
        range = {min(A[0],B[0]),max(A[1],B[1])};
    }
}; 
// Time: O(nlog n)
// Space: O(n)


int main(){
    // vector<vector<int>> intervals = {
    //     {1,3},
    //     {2,6},
    //     {8,10},
    //     {15,18}
    // };

    // vector<vector<int>> intervals = {
    //   {1,4},
    //   {4,5}  
    // };

    vector<vector<int>> intervals = {
        {1,4},
        {0,2},
        {3,5}
    };

    Solution sol;
    vector<vector<int>> ans = sol.merge(intervals);

    cout << "[ ";
    for (vector<int> line:ans){
        cout << "[ ";
        for (int e:line)
            cout << e << " ";
        cout << "] ";
    }
    cout << "]\n";

    // vector<int> A = {1,4};
    // vector<int> B = {4,5};

    // vector<int> range;
    // sol.overlaps(A,B) ? cout << "true\n" : cout << "false\n";

    // sol.mergeIntervals(range,A,B);

    // cout << "[ " << range[0] << ", " << range[1] << " ]\n";

    return 0;
}