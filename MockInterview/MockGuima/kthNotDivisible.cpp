// You are given two positive integers n and k. Print the k-th positive integer that is not divisible by n.

// n = 3 k = 7 => r = 10
   
   // from m = 1 up to k:
   	// add to answer (m+m%n+m/n)
//    6+0+6/3 = 8
//    7+1+7/3 = 10
   
//   4 / 3 = 1 , 4 % 3 = 1 -> 4-1 = 3
//   5 / 3 = 1 , 5 % 3 = 2 -> 5-1 = 4
//   7 / 3 = 2 -> 7-2=5
//   8 / 3 = 2 -> 8-2 = 6
//   10 /3 = 3 -> 10-3 = 7

//    15+15%3+15/3 = 15+0+5 = 20
   
//    7/2 = 3
   
//    2/2+2
   
//  1 2       3 4       5 6       7    8  9  10 11 12 13 14                           7+7%3 7/3 = 7+ 1+2 = 10
// [ 1 2 ] 3 [ 4 5 ] 6 [ 7 8 ] 9 [ 10  11] 13 14 16 17 19 20
 //                  
//			      3 6 9 12 15 18 ... 
// #divisors: 2 4 3   

//    k = 4
//    if (5-5/3 == k)
   
//  [1 2 3 4 5 6 7 8 9 10]
//   l 			m	    r


// counter = 0
// start at 1

#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int kth_not_divisible(int n, int k){
  int q = k/(n-1);
	if(k%(n-1) == 0) q--;
	return k+q;
}

int main(){
	int t, n, k;
  cin >> t;
  for (int i=0;i<t;i++){
  	cin >> n;
    cin >> k;
    cout << kth_not_divisible(n,k) << endl;
  }
  
	return 0;
}