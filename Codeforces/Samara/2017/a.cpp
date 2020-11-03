#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// bool rec(vector<int>& nums, int curr, int x){
//     if (curr > x)
//         return false;

//     if (curr == x)
//         return true;

//     if (memo[curr] != -1)
//         return memo[curr];

//     bool response =  false;
//     for (int i=0;i<nums.size();i++){
//         response = response || rec(nums, curr + nums[i], x);
//     }

//     return memo[curr] = response;
// }

int mdc(int a, int b){
    return b == 0 ? a : mdc(b, a%b);
}

int main(){
    int n, x;
    cin >> n;
    cin >> x;

    int k;
    int a;
    cin >> k;
    for (int i=1;i<n;i++){
        cin >> a;
        k = mdc(k,a);
    }

    if (x % k == 0)
        cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;

}