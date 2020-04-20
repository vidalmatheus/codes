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
    int evalRPN(vector<string>& tokens) {
        if (tokens.size()==0)
            return 0;
        
        stack<int> nums;
        for (int i=0;i<tokens.size();i++){
             string elem = tokens[i];
            if (elem!="+" && elem!="-" && elem!="*" && elem!="/")
                nums.push(stoi(elem));
            else{
                int x = nums.top();
                nums.pop();
                int y = nums.top();
                nums.pop();
                
                int result = 0;
                if (elem=="+") result = y+x;
                if (elem=="-") result = y-x;
                if (elem=="*") result = y*x;
                if (elem=="/") result = y/x;
                nums.push(result);
            } 
        }
        
        return nums.top();
    }
};
// Time: O(n)
// Space: O(n)

int main(){ 
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    Solution sol;
    cout << sol.evalRPN(tokens) << endl;

    return 0;
}
