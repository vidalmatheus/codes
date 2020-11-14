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
  int n, v;
  cin >> n;
  cin >> v;
  int total = n*v;
  // ceil(a/b) = (a+b-1)/b
  for (int i=1;i<=9;++i){
    if (i == 9)
      cout << (total*i + 10-1)/10 << endl;
    else cout << (total*i + 10-1)/10 << " ";
  }

  return 0;
}
