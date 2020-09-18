#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.size() == 0)
            return false;
        
        string str = "";
        for (int num:data){
            bitset<8> bin(num);
            str.append(bin.to_string());
        }
        
        return rec(str,0);
    }
    
    // 01234567 89 10 11 12 13 14 15 16
    // 11000101 10  0  0  0  0  1  0  0 0000001.
    
    bool rec(string& str, int pos){
        if (pos == str.size())
            return true;
        
        if (str[pos] == '0'){ // 1-byte
            return rec(str, pos+8);
        }
        else if (pos+9 < str.size() && str[pos] == '1' && str[pos+1] == '1' && str[pos+2] == '0'){ // 2-byte
            if (str[pos+8] == '1' && str[pos+9] == '0'){
                return rec(str, pos+16);
            }
            else return false;
        }
        else if (pos+17 < str.size() && str[pos] == '1' && str[pos+1] == '1' && str[pos+2] == '1' && str[pos+3] == '0'){ // 3-byte
            if (str[pos+8] == '1' && str[pos+9] == '0'){
                if (str[pos+16] == '1' && str[pos+17] == '0'){
                    return rec(str, pos+24);
                }
                else return false;
            }
            else return false;
        }
        else if (pos+25 < str.size() && str[pos] == '1' && str[pos+1] == '1' && str[pos+2] == '1' && str[pos+3] == '1' && str[pos+4] == '0'){ // 4-byte
            if (str[pos+8] == '1' && str[pos+9] == '0'){
                if (str[pos+16] == '1' && str[pos+17] == '0'){
                    if (str[pos+24] == '1' && str[pos+25] == '0'){
                        return rec(str, pos+32);
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;    
    }    
};
// Time: O(8*n) = O(n)
// Space: O(n/8) = O(n)

int main(){
    Solution sol;
    
    vector<int> data1 = {197, 130, 1};
    assert(sol.validUtf8(data1) == true);

    vector<int> data2 = {235, 140, 4};
    assert(sol.validUtf8(data2) == false);

    cout << "Passed!" << endl;
    return 0;
}