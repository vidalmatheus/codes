
/*
A | &x
[1,2,3,4]
32 bits -> 10 digits

. . . .  | . . . . | . . . . | . . . .

0001 & 0001
1000 & 1000
Num & (0001)


&num -> 0xA48B

|00|01

Short int word = 0x0001;
Char * byte = (char *)&word;
byte++
if(byte[0] ==1)
	Return little-endian;
Else
	Return big-endian;

Int getAddress(int& num, int i){
	
}
If (getAddress(num,0) < getAddress(num,1))
	Return “big-endian”;
Else return “little-endian”;

*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    short int word = 0x0001;
    char* byte = (char *) &word;

    if (byte[0] == 1)
        cout << "little-endian" << endl;
    else cout << "big-endian" << endl;

    return 0;
}
