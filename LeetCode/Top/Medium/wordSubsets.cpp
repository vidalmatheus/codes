#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        if (A.size() == 0 || B.size() == 0)
            return {};
        
        vector<string> ans;
        for (int i=0;i<A.size();i++){
            int counter = 0;
            for (int j=0;j<B.size();j++){
                if (isSubset(A[i],B[j]))
                    counter++;
                else break;
            }
            if (counter == B.size())
                ans.push_back(A[i]);
        }
        
        return ans;
    }
    
    bool isSubset(string& a, string& b){ // O(m)
        if (b.size() > a.size())
            return false;
        
        vector<int> freqA(26,0);
        for (int i=0;i<a.size();i++)
            freqA[a[i]-'a']++;
            
        vector<int> freqB(26,0);
        for (int i=0;i<b.size();i++)
            freqB[b[i]-'a']++;
        
        for (int i=0;i<26;i++){
            if (freqA[i] < freqB[i])
                return false;
        }
        
        return true;
    }
};
// Time: O(n^2*m)
// Space: O(1)

class FasterSolution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        if (A.size() == 0 || B.size() == 0)
            return {};
        
        string b;
        build(B,b);
        vector<string> ans;
        for (int i=0;i<A.size();i++){
            int counter = 0;
            if (isSubset(A[i],b))
                ans.push_back(A[i]);
        }
        
        return ans;
    }
    
    void build(vector<string>& B, string& ans){ // O(|B|)
        vector<int> freqMax(26,0);
        for (int i=0;i<B.size();i++){
            vector<int> freq(26,0);
            for (int j=0;j<B[i].size();j++)
                freq[B[i][j]-'a']++;
            
            for (int j=0;j<26;j++)
                freqMax[j] = max(freqMax[j], freq[j]);
        }
        
        for (int i=0;i<26;i++){
            for (int j=0;j<freqMax[i];j++)
                ans.push_back(i+'a');
        }
    }
    
    bool isSubset(string& a, string& b){ // O(m)
        if (b.size() > a.size())
            return false;
        
        vector<int> freqA(26,0);
        for (int i=0;i<a.size();i++)
            freqA[a[i]-'a']++;
            
        vector<int> freqB(26,0);
        for (int i=0;i<b.size();i++)
            freqB[b[i]-'a']++;
        
        for (int i=0;i<26;i++){
            if (freqA[i] < freqB[i])
                return false;
        }
        
        return true;
    }
};
// Time: O(n_a + n_b)
// Space: O(1)

int main(){
    vector<string> A{"amazon","apple","facebook","google","leetcode"};
    vector<string> B{"lo","eo"};

    vector<string> ans = {"google","leetcode"};

    Solution sol;
    assert(ans == sol.wordSubsets(A,B));

    cout << "Passed!" << endl;
    return 0;
}