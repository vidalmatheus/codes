#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class NaiveSolution { // TLE
public:
    int nthUglyNumber(int n) {
        int i = 1;
        int counter = 0;
        while (counter!=n){
            if(isUgly(i))
                counter++;
            i++;
        }
        
        return i-1;
    }
    
    bool isUgly(int num) { // O(n)
        if (num==0) return false;
        while(num%2==0) num/=2;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        return (num==1);
    }
};

class MemoSolution { // TLE
private:
    unordered_map<int,int> memo;
public:
    int nthUglyNumber(int n) {        
        int counter = 0;
        
        memo.reserve(n);
        
        for (int i=1;;i++){
            if (isUgly(i)){
                counter++;
                if (counter == n)
                    return i;
            }
        }
        
        return -1;
    }
    
    bool isUgly(int n){
        if (n == 1)
            return true;
        
        if (memo.find(n) != memo.end())
            return memo[n];
        
        if (n % 2 == 0)
            return memo[n] = isUgly(n/2);
        
        if (n % 3 == 0)
            return memo[n] = isUgly(n/3);
        
        if (n % 5 == 0)
            return memo[n] = isUgly(n/5);
        
        return memo[n] = false;
    }
};
// Time: O(n)
// Space: O(n)

/*

    p2
L2: 2->4->6->8->10->12->16-> ...

    p3
L3: 3->6->9->12->15->18-> ...

    p5
L5: 5->10->15->20->25->30-> ...

1. While counter < n:
    1.2. pick the next = min(p2,p3,p5)
    1.3. move foward the pointers for the elements that I have used
2. return the n-th ugly number

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        
        vector<int> primes{2,3,5};
        set<int> seen;
        
        vector<vector<int>> L;
        for (int p:primes){
            L.push_back({p});
            seen.insert(p);
        }
        
        vector<int> ans;
        ans.reserve(n);
        ans.push_back(1);
        vector<int> pointers(primes.size(),0);
        for (int i=1;i<n;i++){
            // for (int j=0;j<L.size();j++){
            //     cout << "L[" << primes[j] << "]: ";
            //     for (int k:L[j])
            //         cout << k << " ";
            //     cout << endl;
            // }
            // cout << "-------" << endl;
            
            // grab the next
            ans.push_back(*(seen.begin()));
            // cout << ans.back() << endl;
            seen.erase(*seen.begin());        
            
            // move forward
            for (int j=0;j<pointers.size();j++)
                if (ans[i] == L[j][pointers[j]]){
                    pointers[j]++;
                    L[j].push_back(ans[pointers[j]]*primes[j]);
                    seen.insert(L[j][pointers[j]]);
                }
        }
        
        return ans.back();
    }
};
// Time: O(n*log(k))
// Space: O(n)

class BetterInMemorySolution { // in fact, you don't need the whole lists
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        
        vector<int> primes{2,3,5};
        set<int> seen;
        
        vector<int> L;
        for (int p:primes){
            L.push_back(p);
            seen.insert(p);
        }
        
        vector<int> ans;
        ans.reserve(n);
        ans.push_back(1);
        vector<int> pointers(primes.size(),0);
        for (int i=1;i<n;i++){
            // for (int j=0;j<L.size();j++){
            //     cout << "L[" << primes[j] << "]: ";
            //     cout << L[j] << " ";
            //     cout << endl;
            // }
            // cout << "-------" << endl;
            
            // grab the next
            ans.push_back(*(seen.begin()));
            // cout << ans.back() << endl;
            seen.erase(*seen.begin());        
            
            // move forward
            for (int j=0;j<pointers.size();j++)
                if (ans[i] == L[j]){
                    pointers[j]++;
                    L[j] = ans[pointers[j]]*primes[j];
                    seen.insert(L[j]);
                }
        }
        
        return ans.back();
    }
};
// Time: O(n*log(k)), k = 3
// Space: O(k), k = 3


class DPSolution { // DP, trust in your ideas!!!
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        
        vector<int> primes{2,3,5};
        
        vector<int> ans;
        ans.reserve(n);
        ans.push_back(1);

        vector<int> pointers(primes.size(),0);
        for (int i=1;i<n;i++){
            int next = INT_MAX;
            for (int j=0;j<primes.size();j++)
                next = min(next,ans[pointers[j]]*primes[j]);
            
            ans.push_back(next);
            
            for (int j=0;j<primes.size();j++)
                if (next == ans[pointers[j]]*primes[j])
                    pointers[j]++;        
        }
        
        return ans.back();
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    int n = 10;

    Solution sol;
    cout << sol.nthUglyNumber(n) << endl;

    return 0;
}

