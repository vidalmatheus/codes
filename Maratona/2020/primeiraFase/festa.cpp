#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct empregado {
    int idade;
    int gerenteID;
};

int N, M;
vector<empregado> empregados;
vector<vector<int>> g;

void buildGraph(){ // O(n)
    for(int i=1;i<=N;++i){
        int neighborID = empregados[i].gerenteID;
        if (neighborID != i){
            g[i].push_back(neighborID);
            g[neighborID].push_back(i);
        }
    }
}

vector<bool> visited;
vector<int> counter;

// void dfs(int node, int L, int R){ // O(N)
//     for (int neighbor : g[node]){
//         int idade = empregados[neighbor].idade;
//         if (!visited[neighbor] && L <= idade && idade <= R){
//             visited[neighbor] = true;
//             counter[neighbor]++;
//             dfs(neighbor, L, R);
//         }
//     }
// }

void dfs(int node, int L, int R){ // O(N)
    stack<int> s;
    s.push(node);
    while (!s.empty()){
        node = s.top();
        s.pop();
        
        for (int neighbor : g[node]){
            int idade = empregados[neighbor].idade;
            if (!visited[neighbor] && L <= idade && idade <= R){
                visited[neighbor] = true;
                counter[neighbor]++;
                s.push(neighbor);
            }
        }
    }
}


int main(){
    cin >> N;
    cin >> M;

    empregados.resize(N+1);
    int minIdade = INT_MAX;
    int maxIdade = INT_MIN;
    for (int i=1;i<=N;++i){
        cin >> empregados[i].idade;
        cin >> empregados[i].gerenteID;
        minIdade = min(minIdade, empregados[i].idade);
        maxIdade = max(maxIdade, empregados[i].idade);
    }

    // cout << "Empregados:" << endl;
    // for (int i=1;i<=N;++i){
    //     cout << i << ", " << empregados[i].idade << ", " << empregados[i].gerenteID << endl;
    // }

    g.resize(N+1);
    buildGraph();

    // cout << "Graph: " << endl;
    // for (int i=1;i<=N;++i){
    //     cout << i << ": ";
    //     int k = g[i].size();
    //     for (int j=0;j<k;++j){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    counter.resize(N+1,0);
    int count = 0;
    for (int i=0;i<M;++i){ // O(N*M)
        int anf, L, R;
        cin >> anf;
        cin >> L;
        cin >> R;
        if (L <= minIdade && maxIdade <= R){
            count++;
            continue;
        }
        // cout << anf << " " << L << " " << R << endl;
        visited.resize(N+1,0);
        visited[anf] = true;
        counter[anf]++;
        dfs(anf, L, R);
        visited.clear();
    }

    // cout << "count: " << count << endl;
    for (int i=1;i<=N;++i){
        if (i == N)
            cout << counter[i] + count << endl;
        else cout << counter[i] + count << " ";
    }

    return 0;
}