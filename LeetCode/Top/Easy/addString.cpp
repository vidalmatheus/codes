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

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() == 0)
            return num2;
        if (num2.size() == 0)
            return num1;
        
        while (num1.size() > num2.size())
            num2.insert(0,"0");
        
        while (num1.size() < num2.size())
            num1.insert(0,"0");
        
        int carry = 0;
        int n = num1.size();
        string result(n,'0');
        for (int i=n;i>=0;i--){
            int add = (num1[i]-'0') + (num2[i]-'0') + carry;
            if (add > 9)
                carry = 1;
            else carry = 0;
            
            add %= 10;
            
            result[i] = add+'0';
        }
        
        if (carry > 0){
            string carry_part = "0";
            carry_part[0] = carry+'0';
            result.insert(0,carry_part);
        }
        
        return result;
    }
};
// Time: O(MAX)
// Space: O(1), without extra space


int main(){
    string num1 = "1";
    string num2 = "9";

    Solution sol;
    cout << sol.addStrings(num1,num2) << endl;

    return 0;
}
