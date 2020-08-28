#include <bits/stdc++.h>

using namespace std;

/*
A string is said to be a special string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria.
  Given a string, determine how many special substrings can be formed from it
       
               i
  s = m[non]opoo
  {m, n, o, n, o, p, o, o, non, ono, opo, oo}
12
  
		1 char -> n
    2 char -> m _
    
    non -> 3 + 1 + 1 + 1
  	ono -> 
  
  
  	      
  	m: 1      1 char -> 8
    n: 1      2 char -> 1
    o: 1      3 char -> 
    n: 1
    o: 1
    p: 1
    o: 2      o o oo
  -------
      8 with 1 char
      aaaa
      a a a a aa aa aa aaa aaa aaaa n(n+1)/2
      4 +3 +2 +1
      1
      2 +1
      3 +2 +1
*/
long substrCount(int n, string s) {
    vector<pair<char, long>> adja;
    char cur = '0';
    long pos = -1;

    for(const char & c : s)
    {
        if(cur == c)
        {
            adja[pos].second++;
        }
        else
        {
            adja.push_back({c, 1});
            cur = c;
            pos++;
        }
    }

    long ans = 0;
    pos++;
    for(long i=0; i < pos; i++)
    {
        //cout << adja[i].first << " " << adja[i].second << endl;
        ans += (adja[i].second*(adja[i].second + 1))/2;
    }

    for(long i=1; i < pos - 1; i++)
    {
        if(adja[i-1].first == adja[i+1].first && adja[i].second == 1)
        {
            ans += std::min(adja[i-1].second, adja[i+1].second);
        }
    }

    return ans;
}

int main(){


    return 0;
}