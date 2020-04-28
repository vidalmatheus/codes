#include <bits/stdc++.h>

using namespace std;

// (0-255, 0-255, 0-255)
//  RED.   GREEN. BLUE
// A1 = 16*A + 1; F4 - 16*F + 4; 67 = 16*6 + 7
// AA BB CC -> ABC
// AB BB CC -> ABC
// XYZ -> XXYYZZ

////

/*

input: string with 6 bytes
output: string with 3 bytes


input: BB AB CC 
output: B A C -> BBAACC

171/17 = 10


XXYYZZ -> XYZ
AB BB CC -> BBC -> AA BB CC

16*10 + 11 = 171 AB

16*11 + 11 = 187 BB

16*10 + 10 = 170 


XY

(16*X + Y)/17 = Z (integer)


AF --> CC

A = 10  -> AB C DEF
F = 15

*/

// XY => 16*X + Y
// Z => 16*Z + Z
// Z = int((16*X + Y) / 17.0 + 0.5)

class Solution{
public:
    string similarRGBColor(string& input){ 
        string ans = "";
        for (int i=0;i<input.size();i+=2)
            ans += defineColor(input,i);
        return ans;
    }
  
    char defineColor(string input, int index){
        int Z = round((16*char2int(input[index]) + char2int(input[index+1]))/17.0);
        return int2char(Z);
    }
  
  	int char2int(char c) {
      if (c >= '0' && c <= '9')
        return c - '0';
      if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
      if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    }
  
  	char int2char(int i) {
      if (i < 10)
        return i + '0';
      return i - 10 + 'A';
    }
};
// Time: O(1)
// Space: O(1)
  
int main() {
    string input = "BBABCC";
    
    Solution sol;
    cout << sol.similarRGBColor(input) << endl;  
  
    return 0;
}
