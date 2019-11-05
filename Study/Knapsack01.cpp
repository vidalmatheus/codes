#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution{

public:
    /* The 0/1 Knapsack Problem */
    int knapsack01(vector<int> &w,vector<int> &v){
        int L=w.size();
        int C=*max_element(w.begin(),w.end())+1;
        int dp[L][C]; // dynamic programming
        
        // filling up the first line
        for (int i=0;i<C;i++){ 
            if (w[0]>i) dp[0][i]=0;
            else dp[0][i]=v[0];
        }
        // filling the rest
        for (int i=1;i<L;i++){
            for (int j=0;j<C;j++){
                if (w[i]>j) dp[i][j]=dp[i-1][j]; // it isn't possible to choose item i
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]); // now it's possible, but we have to check if it's optimum solution
                //----------------not chosen-------chosen---------//
            }
        }
        // show dp table
        cout << "DP Table: " << endl;
        for (int i=0;i<L;i++){
            for (int j=0;j<C;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        // traversal
        vector<int> trace;
        int i=L-1;
        int j=C-1;
        while (i>0){
            if (dp[i][j]!=dp[i-1][j]){ // we didn't use item i
                trace.push_back(i);    
                j=j-w[i];
                i=i-1;
            }
            else i=i-1;
        }
        //show the traversal
        cout << "Items chosen: ";
        for (auto i:trace){
            cout << i << " ";
        }
        cout << endl;
        return dp[L-1][C-1];
    }
};

int main(){
    int n = 4;
    vector<int> weight(n);
    weight[0]=5;
    weight[1]=3;
    weight[2]=4;
    weight[3]=2;
    vector<int> value(n);
    value[0]=60;
    value[1]=50;
    value[2]=70;
    value[3]=30;

    for (int i=0;i<n;i++){
            cout << "Item(" << i << "): " << "(" << weight[i] << "," << value[i] << ")" << endl;
    }
    
    Solution sol;
    cout << "Max value we can take is: " << sol.knapsack01(weight,value) << endl;

    return 0;
}