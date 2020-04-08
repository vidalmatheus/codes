#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SolutionBruteForce {
public:
    bool isUgly(int num) {
        if (num<=0)
            return false;
        
        if (num==1)
            return true;
        
        int counter = 0;
        int counter_opposite = 0;
        for (int i=2;i<=num;i++){
            if ((i==2 || i==3 || i==5) && isPrime(i) && num%i==0)
                counter++;
            if ((i!=2 && i!=3 && i!=5) && isPrime(i) && num%i==0)
                counter_opposite++;
            
        }
        
        if (1<=counter && counter<=3 && counter_opposite==0)
            return true;
        else return false;
    }
    
    bool isPrime(int n){
        int counter = 0;
        for (int i=2;i<n;i++){
            if (n%i==0)
                counter++;
        }
        
        if (counter==0)
            return true;
        else return false;
    }
};
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    bool isUgly(int num) {
        if (num==0) return false;
        while(num%2==0) num/=2;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        return (num==1);
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    int num = 6;

    Solution sol;
    sol.isUgly(num) ? cout << "true\n" : cout << "false\n";
    
    return 0;
}