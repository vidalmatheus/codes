#include <bits/stdc++.h>
using namespace std;
 
static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

pair<int,int> intersect(pair<int,int>& a, pair<int,int>& b){
    return {max(a.first,b.first), min(a.second,b.second)};
}

void sol(vector<pair<int,int>>& A){
    stack<pair<int,int>> s;
    sort(A.begin(),A.end());
    
    s.push(A[0]);
    for (int i=1;i<A.size();i++){
        if (s.top().second >= A[i].first){ // if intersects
            pair<int,int> tmp = intersect(s.top(),A[i]);
            s.pop();
            s.push(tmp);
        }
        else {
            s.push(A[i]);
        }
    }

    cout << s.size() << endl;
    while (!s.empty()){
        cout << s.top().first << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    vector<pair<int,int>> A;
    int a,b;
    for (int i=0;i<t;i++){
        cin >> a;
        cin >> b;
        A.push_back({a,b});
    }
    
    sol(A);
    return 0;
}
