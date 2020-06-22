#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

h -> h papers with >= h citations 
    N-h papers with < h citations

[2,2,4,8,9]
 a b c d e
                ---
            ---

        ---

    ---
-------------------------

*/

class Wrongolution { // I need to check this
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0)
            return 0;
        
        int h_index = 0;
        int n = citations.size();
        for (int i=0;i<=citations[n-1];i++){
            int greater_or_equal = 0;
            int less_than = 0;
            for (int j=0;j<citations.size();j++){
                if (citations[j] >= i)
                    greater_or_equal++;
                if (citations[j] <= i) 
                    less_than++;
            }        
            // cout << "test: " << i << endl;
            // cout << greater_or_equal << endl;
            // cout << less_than << endl;
            if (greater_or_equal == less_than && greater_or_equal!=0)
                h_index = max(h_index, greater_or_equal);
        }

        return h_index;
    }
};
// Time: O(n*RANGE)
// Space: O(1)


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n-1;
        int ans;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (citations[mid] == (n-mid))
                return citations[mid];
            else if (citations[mid] > (n-mid))
                right = mid - 1;
            else if (citations[mid] < (n-mid))
                left = mid + 1;
        }
        
        return n-left;
    }
};
// Time: O(log n)
// Space: O(1)

int main(){
    vector<int> citations = {0,1,3,5,6};

    Solution sol;
    cout << sol.hIndex(citations) << endl;

    return 0;
}
