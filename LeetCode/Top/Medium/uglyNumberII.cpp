#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SolutionSlow {
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

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n==1)
            return 1;

        set<int> s;
        s.insert(1);

        int p2 = 1;
        int p3 = 1;
        int p5 = 1;

        int u2 = p2*2;
        int u3 = p3*3;
        int u5 = p5*5;

        int counter = 1;
        while (counter<=n) {
            int minimum = min(u2,u3);
            minimum = min(minimum,u5);
            int prevSize = s.size();
            s.insert(minimum);
            cout << "min: " << minimum << endl;
            if (s.size()>prevSize) 
                counter++;
            if (u2 == minimum)
                p2++;
            else if (u3 == minimum)
                p3++;
            else p5++;

            u2 = p2*2;
            u3 = p3*3;
            u5 = p5*5;
        }

        set<int>::iterator it = s.end();
        it--;

        return *it;
    }
};
// Time: O(n*log n)
// Space: O(n)

int main(){
    int n = 10;

    Solution sol;
    cout << sol.nthUglyNumber(n) << endl;

    return 0;
}

