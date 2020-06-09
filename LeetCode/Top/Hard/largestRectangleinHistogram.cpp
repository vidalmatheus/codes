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
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        
        bool allEqual = true;
        for (int i=1;i<heights.size();++i)
            if (heights[i-1] != heights[i])
                allEqual = false;
        
        if (allEqual)
            return heights[0]*heights.size();

        int area = 0;
        for (int i=0;i<heights.size();++i){
            int h = heights[i];    
            int l = i;
            int r = i;
            if (h!=0){
                while (l >= 0 && heights[l] >= h)
                    l--;
                while (r < heights.size() && heights[r] >= h)
                    r++;

                area = max(area,(r-l-1)*h);
            }
        }
        
        return area;
    }
};
// Time: O(n^2)
// Space: O(1)

class BetterSolution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)
            return 0;
        
        int maxArea = 0;
        stack<int> s;
        s.push(0);
        for (int i=1;i<heights.size();++i){
            int curr = heights[i];
            if (curr >= heights[s.top()])
                s.push(i);
            else {
                while (!s.empty() && curr < heights[s.top()]){
                    int h = heights[s.top()];
                    s.pop();
                    maxArea = max(maxArea,s.empty() ? h*i : h*(i-1-s.top())); // h*(i-1 -(s.top()+1) +1)    
                }
                s.push(i);
            }
        }
        
        int i = heights.size();
        while (!s.empty()){
            int h = heights[s.top()];
            s.pop();
            maxArea = max(maxArea,s.empty() ? h*i : h*(i-1-s.top()));
        }
        
        return maxArea;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> heights{2,1,5,6,2,3};

    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}
