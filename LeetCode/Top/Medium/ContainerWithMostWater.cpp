#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution { // Time Limit Exceeded
public:
    int maxArea(vector<int>& height) {
        if (height.size()==0)
            return 0;
        
        int maxArea = INT_MIN;
        for (int i=0;i<height.size()-1;i++){
            for (int j=i+1;j<height.size();j++){
                maxArea = max(maxArea,area(height,i,j));
            }
        }
        
        return maxArea;
        
    }
    
    int area(vector<int>& height, int i, int j){
        int b = abs(j-i);
        int h = min(height[i],height[j]);
        
        return b*h;    
    }
};
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size()==0)
            return 0;
        
        int maxArea = INT_MIN;
        for (int i=0,j=height.size()-1;i<j;){
            maxArea = max(maxArea,area(height,i,j));
            height[i]<height[j] ? i++ : j--;
        }
        
        return maxArea;   
    }
    
    int area(vector<int>& height, int i, int j){
        int b = abs(j-i);
        int h = min(height[i],height[j]);
        
        return b*h;    
    }
};
// Time: O(n)
// Space: O(1)
// Time: O()
// Space: O(1)

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution sol;
    cout << sol.maxArea(height) << endl;

    return 0;
}
