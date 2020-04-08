#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution_BinarySearch {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size()<3)
            return 0;
        
        // longest side = a < b + c
        sort(nums.begin(),nums.end()); // O(nlg n)
        
        int counter = 0;
        
        for (int i=0;i<nums.size()-2;i++){
            for (int j=i+1;j<nums.size()-1 && nums[i]!=0; j++){
                int k = binarySearch(nums,i+2,nums.size()-1,nums[i]+nums[j]);
                counter+=(k-1) - (j+1) + 1;
            }
        }
        
        return counter;
    }
    
    int binarySearch(vector<int> &nums, int low, int high, int x){
        while (low <= high && high<nums.size()){
            int mid = low + (high-low)/2;
            if (x<=nums[mid])
                high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
};
// Time: O(n^2*log n)
// Space: O(log n)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int counter=0;
        sort(nums.begin(),nums.end()); // Time: O(nlog n) and Space: O(log n)
        for (int i=0;i<(int)nums.size()-2;i++){
            int k = i+2;
            for (int j=i+1;j<nums.size()-1 && nums[i]!=0;j++){
                while (k<nums.size() && nums[i]+nums[j]>nums[k])
                    k++;
                counter+=(k-1)-(j+1)+1;
            }
        }

        return counter;
    }
};
// Time: O(n^2)
// Space: O(log n)

int main(){
    // vector<int> nums = {1,2,3,4,5,6};
    vector<int> nums = {1};

    Solution sol;
    cout << sol.triangleNumber(nums) << endl;

    return 0;
}