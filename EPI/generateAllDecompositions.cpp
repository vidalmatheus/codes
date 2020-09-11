#include <bits/stdc++.h>

using namespace std;

class BruteForceSolution {
public:
    void gen(string& s, vector<string>& ans, int start, string& curr){
        if (start == s.size()){
            ans.push_back(curr);
            return;
        }

        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            curr += s.substr(start, len) + " ";
            gen(s, ans, i+1, curr);
            curr.erase(curr.size()-(len+1), len+1); // 1_2_3_4_
        }
    }

    vector<string> generateDecompositions(string& s){
        if (s.size() == 0)
            return {};
        
        vector<string> ans;
        string curr = "";
        gen(s,ans,0,curr);

        return ans;
    }
    // Time: O(n*2^(n-1))
    // Space: O(n*2^(n-1))
};

class BruteForceSolution2 {
public:
    void gen(string& s, vector<string>& ans, int start, vector<string>& curr){
        if (start == s.size()){
            string str = "";
            for (int i=0;i<curr.size();i++)
                str.append(curr[i]+" ");
            ans.push_back(str);
            return;
        }

        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            curr.push_back(s.substr(start, len));
            gen(s, ans, i+1, curr);
            curr.pop_back();
        }
    }

    vector<string> generateDecompositions(string& s){
        if (s.size() == 0)
            return {};
        
        vector<string> ans;
        vector<string> curr = {};
        gen(s,ans,0,curr);

        return ans;
    }
    // Time: O(n*2^(n-1))
    // Space: O(n*2^(n-1))
};

int main(){
    string s = "1234";

    BruteForceSolution bfsol;
    cout << "Generate All Decompositions:" << endl;
    vector<string> ans = bfsol.generateDecompositions(s);

    for (string s : ans)
        cout << s << endl;

    BruteForceSolution2 bfsol2;
    cout << "Generate All Decompositions2:" << endl;
    ans = bfsol2.generateDecompositions(s);

    for (string s : ans)
        cout << s << endl;
    

    return 0;
}