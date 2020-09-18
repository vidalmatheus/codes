#include <bitset> 
#include <iostream> 

using namespace std;
  
int main()  
{ 
    // char* constructor using custom digits 
    bitset<8> b1("XXXXYYYY", 8, 'X', 'Y'); // X -> 0 and Y -> 1
    cout << b1 << endl; // [0, 0, 0, 0, 1, 1, 1, 1]

    try {
        bitset<8> b2("00012010");
        cout << b2 << endl;
    } catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    try {
        bitset<8> b3("XXXXYYYYx", 8, 'X', 'Y'); // X -> 0 and Y -> 1
        cout << b3 << endl;
    } catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    try {
        bitset<8> b4("XXXXYYYY", 9, 'X', 'Y'); // X -> 0 and Y -> 1
        cout << b4 << endl;
    } catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    bitset<8> b5("00101001");
    cout << b5 << endl;
    return 0;
} 
