// [1, 2, 4, 100]

// [2, 100, 4, 1]
// [1, 2, 4, 100]

// n <= 50 cards

/*

1. randonAmountSwaps = 1 (up to n) 
2. Do those swaps: 
   i = randonIndex()
   j = randonIndex()
   swap(deck[i],deck[j])

---------------------------------------------------------------------

[ [1, 2, 4, 100] [2, 100, 4, 1] [1, 2, 4, 100] ... [100, 2, 4 ,1] ]
       0               1             2                  N
too expensive

---------------------------------------------------------------------
    0   1   2    3
   [4] [100] [1] [2]
                    x

-> [ . . . . ]


*/

//  0 1 2
// [2 3 1]
// [2 1 3]
// [3 2 1]

// randonIndex : 0
// i : 0 
// n : 3  
 
#include <bits/stdc++.h>

using namespace std;

void shuffle(vector<int> &deck){
	int n = deck.size();
    for (int i=n-1;i>0;--i){
    	int randonIndex = rand() % i+1; // [0,n)
        swap(deck[i],deck[randonIndex]);
    }
}
// Time: O(n)
// Space: O(1)

// insert: 4	deck: [2 3 1]
//   			[2 4 3 1]
// 		    [4 2 3 1]
//             [2 3 4 1]
//             [2 3 1 4]
// n -> n+1

//   randonIndex: 1
//    0 1 2 3
//   [2 4 3 1]
    
//     i: 1
  
void shuffleInto(int id, vector<int> &deck){
	int n = deck.size();
  	int randonIndex = rand() % (n+1);
  	deck.push_back(id);
    
    for (int i=n;i>randonIndex;--i){
    	swap(deck[i],deck[i-1]);
    }   
}
// Time: O(n)
// Space: O(1)

// deck: [ 0 2 5 1 ]

// sheffleInto : [10 -> 100]
