#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int bad;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
    if (version==bad) return true;
    else return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        // do binary search to find an the first ocurrency of true
        // do it if left and right integers positions, because it's easier to write
        int left = 1;
        int right = n;
        while (left < right){
            int mid = left + (right-left)/2; // TRICK TO PREVENT OVERFLOW!
            if (!isBadVersion(mid)) 
                left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};

int main(){
    int n = 2126753390;
    bad = 1702766719;
    Solution sol;
    cout << sol.firstBadVersion(n) << endl;
    return 0;
}