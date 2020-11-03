#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


int main(){
    int a,b,c,n,m;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> n;
    cin >> m;
    
    int x,y;
    
    // all unknown are red
    if (a+c<=n && b<=m)
        x = a+b+c;
    else if (a+c<=n && b>m)
        x = m;
    else if (a+c>n && b<=m)
        x = n;
    else x = min(n,m);
    
    // all unknown are green
    if (a<=n && b+c<=m)
        y = a+b+c;
    else if (a<=n && b+c>m)
        y = m;
    else if (a>n && b+c<=m)
        y = n;
    else y = min(n,m);
 
    cout << min(x,y) << endl;   
    
    return 0;
}