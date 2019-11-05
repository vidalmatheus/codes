#include <bits/stdc++.h>

using namespace std;

class KMP
{
    string P;
    vector<int> b;
    int m;

public:
    KMP(const char *_P) : P(_P) // member initialization 
    {
        m = P.size();
        b.assign(m + 1, -1);
        for (int i = 0, j = -1; i < m;)
        {
            while (j >= 0 && P[i] != P[j])
                j = b[j];
            b[++i] = ++j;
        }
    }
    vector<int> match(const char *T)
    {
        vector<int> ans;
        for (int i = 0, j = 0, n = strlen(T); i < n;)
        {
            while (j >= 0 && T[i] != P[j])
                j = b[j];
            i++;
            j++;
            if (j == m)
            {
                ans.push_back(i - j);
                j = b[j];
            }
        }
        return ans;
    }
};

int main()
{
    const char *_P = "abacab";
    const char *T = "abacaabaccabacabaabb";
    char var[20];
    vector<int> ans;
    cout << "KMP" << endl;
    cout << "Pattern: ";
    scanf("%s", &var);
    _P = var;
    cout << "P = " << _P << endl;
    cout << *_P << endl;
    cout << "Sentence: ";
    scanf("%s", &var);
    T = var;
    cout << "T = " << T << endl;
    cout << "T size = " << strlen(T) << endl;
    KMP *kmp = new KMP(_P);
    ans = kmp->match(T);
    cout << "#posicoes: " << ans.size() << endl;
    cout << "posicoes:";
    for (auto i : ans)
        cout << i;
    return 0;
}