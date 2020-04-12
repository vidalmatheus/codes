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
    
        for (auto e:m){
            auto p = text.find(e.first);
            while (p!=string::npos){ // found
                text.replace(p,e.first.length(),e.second);
                p = text.find(e.first);
            }
        }
        
        return text;
        
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    // string text = "&amp; is an HTML entity but &ambassador; is not.";
    // string text = "and I quote: &quot;...&quot;";
    // string text = "Stay home! Practice on Leetcode :)";
    // string text = "x &gt; y &amp;&amp; x &lt; y is always false";
    string text = "leetcode.com&frasl;problemset&frasl;all&apos;";

    Solution sol;
    cout << sol.entityParser(text) << endl;

    return 0;
}
