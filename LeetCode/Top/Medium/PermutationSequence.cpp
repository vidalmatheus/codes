#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WrongSolution { // THAT'S WORNG!!!
public:
    string getPermutation(int n, int k) {
        string nums = "";
        for (char i='1';nums.size()<n;i++)
            nums += i;

        string ans = "";
        int counter = 0;
        permutation(ans,nums,0,counter,k);

        return ans;
    }

    void permutation(string &ans, string &nums, int start, int& counter, int k) {
        if (counter > k)
            return;
        
        if (start == nums.size()) {
            counter++;
            if (counter==k)
                ans = nums;
            return;
        }

        for (int i=start;i<nums.size();i++) {
            swap(nums[start],nums[i]);
            permutation(ans,nums,start+1,counter,k);
            swap(nums[start],nums[i]);
        }
    }
};
// Time: O(n*n!)
// Space: O(n*n!), because of the array as answer

class Solution {
public:
    string getPermutation(int n, int k) {
        string nums = "";
        for (char i='1';nums.size()<n;i++)
            nums += i;
        
        for (int i=0;i<k-1;i++)
            nextPermutation(nums);

        return nums;
    }

    void nextPermutation(string& nums) {
        if (nums.size()==0)
            return;
        
        int pivot = findPivot(nums);
        swapNext(nums,pivot);
        reverseArray(nums,pivot,nums.size()-1);
    }
    
    int findPivot(string& nums){ // Time: O(n) & Space: O(1)
        for (int i=nums.size()-1;i>0;i--){
            if (nums[i-1]<nums[i])
                return i;
        }
        return 0;
    }
    
    void swapNext(string&nums, int pivot){ // Time: O(n) & Space: O(1)
       if (pivot==0)
            return;
        for (int i=nums.size()-1;i>=pivot;i--){
            if (nums[i]>nums[pivot-1]){
                swap(nums[i],nums[pivot-1]);
                break;
            }
        }
    }
    
    void reverseArray(string& nums, int left, int right){ // Time: O(n) & Space: O(1)
        for (int i=left,j=right;i<j;i++,j--)
            if (nums[i]!=nums[j])
                swap(nums[i],nums[j]);
    }

};
// Time: O(n*k)
// Space: O(n)

int main(){
    int n = 3;
    int k = 3;

    WrongSolution sol;
    cout << sol.getPermutation(n,k) << endl;

    return 0;
}
