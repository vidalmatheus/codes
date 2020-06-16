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
    string validIPAddress(string IP) {
        if (IP.size() == 0)
            return "Neither";
        
        
        vector<string> parts;
        int n = IP.size();
        string part = "";

        // This following block of logic is important to know, 'cause it split a string with specific separators
        for (int i=0;i<n;++i){
            char c = IP[i];
            if (c != '.' && c != ':'){
                if (!isalpha(c) && !isdigit(c))
                    return "Neither";
                part += c;
                if (part.size() > 4)
                    return "Neither";
            }
            else {
                parts.push_back(part);
                part = "";
            }            
        }
        parts.push_back(part); // add last part, don't forget it!       

        if (parts.size() == 4)
            return isIPV4(parts);
        else if (parts.size() == 8)
            return isIPV6(parts);   
        return "Neither";
    }
    
    string isIPV4(vector<string>& parts){ // O(n)        
        for (string part:parts){
            if (part.size() == 0)
                return "Neither";
            
            if (part[0] == '0' && part.size() >= 2)
                return "Neither";
            
            for (char c: part)
                if (isalpha(c))
                    return "Neither";
            
            int num = stoi(part);
            if (0 > num || num > 255)
                return "Neither";
        }
        
        return "IPv4";
    }
    
     string isIPV6(vector<string>& parts){ // O(n)         
        for (string part:parts){
            if (part.size() > 4 || part.size() == 0)
                return "Neither";
            
            for (char c: part){
                if (isalpha(c)) {
                    c = tolower(c);
                    if ('a' > c || c > 'f')
                        return "Neither";
                }
                else if ('0' > c || c > '9')
                    return "Neither";
            }
        }
        
        return "IPv6";
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    string IP = "162.1.255.1";

    Solution sol;
    cout << sol.validIPAddress(IP) << endl;

    return 0;
}
