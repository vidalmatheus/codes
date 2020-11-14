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
  int n;
  cin >> n;
  int max = INT_MIN;
  int carlos;
  for (int i=0;i<n;++i){
    int val;
    cin >> val;
    if (i == 0)
      carlos = val;
    max = std::max(max, val);   
  }

  if (carlos == max)
    cout << "S" << endl;
  else cout << "N" << endl;

  return 0;
}
