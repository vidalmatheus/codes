#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 0)
            return {};
        
        vector<int> ans;
        string curr = "";
        
        if (N == 1)
            return {0,1,2,3,4,5,6,7,8,9};
        
        for (int i=1;i<=9;i++)
            rec(ans,curr,N,K,i);
        
        return ans;
    }
    
    void rec(vector<int>& ans, string& curr, int N, int K, int val){
        if (val > 9 || val < 0)
            return;
        
        if (curr.size() == N){
            int next = stoi(curr,nullptr,10);
            if (ans.size() == 0 || (ans.size() > 0 && ans.back() != next))
                ans.push_back(next);
            return;
        }
        
        curr.push_back(val+'0');
        rec(ans,curr,N,K,val+K);        
        rec(ans,curr,N,K,val-K);
        curr.pop_back();        
    }
};
// Time: O(N*2^N)
// Space: O(ans)

int main(){
    Solution sol;

    vector<int> ans{181,292,707,818,929};
    assert(sol.numsSameConsecDiff(3,7) == ans);

    cout << "Passed!" << endl;
    return 0;
}
