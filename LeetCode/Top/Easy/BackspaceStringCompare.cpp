#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class LinearSpaceSolution {
public:
    bool backspaceCompare(string S, string T) {
        if (S.size()==0 && T.size()==0)
            return true;
        
        string s1 = "";
        for (int i=0;i<S.size();i++){
            if (S[i]!='#')
                s1.push_back(S[i]);
            else s1.pop_back();
        }
        
        string t1 = "";
        for (int i=0;i<T.size();i++){
            if (T[i]!='#')
                t1.push_back(T[i]);
            else t1.pop_back();
        }
        
        return s1==t1;
    }
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if (S.size()==0 && T.size()==0)
            return true;
        
        int s = S.size()-1;
        int t = T.size()-1;
        
        while (s>=0 || t>=0){ // check
            int counterS = 0;
            int counterT = 0;
            while (s>=0 && S[s]=='#'){
                counterS++;
                s--;
                while (s>=0 && S[s]!='#' && counterS>0){
                    s--;
                    counterS--;
                }
            }
            
            while (t>=0 && T[t]=='#'){
                counterT++;
                t--;
                while (t>=0 && T[t]!='#' && counterT>0){
                    t--;
                    counterT--;
                }
            }
            
            if (s<0 && t<0)
                return true;
            else if (s>=0 && t>=0 && S[s]==T[t]){
                s--;
                t--;
            }
            else return false;
        }
        
        return true; 
    }
};
// Time: O(n)
// Space: O(1)


int main(){
    // string S = "ab##", T ="c#d#";
    // string S = "xywrrmp", T ="xywrrmu#p";
    string S = "bbbextm", T = "bbb#extm";

    Solution sol;
    sol.backspaceCompare(S,T) ? cout << "true\n" : cout << "false\n";

    return 0;
}
