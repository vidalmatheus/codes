#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<unsigned int*> v(100000000);
    int k=0;
    while(1){
        v[k%100000000] = (unsigned int *) malloc (sizeof(int));
        k++;
    }

    return 0;
}