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
   list<int> subArrayContMenorSoma(vector<int>& nums) { // O(n)
        int v[nums.size()]; // guarda a solução dos casos anteriores
        list<int> ans;
        v[0] = nums[0]; // caso base
        for (int i=1;i<nums.size();i++)
            v[i]=min(v[i-1]+nums[i],nums[i]); // basta trocar para max, se quiser o máximo subarray
        
        // subarray
        int min_sum_index = 0; 
        for (int i=1;i<nums.size();i++){
            if (v[i]<v[min_sum_index])        // basta trocar para '>', se quiser o máximo subarray
                min_sum_index = i;
        }
        int i = min_sum_index+1;
        do{
            i--;
            ans.push_front(nums[i]);
        }while (v[i]!=nums[i]);

        return ans;
    }
};

int main(){
    int N;
    vector<int> nums;
    cin >> N;
    nums.resize(N);
    int i = 0;
    while (cin >> nums[i]){
        i++;
        if (i>=N) break;
    }
       
    Solution sol;
    list<int> ans;
    ans = sol.subArrayContMenorSoma(nums);
    for(auto e:ans)
            cout << e << endl;
    return 0;
}