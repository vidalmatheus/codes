#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int test(vector<int>& nums, int s){
    unordered_map<int,int> counter;
    for (int num:nums)
        counter[num]++;
    
    int k = 0;
    for (int num:nums)
        if ( (s-num != num && counter[num] >= 1 && counter[s-num] >= 1) || (s-num == num && counter[num] >=2) ){
            counter[num]--;
            counter[s-num]--;
            k++;
        }
    return k;
}

int main(){
    int t;
    int n;
    cin >> t;

    for (int i=0;i<t;i++){
        cin >> n;

        vector<int> nums(n,0);
        int x;
        for (int j=0;j<n;j++)
            cin >> nums[j];

        if (nums.size() == 1)
            cout << 0 << endl;
        else {
            sort(nums.begin(),nums.end());

            int max_sum = nums[nums.size()-2] + nums[nums.size()-1];
            int k = INT_MIN;
            for (int s=2;s<=max_sum;s++)
                k = max(k,test(nums,s));

            cout << k << endl;
        }
    }

    return 0;
}
