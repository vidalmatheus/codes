#include <bits/stdc++.h>

using namespace std;

/*
The celebrity knows no one at the party, but everyone knows the celebrity.
There is only one celebrity at the party.
vector<int> ids
Knowledge is not mutual. Person A knowing person B does not imply that person B knows person A.
isFriendsWith(int idA, int B) => true if A knows B, false otherwise.
Who is the celebrity in this party?


[1,2,3,4]


      > 4
    /  |  \
       V   >
  1 -> 2 <- 3  => 2 is the celebrity

(n-1) + (n-1) + (n-1) + (n-1)
Linked list

[1]: 

-----------------------------------------------

I: go for the last candidate
J: go for new candidate

       i
         j
[1 4 3 2]
           

isFriendsWith(1,2) -> true
isFriendsWith(2,3) -> false
isFriendsWith(4,2) -> true


isFriendsWith(3,4) -> false
isFriendsWith(4,2) -> true
isFriendsWith(2,3) -> false
isFriendsWith(3,2) -> true


       i j
[1 4 3 2]

   I j
[1 2]: 1->2
*/

bool isFriendsWith(int a, int b);

int getCelebrity(vector<int>& ids){ // O(n) & O(1)
	if (ids.size() == 1)
		return ids[0];

	int i = 0;
	for (int j=1;j<(int)ids.size();j++){
    if (isFriendsWith(ids[i],ids[j]))
	    i = j;
    }
	
	return ids[i];
}
