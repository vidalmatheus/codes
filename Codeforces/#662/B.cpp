#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


bool hasSquare(unordered_map<int,int>& counter){
    for (auto p : counter)
        if (p.second >= 4)
            return true;
    return false;
}


bool check(unordered_map<int,int>& counter){ // TLE!!!
    if (!hasSquare(counter))
        return false;

    int ans = 0;
    int curr = 0;
    for (auto p : counter){
        if (p.second >= 2){
            curr += p.second/2;
            p.second %= 2;
            if (curr >= 2){
                ans += curr/2;
                if (ans == 2)
                    return true;
                curr %= 2;
            }
        }
    }

    return false;
}

int main(){
    int n;
    int t;
    cin >> n;
    vector<int> A(n,0);
    for (int i=0;i<n;i++)
        cin >> A[i];
    
    unordered_map<int,int> counter;
    for (int i=0;i<A.size();i++)
        counter[A[i]]++;

    cin >> t;
    char op;
    int x;
    for (int i=0;i<t;i++){
        cin >> op;
        cin >> x;
        if (op == '+')
            counter[x]++;
        else counter[x]--;

        check(counter) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
