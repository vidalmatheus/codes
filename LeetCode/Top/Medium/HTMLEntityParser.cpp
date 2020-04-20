#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SlowSolution { // replace in long string cost time
public:
    string entityParser(string text) {
        if (text.size()==0)
            return "";
        
        unordered_map<string,string> m;
        m["&quot;"]="\"";
        m["&apos;"]="'";
        m["&amp;"]="&";
        m["&gt;"]=">";
        m["&lt;"]="<";
        m["&frasl;"]="/";
               
        string partial;
        int i = 0;
        while (i<text.size()) {
            char c = text[i];
            
            if (c == '&')
                partial.push_back(c);
            else if (!partial.empty())
                partial += c;
            
            if (m.find(partial) != m.end()) {
                text.replace(i+1 - partial.size(), partial.size(), m[partial]);
                i = i+1 - partial.size()+m[partial].size();
                partial = "";
            }
            else i++;
        }

        return text;
    }
};
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> m = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
        };
        
        string ans, partial;
        for (char c : text) {
            ans += c;
            
            if (c == '&') 
                partial.push_back(c);
            else if (!partial.empty())
                partial += c;
            
            if (m.find(partial) != m.end()) {
                ans.replace(ans.size() - partial.size(), partial.size(), m[partial]);
                partial = "";
            }
        }
        
        return ans;
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    // string text = "&amp;amp;";
    // string text = "&amp;gt;";
    string text = "and I quote: &quot;...&quot;";

    Solution sol;
    cout << sol.entityParser(text) << endl;

    return 0;
}
