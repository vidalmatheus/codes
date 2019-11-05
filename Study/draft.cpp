// CPP program to demonstrate working of multi_set 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    multiset<int> ms; 
  
    ms.insert(1); 
    ms.insert(3); 
    ms.insert(4); 
    ms.insert(2); 
    ms.insert(2);
    ms.insert(2); 
  
    cout << "Elements in unordered_set:\n"; 
    cout << ms.count(2) << endl;
  
    return 0; 
} 
