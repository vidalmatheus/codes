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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> h;
        
        for (int i=0;i<k;i++){
            h.push(make_pair(dist(points[i]),points[i]));
        }
        
        for (int i=k;i<(int)points.size();i++){
            if (dist(points[i])<h.top().first){
            h.pop();
            h.push(make_pair(dist(points[i]),points[i]));
            }
        }
        
        vector<vector<int>> ans;
        for (int i=0;i<k;i++){
            ans.push_back(h.top().second);
            h.pop();
        }
        
        return ans;
    }

    double dist (vector<int>& point){
        return point[0]*point[0] + point[1]*point[1];
    }
};
// max_heap solution -> Time: O(n*log(k)), Space: O(k)
// pops: Time: O(k), Space: O(k)

// Overall: Time: O(n*log(k)), Space: O(k) 

int main() {
  vector<vector<int>> points = {{0,1} , {3,4}, {1,1}, {0,3}};
  int k = 2;
  
  Solution sol;
  vector<vector<int>> ans = sol.kClosest(points,k);
  
  for (auto p:ans){
    cout << "<" << p[0] << ", " << p[1] << ">  ";
  }
  
  return 0;
}
