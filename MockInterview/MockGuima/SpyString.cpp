// 19:28h
//You are given n strings a1,a2,…,an: all of them have the same length m. The strings consist of lowercase English letters.

//Find any string s of length m such that each of the given n strings differs from s in at most one position. Formally, for each given string ai, there is no more than one position j such that ai[j]≠s[j].

/*
a b a c -> 1
z b a b -> 1 
a z a b -> 1
a b z b -> 1
z b a b
z b a b
z b a b

{
abac
bbac
cbac
.
.
.
zbac
} O(26)



// Time: O(n*m²)

x: z
x: abab
r: abab

b a b a -> 1
a b a b -> 2
x: aab
r:null


baa
aaa
aab
r: aaa

a
b
c
r: d

aaaa
bbbb
r: null

*/


/*

Time: O(n^m)

rec(<first_char>, <pos>, <ans>)

rec('',0,"");
    rec(a,1,"a"):
        rec(b,2,"ab"):
           rec(a,3,"aba"):
               rec(c,4,"abac"):
                   
               
               rec(b,4):
           
           rec(z,3):
            
        rec(z,2):
    
    rec(z,1):
*/

/*
a b a c
z b a b
a z a b
a b z b
z b a b
z b a b
z b a b
*/

#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool isValid(vector<string>& words,string& candidate){ // O(n*m)
    for (int i=0;i<words.size();i++){
        int counter = 0;
        // cout << "(" << candidate << ", " << words[i] << ")" << endl;
        for (int j=0;j<words[i].size();j++){
            if (words[i][j]!=candidate[j]){
                counter++;
                if (counter == 2)
                    return false;
            }
        }
    }
    
    return true;
}

string solution(vector<string>& words){
    for (int i=0;i<words[0].size();i++){
        string candidate = words[0];  // abac
        for (int j=0;j<26;j++){
            candidate[i] = j+'a';    // abac
            // cout << candidate << endl;
            if (isValid(words,candidate))
                return candidate;
        }
    }
    
    return "-1";
}
// Time: O(m*26*n*m)
// Space: O(1)

int main(){
    int t, n, m;
    cin >> t;
    for (int k=0;k<t;k++){
        cin >> n;
        cin >> m;
        vector<string> words;
        words.reserve(n);
        for (int i=0;i<n;i++){
            string word;
            cin >> word;
            words.push_back(word);
        }
        
        cout << solution(words) << endl;
    }

    return 0;
}