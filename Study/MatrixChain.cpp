#include <bits/stdc++.h>

using namespace std;

int MatrixChain(int n, vector<int> &d, vector<vector<int>> &N, vector<vector<int>> &T)
{
    // inicialização das matrizes
    for (int i = 0; i < n; i++)
    {
        N[i].resize(n);
        N[i][i] = 0; // subproblemas triviais
    }
    for (int i = 0; i < n; i++)
        T[i].resize(n);
    for (int b = 1; b < n; b++) // tamanhos dos subproblemas
        for (int i = 0; i < n - b; i++)
        {
            int j = i + b; // novo intervalo para subproblema
            N[i][j] = INT_MAX; // valor provisório para a solução
            T[i][j] = i; // valor provisório para o índice
            for (int k = i; k < j; k++) // equação de cálculo
            {
                int x = N[i][k] + N[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                if (x < N[i][j])
                {
                    N[i][j] = x;
                    T[i][j] = k; // (Ai... Ak).(Ak + 1...Aj)
                }
            }
        }
    return N[0][n - 1];
}

int main()
{
    int n = 5;
    vector<vector<int>> N(n); // parêntesis
    vector<vector<int>> T(n);
    vector<int> d = {5, 4, 1, 3, 7, 2};
    int ans = MatrixChain(n, d, N, T);
    for (auto i:T){                     // Tracing
        for (auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "ans = " << ans << endl;
    return 0;
}