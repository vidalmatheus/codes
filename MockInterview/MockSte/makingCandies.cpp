#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void distribute(long& m, long& w, long& prev_candies, long p){
  long investment = (m*w + prev_candies)/p;
  prev_candies = (m*w + prev_candies) - investment*p;

  long dif = min(abs(m-w),investment);
  if (w < m)
    w += dif;
  else if (w > m)
    m += dif;
  
  investment -= dif;
  m += investment/2 + investment%2;
  w += investment/2; 
}

// Complete the minimumPasses function below.
long minimumPasses(long m, long w, long p, long n) {
    long prev_candies = 0;
    for (long day=1;;day++){
        cout << "day: " << day << endl;
        cout << "(m,w) = " << m << ", " << w << " -> " << m*w << endl;
        cout << "prev_candies: " << prev_candies << endl;
        if (m*w + prev_candies >= n)
            return day;

        distribute(m,w,prev_candies,p);
    }
}

int main(){
    long n = 60;
    long m = 1;
    long w = 2;
    long p = 1;
    
    long sol1 = minimumPasses(m,w,p,n);
    cout << sol1 << endl;

    assert(sol1 == 4);

    n = 12;
    m = 3;
    w = 1;
    p = 2;
    
    long sol2 = minimumPasses(m,w,p,n);
    cout << sol2 << endl;

    n = 45;
    m = 1;
    w = 1;
    p = 6;

    assert(sol2 == 3);

    long sol3 = minimumPasses(m,w,p,n);
    cout << sol3 << endl;

    // assert(sol3 == 16);

    return 0;
}
