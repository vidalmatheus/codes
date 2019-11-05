#include <bits/stdc++.h>
using namespace std ;

#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for (int x=0; (x)<int (n) ; (x)++)
#define FOR1(x,n) for (int x=1; (x)<=int (n) ; (x)++)
#define REP(x,n) for (int x=int (n) -1; (x)>=0; (x)--)
#define REP1(x,n) for (int x=(n) ; (x) >0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define sz(x) int (x.size())
#define all(x) x.begin(),x.end()
#define mset (x,y) memset(&x,(y), sizeof(x))

typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;
typedef unsigned int uint ;
typedef vector<int> vi ;
typedef pair<int,int> ii ;

class KMP
{
    string P;
    vector<int> b;
    int m;

public:
    KMP(const char *_P) : P(_P)
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
    char var[10];
    vector<int> ans;
    cout << "KMP" << endl;
    cout << "Pattern: ";
    scanf("%s", &var);
    _P = var;
    cout << _P << endl;
    cout << *_P << endl;
    cout << "Sentence: ";
    scanf("%s", &var);
    T = var;
    cout << "T = " << T << endl;
    KMP *kmp = new KMP(_P);
    ans = kmp->match(T);
    cout << "#posicoes: " << ans.size() << endl;
    cout << "posicoes:";
    for (auto i : ans)
        cout << i;
    return 0;
}
