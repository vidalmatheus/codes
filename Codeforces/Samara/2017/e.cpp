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
    int n,m;
    vector<int> t,b;
    cin >> n;
    cin >> m;
    
    for (int i=0;i<n;i++)
        cin >> t[i];
    
    for (int i=0;i<m;i++)
        cin >> b[i];
        
    // get min distance between b and  t_before and t_after
    int j = 0;
    vector<int> dist(m);
    for (int i=0;i<m;i++){
        while (t[j] <= b[i])
            j++;
        j--;
        if (j == 0)
            dist[i] = INT_MAX;
        else dist[i] = b[i]-t[j];
        
        int aux;
        if (j < n)
            aux = t[j] - b[i];
        else aux = INT_MAX;
        
        dist[i] = min(dist[i], aux);
    }
    
    for (auto a : dist)
        cout << a  << " ";
    
    
    return 0;
}