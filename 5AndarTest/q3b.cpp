#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) { 
    // write your code in C++14 (g++ 6.2.0)
    if (A.size()==1) // A.size() >= 1
        return 1;
    int maxLength=0;
    for (int start=0;start<A.size();start++){
        vector<int> dp(A.size()); // dynamic programming
        dp[start]=1; //just one element
        for (int k=start+1;k<A.size();k++){
            int last = A[k];
            bool fails = false;
            for (int i=k;i>=0;i-=2){
                if (A[i]!=last){
                    fails = true;
                    break;
                }
            }
            if (fails)
                dp[k]=dp[k-1];
            else dp[k]=min(k+1,dp[k-1]);
            if (dp[k]>maxLength)
                maxLength = dp[k];
        }
        for (auto e:dp)
            cout << e << " ";
        cout << endl;
    }

    return maxLength;
}


int main(){
    /* vector<int> A = {3,-7,3,-7,3}; */
    /* vector<int> A = {7,4,-2,4,-2,-9}; */
    vector<int> A = {7,-5,-5,-5,7,-1,7};

    cout << solution(A) << endl;

    return 0;
}