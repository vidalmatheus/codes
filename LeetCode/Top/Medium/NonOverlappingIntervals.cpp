#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


struct myComparator {
  bool operator () (vector<int>& e1, vector<int>& e2){
      return e1[1]<e2[1];
  }  
};

class Solution { // Greedy!!!
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size()==0)
            return 0;
        
        
        struct myComparator obj;
        sort(intervals.begin(),intervals.end(), obj); // for sort is the object, for priority queue is the class (struct)
        
        vector<bool> cut(intervals.size(),false);
        int prev = 0;
        for (int i=1;i<intervals.size();i++){
            if (intervals[prev][1]>intervals[i][0]){ // if they overlaps each other
                cut[i]=true;
            }
            else prev = i;
        }
        
        int min = 0;
        for (int i=0;i<cut.size();i++)
            if(cut[i])
                min++;
        
        return min;
    }   
};
// Time: O(nlog n)
// Space: O(n)

int main(){
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals) << endl;

    return 0;
}
