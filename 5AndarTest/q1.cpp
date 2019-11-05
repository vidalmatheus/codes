#include <bits/stdc++.h>

using namespace std;

string solution(int T) {
    // write your code in C++14 (g++ 6.2.0)
    int hour = T/3600;
    int minutes = (T%3600)/60;
    int seconds = (T%3600)%60;
    return to_string(hour)+'h'+to_string(minutes)+'m'+to_string(seconds)+'s';
}


int main(){
    cout << solution(1) << endl;


    return 0;
}