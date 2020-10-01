#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> nums{1,2,3,4,5};

    cout << "Copying the values..." << endl;
    for (int num : nums)
        num *= 2;

    for (int num : nums)
        cout << num << " ";

    cout << "\nPassing by reference..." << endl;
    for (int & num : nums)
        num *= 2;

    for (int num : nums)
        cout << num << " ";
    
    cout << endl;
    return 0;
}