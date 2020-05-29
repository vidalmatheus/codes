#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> countBits(int num) {
        if (num==0)
            return {0};
        
        vector<int> ans(num+1,0);
        for (int i=1;i<=num;i++)
            ans[i] = numberOfOnes(i);
        
        return ans;
    }
    
    int numberOfOnes(int num){ // O(sizeof(num))
        int n = log2(num) + 1; // number of digits in binary
        int counter = 0;
        for (int i=0;i<n;i++)
            counter += num&(1<<i) ? 1:0;
        
        return counter;
    }
};
// Time: O(n*sizeof(n))
// Space: O(1)

int main(){
    int num = 2;

    Solution sol;
    vector<int> ans = sol.countBits(num);

    for (int i:ans)
        cout << i << " ";
    cout << endl;

    return 0;
}

