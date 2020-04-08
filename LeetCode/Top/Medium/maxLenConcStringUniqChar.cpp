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
    int maxLength(vector<string>& arr) {
        if (arr.size()==0)
            return 1;
        
        int ans=0;
        maxUnique(arr,0,"",ans);

        return ans;    
    }

    void maxUnique(const vector<string> &arr, int pos, string curr, int &max){
        if (pos == arr.size() && uniqueCharCounter(curr)>max){
            max = uniqueCharCounter(curr);
            return;
        }

        if (pos == arr.size())
            return;

        maxUnique(arr,pos+1,curr,max); // without concatenating string at pos index
        maxUnique(arr,pos+1,curr+arr[pos],max); // with concatenating string at pos index
    }

    int uniqueCharCounter(string curr){
        //         unordered_set<char> s;
        //         for (int i=0;i<curr.size();i++){
        //             if (s.find(curr[i])!=s.end()) // found
        //                 return -1;
        //             else s.insert(curr[i]);
        //         }

        //         return curr.size();

        // Same solution without hash_set
        vector<char> counts(26);
        for(char c:curr)
            if (counts[c-'a']>0)
                return -1;
            else counts[c-'a']++;
        return curr.size();
    }
};
// Time: O(2^n)
// Space: O(1)

int main() {
    vector<string> arr = {"un","iq","ue"};

    Solution sol;    
    cout << sol.maxLength(arr) << endl;

    return 0;
}