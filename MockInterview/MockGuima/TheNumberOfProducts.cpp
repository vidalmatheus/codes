#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstSolution{
public:
    vector<int> numberOfProducts(vector<int>& nums){
        if (nums.size()==0)
            return {};

        // build prefixes product
        vector<int> prefixProduct(nums.size(),1);
        prefixProduct[0] = nums[0];
        for (int i=1;i<nums.size();i++)
            prefixProduct[i] = nums[i]*prefixProduct[i-1]; 
        
        int counterPositive = 0;
        int counterNegative = 0;
        for (int i=0;i<prefixProduct.size();i++){ // beginning
            for (int j=i;j<prefixProduct.size();j++){ // ending
                int subArray = nums[i];
                if (i!=j)
                    if (i==0)
                        subArray = prefixProduct[j];
                    else subArray = prefixProduct[j]/prefixProduct[i-1];
                if (subArray > 0)
                    counterPositive++;
                else counterNegative++;            
            }
        }

        return {counterNegative,counterPositive};
    }
};
// Time: O(n^2)
// Space: O(n)

class Solution{
public:
    vector<long long int> numberOfProducts(vector<int>& nums){
        if (nums.size()==0)
            return {};

        long long int n = nums.size();
        // build prefixes sum
        vector<long long int> prefixSum(nums.size(),0);
        prefixSum[0] = nums[0];
        for (int i=1;i<n;i++)
            prefixSum[i] = nums[i]+prefixSum[i-1]; 
        
        long long int odd = 0;
        long long int even = 1;
        for (int i=0;i<n;i++){
            if (prefixSum[i]%2) // odd
                odd++;
            else even++;
        }
        
        return {odd*even, (n*(n-1))/2 + n - odd*even};
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    int n;
    cin >> n;

    vector<int> nums;
    nums.reserve(n);
    for (int i=0;i<n;i++){
        int num;
        cin >> num;
        nums.push_back(num < 0 ? 1:0);
    }

    Solution sol;
    vector<long long int> ans = sol.numberOfProducts(nums);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
