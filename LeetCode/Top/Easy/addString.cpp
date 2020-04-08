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
    string addStrings(string num1, string num2) {
        if (num1.size()== 0)
            return num2;
         
        if (num2.size()==0)
            return num1;
        
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        int carry = 0;
        int sum = 0;
        string ans;
        
        while (p1>=0 || p2>=0){
            sum+=carry;
            if (p1>=0)
                sum+=num1[p1--]-'0';
            
            if (p2>=0)
                sum+=num2[p2--]-'0';
            

            carry = sum/10;
            sum %=10;
            ans.append(to_string(sum));            
        }
        
        if (carry!=0)
            ans.append(to_string(carry));
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    string num1 = "1";
    string num2 = "9";

    Solution sol;
    cout << sol.addStrings(num1,num2) << endl;

    return 0;
}