#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

vector<int> memo;
vector<bool> isPrime;

void crivo(int n){ // O(n)
        isPrime.resize(n,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for (int i=2;i*i<n;i++){ 
            if (isPrime[i]){ 
                for (int j=i;i*j<n;j++){
                    isPrime[i*j] = false;
                }
            }
        }

        // for (int i=0;i<n;i++)
        //     cout << i << "," << isPrime[i] << endl;

}

bool isNearlyPrime(int num){ // O(num)
    if (memo[num] != -1)
        return memo[num];

    int left = 0;
    int right = isPrime.size()-1;
    while (left < right){
        if (isPrime[left] && isPrime[right]){
            if (left * right < num)
                left++;
            else if (left * right > num)
                right--;
            else{
                return memo[num] = true;
            }
        }
        else if (!isPrime[left])
            left++;
        else right--;
    }

    return memo[num] = false;
}

void test(int n){ // O(n^3)
    for (int a=1;a<n-3;a++){
        for (int b=a+1;b<n-2;b++){
            for (int c=b+1;c<n-1;c++){
                int d = n - a - b - c;
                    // if (a + b + c + d == n){
                        if (d>=1 && d!=a && d!=b && d!=c && (isNearlyPrime(a) + isNearlyPrime(b) + isNearlyPrime(c) + isNearlyPrime(d) >= 3)){
                            cout << "YES" << endl;
                            cout << a << " " << b << " " << c << " " << d;
                            return;
                        }
                    // }
                
            }
        }            
    }

    cout << "NO";
}

int main(){
    int t;
    int n;
    cin >> t;
    crivo(200000);
    memo.resize(200000,-1);

    for (int i=0;i<t;i++){
        cin >> n;
        if (i!=0)   
            cout << endl;
        test(n);
    }

    return 0;
}
