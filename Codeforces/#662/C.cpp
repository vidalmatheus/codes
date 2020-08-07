#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int findMin(vector<int>& A){
    unordered_map<int,int> map;
    int min = INT_MAX;
    for (int i=0;i<A.size();i++){
        if (map.find(A[i]) != map.end()){
            min = std::min(min, i - map[A[i]] - 1);
        }
        map[A[i]] = i;
    }

    return min;
}

int test(vector<int>& A){ // wrong answer :(
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> counter;
    for (int num : A)
        counter[num]++;
    
    for (auto elem : counter)
        pq.push({elem.second,elem.first});
    
    int min = 0;
    vector<int> order;
    vector<pair<int,int>> tmp;
    while (!pq.empty()){
        int top = pq.top().second;
        order.push_back(top);
        pq.pop();
        counter[top]--;
        if (counter[top] > 0) 
            tmp.push_back({counter[top],top});
        if (pq.empty()){
            for (auto e : tmp)
                pq.push(e); 
            tmp.clear();    
        }
    }

    return findMin(order);
}

int main(){
    int t;
    int n;
    cin >> t;

    for (int i=0;i<t;i++){
        cin >> n;
        vector<int> A(n,0);
        for (int i=0;i<n;i++)
            cin >> A[i];
        
        if (n <= 2)
            cout << 0 << endl;
        else cout << test(A) << endl;
    }

    return 0;
}
