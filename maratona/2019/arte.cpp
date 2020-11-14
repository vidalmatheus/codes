#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct sensor{
  int x;
  int y;
  int r;
};

int dist(sensor& s1, sensor& s2){
  return (s1.x-s2.x)*(s1.x-s2.x) + (s1.y-s2.y)*(s1.y-s2.y);
}

void buildGraph(unordered_map<int,vector<int>>& g, vector<sensor>& S){
  int K = S.size();
  for (int i=0;i<K;++i){
    for (int j=i+1;j<K;++j){
      int d = dist(S[i],S[j]);
      int limite = (S[i].r+S[j].r)*(S[i].r+S[j].r);
      if (d <= limite){
        g[i].emplace_back(j);
        g[j].emplace_back(i);
      }
    }
  }
}

unordered_set<int> visited;
bool dfs(unordered_map<int,vector<int>>& g, vector<sensor>& S, int node, int M, int N){

  int counter = 0;
  for (int neighbor : g[node]){
    if (visited.find(neighbor) == visited.end()){
      visited.insert(neighbor);
      if (dfs(g, S, neighbor, M, N))
        return true;
    }
    else counter++;
  }

  if (counter == g[node].size())
    if (S[node].y > S[node].r && S[node].x + S[node].r < M)
      return true;

  return false;
}

int main(){

  int M, N, K;
  cin >> M;
  cin >> N;
  cin >> K;

  vector<sensor> S(K);
  for (int i=0;i<K;++i){
    cin >> S[i].x;
    cin >> S[i].y;
    cin >> S[i].r;
  }

  unordered_map<int,vector<int>> g;
  buildGraph(g, S);

  bool hasInitialNode = false;
  for (int i=0;i<K;i++){
    if (visited.find(i) == visited.end()){
      if (S[i].x <= S[i].r || S[i].y + S[i].r >= N){
        hasInitialNode = true;
        visited.insert(i);
        if (dfs(g, S, i, M, N)){
          cout << "S" << endl;
          return 0;
        }
      }
    }
  }

  if (hasInitialNode)
    cout << "N" << endl;
  else cout << "S" << endl;
  return 0;
}
