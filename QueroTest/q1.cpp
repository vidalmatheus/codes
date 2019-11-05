#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int menorInteiroPositivo(vector<int>& nums) {
        int min;
        sort(nums.begin(),nums.end()); // O(nlogn)
        for (int i=0;i<nums.size();i++){
            if(nums[i+1]>nums[i]+1 && nums[i+1]-1>0)
                return nums[i+1]-1;
        }
        return nums[nums.size()-1]+1;
    }
};

int main(){
    int N;
    vector<int> nums;
    cin >> N;
    nums.resize(N);
    for (int i=0;i<N;i++)
       cin >> nums[i];
    Solution sol;
    cout << sol.menorInteiroPositivo(nums) << endl;
    return 0;
}