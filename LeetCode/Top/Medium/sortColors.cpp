#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution_CountingSort { // Counting Sort (2-pass algorithm)
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for (int i=0;i<nums.size();i++){
            if (nums[i]==0)
                zeros++;
            if (nums[i]==1)
                ones++;
            if (nums[i]==2)
                twos++;
        }
        
        for (int i=0;i<nums.size();i++){
            if (i<zeros)
                nums[i]=0;
            if (i>=zeros && i<zeros+ones)
                nums[i]=1;
            if (i>=zeros+ones && i<zeros+ones+twos)
                nums[i]=2;
        }
    }
};
// Time: O(n)
// Space: o(1)

class Solution { // one-pass algorithm
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        int i = 0;
        while (i<=p2 && p0<p2){
            if (nums[i]==0){
                swap(nums[p0],nums[i]);
                p0++;
                i++;
            }
            else if (nums[i]==2){
                swap(nums[p2],nums[i]);
                p2--;
            }
            else // nums[i]==1
                i++;
        }
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> nums = {2,0,2,1,1,0};

    for (int e:nums)
        cout << e << " ";
    cout << endl;

    Solution sol;
    sol.sortColors(nums);

    for (int e:nums)
        cout << e << " ";
    cout << endl;

    return 0;
}