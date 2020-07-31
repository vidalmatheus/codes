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
    if (n < 31)
        cout << "NO";
    else if (n == 36)
        cout << "YES\n" << "6 10 15 " << n - 31;
    else if (n == 40)
        cout << "YES\n" << "6 10 15 " << n - 31;
    else if (n == 44)
        cout << "YES\n" << "6 10 15 " << n - 31;
    else cout << "YES\n" << "6 10 14 " << n - 30;
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
