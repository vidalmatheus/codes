#include <bits/stdc++.h>

using namespace std;

int numberOfDigits(int n){ // function to return the number of digits
    int count=0;
    while (n!=0){
        n/=10;
        count++;
    }
    return count;
}

void solution(vector<int> &A, int K) { 
    // write your code in C++14 (g++ 6.2.0)
    if (A.size()<K) // we have to trunc K to its maximum
        K = A.size();
    // first we need to find the maximum value in order to get the maximum number of digits
    int maxDigits=0;
    for (int i=0;i<A.size();i++){
        int n = numberOfDigits(A[i]);
        if (n>maxDigits)
            maxDigits = n;
    }
    for (int j=0;j<A.size()/K;j++){
        for (int p=1;p<=K;p++){ // edges
            cout << "+";
            for (int t=1;t<=maxDigits;t++)
                cout << "-";
        }
        cout << "+" << endl;
        cout << "|";
        for (int i=0;i<K;i++){ // numbers
            printf("%*d", maxDigits, A[j*K+i]);
            cout << "|";
        }
        cout << endl;
    }
    // penult line
    for (int p=1;p<=K;p++){
        cout << "+";
        for (int t=1;t<=maxDigits;t++)
            cout << "-";
    }
    cout << "+" << endl;  

    // if the size of a isn't multiple of K, we have to construct the last line of numbers
    int sizeLastEdge = K;
    if (A.size()%K!=0){ 
        cout << "|";
        for (int i=K*(A.size()/K);i<A.size();i++){ // numbers
            printf("%*d", maxDigits, A[i]);
            cout << "|";
        }
        cout << endl;
        sizeLastEdge = A.size()%K; // change the size of the last edge
        
        // last edge
        for (int p=1;p<=sizeLastEdge;p++){ 
            cout << "+";
            for (int t=1;t<=maxDigits;t++)
                cout << "-";
        }
        cout << "+" << endl;   
    }
}



int main(){
    vector<int> A = {4,35,80,123,12345,44,8,5}; 
/*     vector<int> A = {1000000000,2,59}; */
    int k = 1000;

    solution(A,k);

    return 0;
}