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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;
        
        vector<int> ans;
        ans.reserve(n);
        ans.push_back(1);

        vector<int> pointers(primes.size(),0);
        for (int i=1;i<n;i++){
            int next = INT_MAX;
            for (int j=0;j<primes.size();j++)
                next = min(next,ans[pointers[j]]*primes[j]);
            
            ans.push_back(next);
            
            for (int j=0;j<primes.size();j++)
                if (next == ans[pointers[j]]*primes[j])
                    pointers[j]++;        
        }
        
        return ans.back();
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    int n = 12;

    vector<int> primes{2,7,13,19};

    Solution sol;
    cout << sol.nthSuperUglyNumber(n,primes) << endl;
    
    return 0;
}
