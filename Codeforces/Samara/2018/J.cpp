#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int sol(vector<int>& A){
    unordered_map<int,int> counter;
    for (int i=0;i<A.size();i++){
        counter[A[i]]++;
    }

    int ans = 0;
    int curr = 0;
    for (auto p = counter.begin();p!=counter.end();p++){
        if (p->second >= 2){
            curr += p->second/2;
            p->second %= 2;
            if (curr >= 2){
                ans += curr/2;
                curr %= 2;
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n,0);
    for (int i=0;i<n;i++)
        cin >> A[i];

    cout << sol(A);

    return 0;
}
