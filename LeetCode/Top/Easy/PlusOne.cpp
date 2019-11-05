/* Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */
#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/* class Solution { // OVERFLOW!
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size());
        int sum=1;
        for (int i=0;i<digits.size();i++){
            sum +=(int)(exp((digits.size()-1-i)*log(10)))*digits[i];
        }
        for(int i=0;i<digits.size();i++){
            ans[digits.size()-1-i]=( (sum/((int)(exp((i)*log(10)))) )%10);
        }
        return ans;
    }
}; */

class Solution { 
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i=digits.size()-1;i>=0;i--){ // O(n)
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
// TIME: O(n)
// SPACE: O(1)


int main(){
    vector<int> digits={9,9};
    vector<int> ans;
    Solution sol;
    ans = sol.plusOne(digits);
    for(auto e: ans)
        cout << e;
    
    return 0;
}