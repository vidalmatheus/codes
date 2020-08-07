#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void test(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int counter = 0;
    for (int i=1;i<(int)nums.size();i++)
        if (abs(nums[i-1] - nums[i]) <= 1)
            counter++;

    counter == nums.size() - 1 ? cout << "YES\n" : cout << "NO\n";
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

        test(nums);
    }

    return 0;
}
