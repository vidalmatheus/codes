#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if (A.size()==0)
            return 0;
        
        vector<int> prefixSum(A.size()+1,0);
        for (int i=1;i<prefixSum.size();i++)
            prefixSum[i] = prefixSum[i-1] + A[i-1];
        
        int counter = 0;
        int index = prefixSum.size()-1;
        int toSearch = prefixSum[index]-S; 
        while (toSearch>=0){
            counter += binarySearch(prefixSum,0,index-1,toSearch);
            index--;
            toSearch = index>=0 ? prefixSum[index]-S : -1;
        }
        
        return counter;
    }
    
    int binarySearch(vector<int>& prefix, int left, int right, int val){
        if (val<prefix[0] || val>prefix[prefix.size()-1])
            return 0;

        while (left<=right){
            int mid = left + (right-left)/2;
            if (val<prefix[mid])
                right = mid - 1;
            else if (val>prefix[mid])
                left = mid + 1;
            else {
                int counter = 1;
                int pos = mid+1;
                while (pos <= right && prefix[pos++]==val)
                    counter++;
                pos = mid-1;
                while (pos >= left && prefix[pos--]==val)
                    counter++;                
                return counter;
            }
        }
        
        return 0;
    }
};
// Time: O(n log n)
// Space: O(n)

int main(){
    vector<int> A = {1,0,1,0,1};
    int S = 2;

    Solution sol;
    cout << sol.numSubarraysWithSum(A,S) << endl;

    return 0;
}
