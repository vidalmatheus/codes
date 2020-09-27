#include <bits/stdc++.h>

using namespace std;

int main(){

    // split with ','
    string input = "matheus,vidal,de,menezes";
    string item;
    stringstream ss;
    ss.str(input);

    cout << "\ninput: " << input << endl;
    while (getline(ss, item, ',')){
        cout << "item: " << item << endl;
    }

    ss.clear(); // you have to clear the stringstream to use it again

    // split with ' '
    string input2 = "abacaxi maca pera banana";
    ss.str(input2);

    cout << "\ninput: " << input2 << endl;
    while (getline(ss,item,' ')){
        cout << "item: " << item << endl;
    }

    ss.clear();

    // split with 'a'
    string input3 = "abracadabra";
    ss.str(input3);

    cout << "\ninput: " << input3 << endl;
    while (getline(ss,item,'a')){
        cout << "item: " << item << endl;
    }

    return 0;
}