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
    int findJudge(int N, vector<vector<int>>& trust) { // Time: O(N) and Space: O(N)
        // let's define a hashmap that will help us:
        unordered_map<int,list<int>> trustWho(N);
        for (auto t:trust){
            trustWho[t[0]].push_back(t[1]);
        }
        // if the town judge exists, this must happen:
        // the judge doesn't trust anyone
        int potentialJudge = -1;
        for (int i=1;i<=N;i++){
            if (trustWho.find(i)==trustWho.end()){
                potentialJudge = i;
                break;
            }
        }
        // everyone must trust him, so must exists exactly N-1 trustness as [i,J], for all i!=J 
        int count = 0;
        for (auto t:trust){
            if (t[1]==potentialJudge){
                count++;
            }
        }
        if (count==N-1){
            return potentialJudge;
        }
        else{
            return -1;
        }
    }
};

class Solution2 { // A better one!
public:
    int findJudge(int N, vector<vector<int>>& trust) { // Time: O(N) and Space: O(N)
        // judgeRelatedDegree = N-1 (out: N-1 and in: 0) --> unique
        vector<int> relativeDegree(N+1);
        for (auto t:trust){
            relativeDegree[t[0]]--;
            relativeDegree[t[1]]++;
        }
        // find that node wich relative degree is equal N-1
        for (int i=1;i<=N;i++){
            if (relativeDegree[i]==N-1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int N = 2;
    vector<vector<int>> trust = {{1,2}};
    Solution2 sol;
    cout << sol.findJudge(N,trust) << endl;
    return 0;
}