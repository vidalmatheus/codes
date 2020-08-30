// CPP program to demonstrate the 
// multiset::lower_bound() and multiset::upper_bound functions
#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 

	// Initialize multiset 
	multiset<int> s; 

	s.insert(7); 
  	s.insert(2);
  	s.insert(4);
  	s.insert(3);
  	s.insert(1); 


	int val = 3;
	// iterator pointing to 
	// position where val is 
	auto pos = s.lower_bound(val); // first it, such that *it >= val
  	auto pos2 = s.upper_bound(val); // first it, such that *it > val
  	cout << *(pos) << endl;
  	cout << *pos2 << endl;

	// for the first element that is less than searching element, we do:
	if (pos != s.begin())
		cout << *(--pos) << endl; // now we're printing *it <= val
	else if (*pos <= val)
		cout << *pos << endl;
	else pos = s.end();
	
	return 0; 
} 