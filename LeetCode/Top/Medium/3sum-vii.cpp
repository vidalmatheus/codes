#include <bits/stdc++.h>

using namespace std;

static auto speedUp(){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}
/*

O(n^2)

a+b = -c

[-1, 0, 1, 2, -1, -4]
  
*/

class Solution {
private:
    const int p = pow(10,9) + 7;
    unordered_map<int,unordered_set<string>> hash; // each answer is of size 3
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        vector<vector<int>> ans;
        ans.reserve(nums.size());
        for (int i=0;i<nums.size();i++)
            twoSum(nums,i,-nums[i],ans);
        
        // for (auto elem:hash){
        //     cout << elem.first << ": ";
        //     for (auto s:elem.second){
        //         cout << "[ ";
        //         for (int i:s)
        //             cout << i << " ";
        //         cout << "]";
        //     }
        //     cout << endl;
        // }
        // cout << "--------------------------------------" << endl;
        
        return ans;
    }
    
    void twoSum(vector<int>& nums, int indexSum, int sum, vector<vector<int>>& ans){
        unordered_set<int> seen;
        for (int i=0;i<nums.size();i++){
            if (i == indexSum) continue;            
            if (seen.find(sum-nums[i]) != seen.end()){               
                vector<int> newSol = {-sum,nums[i],sum-nums[i]};
                sort(newSol.begin(),newSol.end());
                int hash_value = hashValue(newSol);
                string str(newSol.begin(),newSol.end());
                if (hash.find(hash_value) == hash.end() || hash[hash_value].find(str) == hash[hash_value].end()){
                    hash[hash_value].insert(str);
                    ans.push_back(newSol);
                }
            }
            seen.insert(nums[i]);
        }
    }
    
    int hashValue(vector<int>& v){
        int val = 0;
        for (int i=0;i<v.size();i++)
            val += pow(10,i)*v[i];
        
        val %= p;
        return val;
    }
};
// Time: O(n^2)
// Space: O(ans)

/*

[-1, 0, 1, 2, -1, -4]


[-4] -> [-1, -1, 0, 1, 2]
  i          a + b = 4

[-4] [-1] -> [-1, 0, 1, 2]
       i       a + b = 1
       
1. sort the input (O(nlog n))
2. traverse the array O(n²)
    2.1 pick ith number as the -sum O(1)
    2.2 check if I have a+b=sum on the right side O(n)
        2.2.1 if solution found, append to answer
3. return ans

Overall:
Time: O(n^2) 
Space: O(log n)
      
*/

/*

[-4] -> [-1, -1, 0, 1, 2]
  i          a + b = 4 X
          
[-4] [-1] -> [-1, 0, 1, 2]
                  s  e
        [-1,-1,2]
        [-1, 0,1]
        
[-4,-1] [-1] -> [0, 1, 2]
                 s  e
        [-1,0,1]
            
[-4,-1,-1] [0] -> [1, 2]
                   s  e
                   
[-4,-1-1,0] [1] -> [2]


*/

class BestSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        for (int i=0;i<(int)nums.size();i++){
            if (i-1 >= 0 && nums[i-1] == nums[i]) continue;
            int start = i+1;
            int end = nums.size()-1;
            int target = -nums[i];
            // do 2 sum
            while (start < end){
                if (nums[start] + nums[end] == target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    int current_start = start;
                    while (nums[current_start] == nums[start] && start<end)
                        start++;
                    int current_end = end;
                    while (nums[current_end] == nums[end] && start<end)
                        end--;
                }
                else if (nums[start] + nums[end] < target)
                    start++;
                else end--;
            }
        }
        
        return ans;
    }
};
// Time: O(n^2)
// Space: O(log n)

int main(){
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << ans.size() << endl;
    for (auto row:ans){
        for (int i:row)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}