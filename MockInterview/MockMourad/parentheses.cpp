/*

19:27 - 20:12

1003. Check If Word Is Valid After Substitutions

We can say that a string is valid if it follows one of the three following cases:

An empty string "" is valid. <-
The string "abc" is also valid.
Any string in the form "a" + str + "bc", "ab" + str + "c", str + "abc" or "abc" + str where str is a valid string is also considered a valid string.

-> For example, "", "abc", "aabcbc", "abcabc" and "abcabcababcc" are all valid strings, while "abccba", "ab", "cababc" and "bac" are not valid strings.
                             -^-
Given a string s, return true if it is a valid string, otherwise, return false.

abc -> valid
-> a + valid + bc -> valid
-> aabcbc -> a + valid + bc

abcabc -> valid, because valid + valid -> valid

valid + invalid -> invalid


S-> valid

...............abc............



a abc bc

reamining = "a" + "bc" = "abc"

0. if s is empty, return true

1. first search for 'abc' substring -> I have the index of "a.."
    1.1 if I don't have it -> return false
    1.2 if I have it
        1.2.1 take out this substring
        1.2.2 call a recursion for the remaning (left + right) ----

*/

/*
T(n) = T(n-3) + O(n) -> n²
Space: n
*/

#include <bits/stdc++.h>

using namespace std;

bool isValid(string& S) {
    if (S.size() == 0)
        return true;
    int index = findABC(S);
    S.erase(index, 3); // O(n)
    return isValid(S);
}

class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        for(char c: S) {
            if(c == 'a') st.push('a');
            else if(c == 'b') {
                if(st.empty() || st.top() != 'a') return false;
                st.push('b');
            }
            else if(c == 'c') {
                if(st.empty() || st.top() != 'b') return false;
                st.pop(), st.pop();
            }
        }
        return st.empty();
    }
};

// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/









