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
    int myAtoi(string str) {
        int begin=0;
        int end=str.size()-1;
        while (str[begin]==' '){
            begin++;
        }
        if (begin>=str.size()) return 0;
        int signal;
        if ( (str[begin]<'0' || str[begin]>'9') && (str[begin+1]<'0' || str[begin+1]>'9') ) return 0;
        if (str[begin]=='+'){
            signal = 1;
            begin++;
        }
        if (str[begin]=='-'){
            signal = -1;
            begin++;
        }
        while (str[begin]=='0'){
            begin++;
        }
        for (int i=begin;i<str.size();i++){
            if (str[i]<'0' || str[i]>'9'){
                end=i-1;
                break;
            }   
        }
        if (end<begin) return 0;
        str = str.substr(begin,end-begin+1);
        if (str.size()>10) 
            return signal>0?INT_MAX:INT_MIN;
        double ans=0;
        double base=1;
        for (int i=str.size()-1;i>=0;i--) {
            ans+=(str[i]-'0')*base;
            base*=10;
            if ((double)ans*signal > (double)INT_MAX || (double)ans*signal < (double)INT_MIN) 
                return signal>0?INT_MAX:INT_MIN;
        }
        return int(ans*signal);
    }
};

int main(){
    Solution sol;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    cout << sol.myAtoi("-2147483648") << endl;
    return 0;
}