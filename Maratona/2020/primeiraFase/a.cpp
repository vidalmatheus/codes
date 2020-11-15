#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


int main(){
    int N, A, B;
    // cin >> N;
    // cin >> A;
    // cin >> B;

    N = 1000000;
    A = 0;
    B = 2;

    float sum = 0;
    int k = A;
    int val = 0;
    float p = 1;
    float px = 1.0/(B-A+1);
    for (int i=0;i<N;i++){
        sum += p*val;
        p *= px;
        val += (k)%(B-A+1) + A;
        k++;
    }

    cout << sum << endl;


    return 0;
}