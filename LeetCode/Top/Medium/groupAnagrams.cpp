#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { // O(log(n))
        if (strs.size()==0)
            return {};
        vector<vector<string>> ans;
        map<string,vector<string>> m;
        for (int i=0;i<strs.size();i++){
            string index = strs[i];
            sort(index.begin(),index.end());
            m[index].push_back(strs[i]);
        }
        
        for (auto e:m){
            ans.push_back(e.second);
        }
        return ans;
    }
};

class SolutionBruteForce { // TIME LIMIT EXCEEDED !!! 
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { // O(n^2)
        if (strs.size()==0)
            return {};
        vector<vector<string>> ans;
        vector<bool> added(strs.size());
        for (int i=0;i<strs.size();i++){
            if (!added[i]){
                vector<string> line;
                line.push_back(strs[i]);
                added[i]=true;
                for (int j=i+1;j<strs.size();j++){
                    if (isAnagram(strs[i],strs[j]) && !added[j]){
                        added[j] = true;
                        line.push_back(strs[j]);
                    }
                }
                ans.push_back(line);
            }
        }
        return ans;
    }
    
    bool isAnagram (string a,string b){ // O(m*log(m))
        if (a.size()!=b.size())
            return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for (int i=0;i<a.size();i++){
            if (a[i]!=b[i])
                return false;
        }
        return true;
    }
};

int main(){


    return 0;
}