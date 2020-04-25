#include<bits/stdc++.h>

using namespace std;

class FirstSlowSolution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int AND = m;
        for (unsigned int i=(unsigned int)m+1;i<=n;i++){
            if (AND==0)
                return 0;
            AND &=i;
        }
        return AND;
    }
};
// Time: O(n)
// Space: O(1)

class SlowSolution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> AND(32,1); 
        for (int j=0;j<32;j++){
            for (unsigned int i=m;i<=n;i++){        
                if ((i&(1<<j))==0){
                    AND[j] = 0;
                    break;
                }   
            }
        }
        
        unsigned int ans = 0;
        unsigned int prod = 1;
        for (int i=0;i<32;i++){
            ans += AND[i]*prod;
            prod *= 2;
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c=0;
	    while(m!=n){ // try to find the first same bit for all numbers in the range
		m>>=1;
		n>>=1;
        ++c;
	}

	return n<<c;
    }
};
// Time: O(log n)
// Space: O(1)

int main(){
    int m = 5;
    int n = 7;

    Solution sol;
    cout << sol.rangeBitwiseAnd(m,n) << endl;

    return 0;
}
