#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) { 
    // write your code in C++14 (g++ 6.2.0)
    if (A.size()==1) // A.size() >= 1
        return 1;
    vector<int> dp(A.size()); // dynamic programming
    dp[1]=1; //just one element
    for (int k=2;k<A.size();k++){
        int last = A[k];
        dp[k]=k+1;
        for (int i=k;i>=0;i-=2){
            if (A[i]!=last)
                dp[k]=dp[k-1];
        }
    }
    return dp[dp.size()-1];
}


int main(){
    /* vector<int> A = {3,-7,3,-7,3}; */
    /* vector<int> A = {7,4,-2,4,-2,-9}; */
    vector<int> A = {7,-5,-5,-5,7,-1,7};

    cout << solution(A) << endl;

    return 0;
}