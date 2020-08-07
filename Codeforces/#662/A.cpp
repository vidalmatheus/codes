#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int X(int n){
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    
    return n/2 + 1;
}

int main(){
    int t;
    int n;
    cin >> t;

    for (int i=0;i<t;i++){
        cin >> n;
        cout << X(n) << endl;
    }

    return 0;
}
