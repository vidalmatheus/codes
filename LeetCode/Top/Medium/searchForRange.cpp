#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution_Linear {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0 || target > nums[nums.size()-1] || target < nums[0])
            return {-1,-1};
        
        vector<int> ans;
        bool found = false;
        int start = 0;
        int end = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==target){
                found = true;
                start = i;
                for (int j=i;j<nums.size();j++){
                    if (nums[j]==target)
                        end = j;
                }
                break;
            }
        }
        
        ans.push_back(start);
        ans.push_back(end);
        
        if (found)
            return ans;
        else return {-1,-1};
    }
};
// Time: O(n)
// Space: O(1)

class AlmostBetterSolution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0 || target > nums[nums.size()-1] || target < nums[0])
            return {-1,-1};
        
        bool found = false;
        
        int low = 0;
        int high = nums.size()-1;
        while (low<high){
            int mid = low + (high-low)/2;
            if (target <= nums[mid])
                high = mid;
            else  //(nums[mid] < target)
                low = mid+1;
        }
        
        if (nums[low] == target){
            int start = low;
            int end = low;
            while (start>0 && nums[start-1]==target)
                start--;
            while (end<nums.size()-1 && nums[end+1]==target)
                end++;

            return {start,end};
        }

        return {-1,-1};
    }
};
// Time: O(n)
// Space: O(1)

class Solution {
private:
    const int START = 0;
    const int END = 1;
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0)
            return {-1,-1};

        int start = searchPos(nums,target,START);
        if (start==-1)
            return {-1,-1};
        else return {start,searchPos(nums,target,END)};
    }

    int searchPos(vector<int>& nums, int target, int pos){
        int left = 0;
        int right = nums.size()-1;

        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if (target>nums[mid])
                left = mid+1;
            else if (target<nums[mid])
                right = mid-1;
            else{
                if (pos==START)
                    if (mid>=1 && nums[mid-1]==target)
                        right=mid-1;
                    else{ 
                        ans = mid;
                        break;
                    }
                else //pos==END
                    if (mid<nums.size()-1 && nums[mid+1]==target)
                        left=mid+1;
                    else{
                        ans=mid;
                        break;
                    }
            }
        }

        return ans;
    }   
};
// Time: O(log n)
// Space: O(1)

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    // vector<int> nums = {1};
    // int target = 1;

    Solution sol;
    vector<int> ans = sol.searchRange(nums,target);

    cout << "[ ";
    for (int e:ans)
        cout << e << " ";
    cout << "]" << endl;

    return 0;
}