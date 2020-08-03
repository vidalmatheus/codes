#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


void test(int n){
    if (n == 1){
        cout << "8";
        return;
    }
    
    vector<int> x(n,9);
    int start = n%4 == 0 ? n-n/4 : n-n/4-1;
    for (int i=n-1;i>=start;i--)
        x[i] = 8;             

    for (int i:x)
        cout << i;
}

int main(){
    int t;
    int n;
    cin >> t;

    for (int i=0;i<t;i++){
        cin >> n;
        if (i!=0)   
            cout << endl;
        test(n);
    }

    return 0;
}
