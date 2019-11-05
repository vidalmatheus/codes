#include <bits/stdc++.h>

using namespace std;

int LCS(vector<char> &x, vector<char> &y, vector<vector<int>> &c, vector<vector<char>> &trace)
{
    int m = x.size();
    int n = y.size();
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (x[i-1] == y[j-1])                       // TAVA ERRADO NO SLIDE
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                trace[i][j] = 92; // '\' = 92
            }
            else if (c[i][j - 1] > c[i - 1][j])
            {
                c[i][j] = c[i][j - 1];
                trace[i][j] = '-';
            }
            else
            {
                c[i][j] = c[i - 1][j];
                trace[i][j] = '|';
            }
    return c[m][n];
}

void PrintLCS(vector<char> &x, vector<vector<char>> &trace, int i, int j)
{
    if (i == 0 || j == 0)   return;
    if (trace[i][j] == 92)  // '\' = 92
    {
        PrintLCS(x, trace,i - 1, j - 1);
        cout << x[i-1];                         // TAVA ERRADO NO SLIDE
    }
    else if (trace[i][j] == '|')
        PrintLCS(x,trace,i - 1, j);
    else
        PrintLCS(x,trace,i, j - 1);
}

int main()
{
    vector<char> x = {'G', 'G', 'A', 'T', 'C', 'G', 'A'},
                 y = {'G', 'A', 'A', 'T', 'T', 'C', 'A', 'G', 'T', 'T', 'A'};
    vector<vector<int>> c(x.size() + 1); // c_mXn
    vector<vector<char>> trace(x.size() + 1);
    for (int i = 0; i < c.size(); i++)
    {
        c[i].resize(y.size() + 1);
        trace[i].resize(y.size() + 1);
    }
    int lcs = LCS(x, y, c, trace);
    cout << "|LCS| = " << lcs << endl;
    cout << endl;
    cout << "Matriz de Comparacao:" << endl;
    for (auto i : c)
    { // matriz de comparação
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matriz de Trace:" << endl;
    for (auto i : trace)
    { // matriz de trace
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    // PrintLCS
    // m = x.size()
    // n = y.size()
    PrintLCS(x,trace,x.size(),y.size());

    return 0;
}