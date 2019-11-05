#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

/* class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // nums = {1,2,3,4,5,6,7};
        // Naive Solution:
        // 1) make a map of k values to be rotate
        // 2) shift k positions the elements of primary vector
        // 3) put k values of set created to the first k spaces of primary vector
        // 1,2,3,4 ; k=5
        // 4,1,2,3
        // 3,4,1,2
        // 2,3,4,1
        // 1,2,3,4
        // 4,1,2,3
        if (k!=nums.size()){
            if (k>nums.size())
                k = k%nums.size();

            map<int,int> m;
            for(int i=nums.size()-1,j=k-1;i>nums.size()-1-k;i--,j--){ // --> O(log(k))
                m.insert(make_pair(j,nums[i]));
            }
            // Now we've done the step 1

            for(auto a:m)
                cout << a.first << " " << a.second << endl;

            // shift
            for (int i=nums.size()-1-k;i>=0;i--)                      // --> O(k)
                nums[i+k]=nums[i];
            // step 2 done

            for (auto a:nums)
                cout << a << " ";

            cout << endl;
            // Then finally we put back the k final values back in nums
            for (int i=0;i<k;i++)                                     // --> O(k)
                nums[i]=m[i];
        }
    }
}; */
// TIME: O(log(k))
// SPACE: O(k)

//Smart Solution 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());      // O(n/2)
        reverse(nums.begin(), nums.begin()+k);  // O(n/2)
        reverse(nums.begin()+k, nums.end());    // O(n/2)
        
    }
};


int main(){
    vector<int> nums = {1,2};
    int k = 3;
    Solution obj;
    obj.rotate(nums,k);

    // show the new vector
    cout << "[" << nums[0];                                   // --> O(n)
    for (int i = 1; i<nums.size();i++)
        cout << "," << nums[i];
    cout << "]" << endl;

    return 0;
}