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
    int countElements(vector<int>& arr) {
        if (arr.size()==0)
            return 0;
        
        unordered_map<int,int> m(arr.size());
        for (int i=0;i<arr.size();i++){
            if (m.find(arr[i])==m.end()) // not found
                m[arr[i]]=1;
            else m[arr[i]]++;
        }
        
        int counter = 0;
        for (int i=0;i<arr.size();i++){
            int x = arr[i];
            if (m.find(x+1)!=m.end() && m[x]>0){ // found
                m[x]--;
                counter++;
            }
        }
        
        return counter;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> arr = {1,3,2,3,5,0};

    Solution sol;
    cout << sol.countElements(arr) << endl;

    return 0;
}
