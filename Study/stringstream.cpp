#include <bits/stdc++.h>

using namespace std;

int main(){

    // split with ','
    string input = "matheus,vidal,de,menezes";
    string item;
    stringstream ss;
    ss.str(input);

    while (getline(ss, item, ',')){
        cout << item << endl;
    }

    ss.clear(); // you have to clear the stringstream to use it again

    // split with ' '
    string input2 = "abacaxi maca pera banana";
    ss.str(input2);

    while (getline(ss,item,' ')){
        cout << item << endl;
    }

    ss.clear();

    // split with 'a'
    string input3 = "abracadabra";
    ss.str(input3);

    while (getline(ss,item,'a')){
        cout << item << endl;
    }

    return 0;
}