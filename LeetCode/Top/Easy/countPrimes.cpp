#include <bits/stdc++.h>

using namespace std;

// To Speed Up
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class NaiveSolution {
public:
    int countPrimes(int n) {
        int counter=0;
        for (int i=2;i<n;i++){
            if (isPrime(i)){
                counter++;
            }
        }
        return counter;
    }
    bool isPrime(int x){
        int counter=0;
        for (int i=2;i<=sqrt(x);i++){
            if (x%i==0){
                return false;
            }
        }
        return true;
    }
};

class Solution { // Sieve of Eratosthenes
public:
    int countPrimes(int n) {
        if (n==0) return 0;
        vector<bool> isPrime(n);
        // At the beginning, every one is considered prime number
        for (int i=0;i<n;i++){
            isPrime[i]=true;
        }
        isPrime[0]=false;
        isPrime[1]=false;
        for (int i=2;i*i<n;i++){ // we just have to check untill sqrt(n)
            if (isPrime[i]){ // if a number is prime, then we cross out every multiple of him
                for (int j=i;i*j<n;j++){
                    isPrime[i*j] = false;
                }
            }
        }
        // now we just count the numbers that are prime
        int counter = 0;
        for (int i=2;i<n;i++){
            if (isPrime[i])
                counter++;
        }
        return counter;
    }
};

int main() {
    Solution sol;
    cout << sol.countPrimes(11) << endl;
    return 0;
}