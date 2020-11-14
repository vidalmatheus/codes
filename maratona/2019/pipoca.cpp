#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int calculaCompetidores(int tempo, int T, vector<int>& p){
  int N = p.size();
  int c = 1;
  int maxPipocas = tempo*T;
  int counter = 0;
  for (int i=0;i<N;++i){
    if (counter + p[i] <= maxPipocas)
      counter += p[i];
    else if (p[i] <= maxPipocas) {
      c++;
      counter = p[i];
    }
    else return INT_MAX;
  }

  return c;
}

int main(){
  int N, C, T;
  cin >> N;
  cin >> C;
  cin >> T;

  vector<int> p(N);
  int total = 0;
  for (int i=0;i<N;++i){
    cin >> p[i];
    total +=p[i];
  }

  int max = (total+T-1)/T;
  int min = 1;

  while (min < max){
    int mid = min + (max-min)/2;
    int c = calculaCompetidores(mid, T, p);
    // cout << "min: " << min << "   ";
    // cout << "chute(mid): " << mid << "   ";
    // cout << "max: " << max << "   ";
    // cout << "c: " << c << endl;
    if (c > C){
      min = mid+1;
    }
    else max = mid;
  }

  cout << min << endl;
  return 0;
}
