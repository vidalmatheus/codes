#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        
        return arr == target;
    }
};
// Time: O(n log n)
// Space: O(log n)

int main(){
    vector<int> target{1,2,3,4};
    vector<int> arr{2,4,1,3};

    Solution sol;
    sol.canBeEqual(target,arr) ? cout << "true\n" : cout << "false\n";
 
    return 0;
}
