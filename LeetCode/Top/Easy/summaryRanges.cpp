#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[0 2 3 4 6 8 9]

ans: "0", "2->4", "6"
range: "8"
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<string> ans;
        string range = "";
        for (int i=0;i<n;i++){
            // if first or the beginning of the range
            if (i == 0 || nums[i] - 1 != nums[i-1]){
                range += to_string(nums[i]);
                // if the range starts at the final element
                if (i == n-1 || i+1 < n && nums[i] + 1 != nums[i+1]){
                    ans.push_back(range);
                    range = "";
                }
            }
            // if it is the final element of the range in the middle or at the end
            else if ((i+1 < n && nums[i] + 1 != nums[i+1]) || (i == n-1 && nums[i-1] + 1 == nums[i])){
                range += "->" + to_string(nums[i]);
                ans.push_back(range);
                range = "";
            }
        }

        return ans;
    }
};
// Time: o(n)
// Space: O(1), extra space

int main() {
    Solution sol;

    vector<int> nums1{0,1,2,4,5,7};
    vector<int> nums2{0,2,3,4,6,8,9};
    vector<int> nums3{};
    vector<int> nums4{-1};

    vector<string> ans1{"0->2","4->5","7"};
    vector<string> ans2{"0","2->4","6","8->9"};
    vector<string> ans3{};
    vector<string> ans4{"-1"};

    assert(sol.summaryRanges(nums1) == ans1);
    assert(sol.summaryRanges(nums2) == ans2);
    assert(sol.summaryRanges(nums3) == ans3);
    assert(sol.summaryRanges(nums4) == ans4);

    cout << "Passed!" << endl;
    return 0;
}