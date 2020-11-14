#include<bits/stdc++.h>

using namespace std;

vector<int> fat;

int rec(int n, int i){
  if(n <= 1)
    return 1;
  
  int div = n/fat[i];
  if (div != 0)
    return div+rec(n-fat[i]*div, i-1);
  else return rec(n, i-1);
}


int main(){
  int n;
  cin >> n;
  
  fat.resize(n);
  fat[0] = 1;
  for (int i=1;i<n;i++)
    fat[i] = i*fat[i-1];
  
  int ans = rec(n, n-1);
  
  cout << ans << endl;
  
  return 0;
}