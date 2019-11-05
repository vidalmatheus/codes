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
    vector<int> subArrayContMenorSoma(vector<int>& nums) { // O(n)
        int v[nums.size()]; // guarda a solução dos casos anteriores
        vector<int> last;
        v[0] = nums[0]; // caso base
        int min_sum=v[0];
        last.push_back(nums[0]);
        for (int i=1;i<nums.size();i++){
            v[i]=min(v[i-1]+nums[i],nums[i]);
            // atualiza o mínimo
            if (v[i]<min_sum){
                min_sum = v[i];
                if (v[i]==v[i-1]+nums[i]) last.push_back(nums[i]);
                else {
                    last.clear();
                    last.push_back(nums[i]);
                }
            }
        }
        return last;
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
    vector<int> ans;
    ans = sol.subArrayContMenorSoma(nums);
    int min_sum=0;
    for (auto e:ans)
        min_sum+=e;
    if (min_sum >= 0) cout << 0 << endl;
    else{
        for(auto e:ans)
            cout << e << endl;
    }
    return 0;
}