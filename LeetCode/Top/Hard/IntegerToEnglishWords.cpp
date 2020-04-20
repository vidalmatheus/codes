#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
private:
    unordered_map<int,string> eng;
public:
    Solution(){
        eng[0]="Zero";
        eng[1]="One";
        eng[2]="Two";
        eng[3]="Three";
        eng[4]="Four";
        eng[5]="Five";
        eng[6]="Six";
        eng[7]="Seven";
        eng[8]="Eight";
        eng[9]="Nine";
        eng[10]="Ten";
        eng[11]="Eleven";
        eng[12]="Twelve";
        eng[13]="Thirteen";
        eng[14]="Fourteen";
        eng[15]="Fifteen";
        eng[16]="Sixteen";
        eng[17]="Seventeen";
        eng[18]="Eighteen";
        eng[19]="Nineteen";
        eng[20]="Twenty";
        eng[30]="Thirty";
        eng[40]="Forty";
        eng[50]="Fifty";
        eng[60]="Sixty";
        eng[70]="Seventy";
        eng[80]="Eighty";
        eng[90]="Ninety";
    }
    
    string tens(int n){
        if (n <= 20) 
            return eng[n];
    
        return !(n%10) ? eng[(n/10)*10] : eng[(n/10)*10]+" "+eng[n%10];
    }
    
    string hundreds(int n){
        if (n < 100)
            return tens(n);

        return !(n%100) ? tens(n/100) + " Hundred" : tens(n/100) + " Hundred " + tens(n%100);
    }
    
    string thousands(int n){
        if (n < 1000)
            return hundreds(n);
        
        return !(n%1000) ? hundreds(n/1000) + " Thousand" : hundreds(n/1000) + " Thousand " + hundreds(n%1000);
    }
    
    string millions(int n){
        if (n < 1000000)
            return thousands(n);
        
        return !(n%1000000) ? hundreds(n/1000000) + " Million" : hundreds(n/1000000) + " Million " + thousands(n%1000000);
    }
    
    string billions(int n){
        if (n < 1000000000)
            return millions(n);

        return !(n%1000000000) ? tens(n/1000000000) + " Billion" : tens(n/1000000000) + " Billion " + millions(n%1000000000);
    }
    
    string numberToWords(int num) {
        return billions(num);
    }
};
// Time: O(n)
// Space: O(n)

int main(){
    int num = 1234;

    Solution sol;
    cout << sol.numberToWords(num) << endl;

    return 0;
}
// Time: O(1)
// Space: O(1)
