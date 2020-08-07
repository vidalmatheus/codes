#include <bits/stdc++.h>
 
using namespace std;
 
static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
 
long long test(vector<int>& a, int& min_a, vector<int>& b, int& min_b, int& n){
    long long k = 0;
    for (int i=0;i<n;i++){
        int da = a[i] - min_a;
        int db = b[i] - min_b;
        if (da > 0 && db > 0){
            int move = min(da,db);
            k += min(da,db);
            if (da > db)
                k += da-move;
            else if (da < db)
                k += db-move;
        }
        else if (da > 0)
            k += da;
        else if (db > 0)
            k += db;
    }
 
    return k;
}
 
int main(){
    int t;
    int n;
    cin >> t;

    vector<int> a(55,0);
    vector<int> b(55,0); 
    for (int i=0;i<t;i++){
        cin >> n;
        int min_a = INT_MAX;
        for (int j=0;j<n;j++){
            cin >> a[j];
            min_a = min(min_a,a[j]);
        }

        int min_b = INT_MAX;
        for (int j=0;j<n;j++){
            cin >> b[j];
            min_b = min(min_b,b[j]);
        }

        if (n == 1)
            cout << 0 << endl;
        else cout << test(a,min_a,b,min_b,n) << endl;
    }
 
    return 0;
}
