#include <bits/stdc++.h>

using namespace std;

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int combMoedas(const vector<int>& denom,const int& N) { //N = valor
		int M = denom.size();
		int table[M+1][N+1];
		for (int i=0;i<=M;i++) table[i][0]=1; // casos base
		for (int i=1;i<=N;i++) table[0][i]=0; // casos base
		for (int i=1;i<=M;i++){
			for (int j=1;j<=N;j++){
				if (j-denom[i-1]>=0) // se for possível utilizar a moeda corrente
					table[i][j]=table[i-1][j]+table[i][j-denom[i-1]];
				else table[i][j]=table[i-1][j]; // se não for possível utilizar a moeda corrente
			}
		}
		return table[M][N];
    }
}; 

int main (){
    vector<int> denom;
    int N,M;
    cin >> N;
	cin >> M;
    denom.resize(M);
    for (int i=0;i<M;i++)
       cin >> denom[i];
	Solution sol;
	cout << sol.combMoedas(denom,N) << endl;
    return 0;
}