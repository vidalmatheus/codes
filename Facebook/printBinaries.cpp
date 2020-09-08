#include <bits/stdc++.h>

using namespace std;

/*

0
1
00
01
10
11
000
001
010
011
100
101
111
...

n = 2 + 4 + 8 + ... + 2^k => 2^k = n - (2+4+8+...+2^k-1) = n - 2^k - 2 => 2^(k+1) = n-2

queue:  000, 001, 010, 011, 100, 101, 110, 111

0
1
00
01
10
11

*/

void generatePattern(int n){
    queue<string> q;
    q.push("0");
    q.push("1");
    for (int i=0;i<n;i++){
        string curr = q.front();
        cout << curr << endl;
        q.pop();
        q.push(curr+"0");
        q.push(curr+"1");
    }
}
// Time: O(n)
// Space: O(log n)

int main(){
    generatePattern(15);
    return 0;
}