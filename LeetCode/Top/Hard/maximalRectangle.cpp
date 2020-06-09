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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int area = 0;
        for (int i=0;i<n;++i){
            // build the histogram
            vector<int> heights = buildHistogram(matrix,i);            
            area = max(area,largestRectangleArea(heights));
        }
        
        return area;
    }
        
    vector<int> buildHistogram(vector<vector<char>>& matrix, int base){ // Time: O(m*(n-base)) & Space: O(1)
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        vector<int> heights;
        for (int j=0;j<m;++j){
            int height = 0;
            if (matrix[base][j] == '1')
                for (int i=base;i<n;++i){
                    if (matrix[i][j] == '0')
                        break;
                    else height++;
                }
            heights.push_back(height);
        }
        
        return heights;
    }
    
    int largestRectangleArea(vector<int>& heights) { // Time: O(m^2) & Space: O(1)
        if (heights.size() == 0)
            return 0;
        int area = 0;
        for (int i=0;i<heights.size();++i){
            int h = heights[i];    
            int l = i;
            int r = i;
            if (h!=0)
                while (l >= 0 && heights[l] >= h)
                    l--;
                while (r < heights.size() && heights[r] >= h)
                    r++;

                area = max(area,(r-l-1)*h);
        }
        
        return area;
    }

    int largestRectangleAreaOptimal(vector<int>& heights) { // Time: O(m) & Space: O(1)
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
// Time: O(n^2*m) without stack or O(n^2*m + n*m^2) with a stack
// Space: O(m)

class BetterSolution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int area = 0;
        vector<int> heights;
        for (int i=0;i<n;++i){
            // build the histogram
            buildHistogram(matrix,i,heights);            
            area = max(area,largestRectangleArea(heights));
        }
        
        return area;
    }
        
    void buildHistogram(vector<vector<char>>& matrix, int base, vector<int>& heights){ // Time: O(k) & Space: O(1)
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        if (base == 0){
            for (int j=0;j<m;++j){
                int height = 0;
                if (matrix[base][j] == '1')
                    for (int i=base;i<n;++i){
                        if (matrix[i][j] == '0')
                            break;
                        else height++;
                    }
                heights.push_back(height);
            }
        }
        else {
            for (int j=0;j<m;++j){
                int height = 0;
                if (matrix[base][j] == '1'){
                    if (heights[j] > 0)
                        height = heights[j]-1;
                    else {
                        for (int i=base;i<n;++i){
                            if (matrix[i][j] == '0')
                                break;
                            else height++;
                        }
                    }
                }
                heights[j] = height;
            }
        }
    }
    
    int largestRectangleArea(vector<int>& heights) { // Time: O(m) & Space: O(1)
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
// Time: O(n^2*m)
// Space: O(m)

class BestSolution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int area = 0;
        vector<int> heights(m,0);
        for (int i=0;i<n;++i){
            // build the histogram
            buildHistogram(matrix,i,heights);     
            area = max(area,largestRectangleArea(heights));
        }
        
        return area;
    }
        
    void buildHistogram(vector<vector<char>>& matrix, int base, vector<int>& heights){ // Time: O(m) & Space: O(1)
        int m = matrix[0].size();
        
        for(int j=0;j<m;++j){
            heights[j] = matrix[base][j] == '1' ? heights[j]+1 : 0;
        }
    }
    
    int largestRectangleArea(vector<int>& heights) { // Time: O(m) & Space: O(1)
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
// Time: O(n*m)
// Space: O(m)

int main(){
    vector<vector<char>> matrix{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution sol;
    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}
