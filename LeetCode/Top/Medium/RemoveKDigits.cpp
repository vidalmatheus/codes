#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

1432219
1###219 --> 1##219
0123456     012345

*/

class WRONGSolution {
public:
    string removeKdigits(string num, int k) {
        if (k==0)
            return num;
        
        if (k==num.size())
            return "0";
        
        int counter = 0;
        for (int i=1;i<num.size();i++){
            if (counter<k){
                if (num[i-1]<num[i]){
                    num.erase(i--,1); // str.erase(<pos>,<len>)
                    counter++;
                }
                else if (num[i-1]>num[i]) {
                    num.erase(i-1,1);
                    counter++;
                    i--;
                }
                
                if (counter==k)
                    break;
            }
        }
        
        while (num[0]=='0')
            num.erase(0,1);
        
        if (counter == 0)
            num.erase(0,k);

        return num == "" ? "0" : num;
    }
};
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k==0)
            return num;
        
        if (k==num.size())
            return "0";
        
        // build stack
        stack<char> s;
        for (char c:num){
            while (!s.empty() && k>0 && s.top()>c){
                s.pop();
                k--;
            }
            
            if (!s.empty() || c!='0')
                s.push(c);
        }
        
        
        while (!s.empty() && k-->0)
            s.pop();
        
        if (s.empty())
            return "0";
        
        int i = num.size()-1;
        while (!s.empty()){
            num[i--] = s.top();
            s.pop();
        }
        
        return num.substr(i+1);
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    string num = "1432219";
    int k = 3;

    Solution sol;
    cout << sol.removeKdigits(num,k) << endl;

    return 0;
}
