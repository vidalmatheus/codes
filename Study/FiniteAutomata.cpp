/* Finite Automata to find a sequence, such that it has 3K values of 1, and two consecutives 0 is not allowed. */

#include <bits/stdc++.h>

using namespace std;

int main(){
    // a == 1
    // b == 0
    string input;
    cout << "String: ";
    cin >> input;
    
    int count = 0;
    int state = 0;
    do{
        switch (state)
        {
        case 0: 
            if (input[count]=='a') state = 1;
            else state = 3;
            count++;
            break;
        case 1:
            if (input[count]=='a') state = 2;
            else state = 5;
            count++;
            break;
        case 2:
            if (input[count]=='a') state = 0;
            else state = 7;
            count++;
            break;
        case 3:
            if (input[count]=='a') state = 8;
            else state = 4;
            count++;
            break;
        case 4:
            count++;
            break;
        case 5:
            if (input[count]=='a') state = 6;
            else state = 4;
            count++;
            break;
        case 6:
            if (input[count]=='a') state = 3;
            else state = 4;
            count++;
            break;
        case 7:
            if (input[count]=='a') state = 3;
            else state = 4;
            count++;
            break;
        case 8:
            if (input[count]=='a') state = 9;
            else state = 4;
            count++;
            break;
        case 9:
            if (input[count]=='a') state = 3;
            else state = 4;
            count++;
            break;                                                                                      
        }
    } while(count<input.size());

    if (state == 0 || state == 3) {
        cout << "String Accepted!" << endl;
        cout << "Final State = " << state << endl;
    }
    else if (state == 4) cout << "String NOT Accepted (two b)" << endl;
    else cout << "String NOT Accepted" << endl;

    return 0;
}