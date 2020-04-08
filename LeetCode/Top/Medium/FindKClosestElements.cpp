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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size()==0)
            return {};
        
        priority_queue<pair<int,int>> h;
        for (int i=0;i<arr.size();i++){
            if (i<k)
                h.push({abs(arr[i]-x),arr[i]});
            else if (abs(arr[i]-x)<h.top().first){
                h.pop();
                h.push({abs(arr[i]-x),arr[i]});
            }
        }
        
        vector<int> ans(k);
        for (int i=0;i<k;i++){
            ans[i]=h.top().second;
            h.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
// Time: O(nlog(k))
// Space: O(k)

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;

    Solution sol;
    vector<int> ans = sol.findClosestElements(arr,k,x);

    for (int e:ans)
        cout << e << " ";
    cout << endl;

    return 0;
}
