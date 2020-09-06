#include <bits/stdc++.h>

using namespace std;

/*
After each day, if any plant has more pesticide than the plant on its left, being weaker than the left one, it dies.
P = [3, 6, 2, 7, 5] 	day = 0
P = [3, 2, 5] 	    	day = 1
P = [3, 2] 		day = 2

Ans = 2

P = [3, 6, 8, 7, 5] 
P = [3, 7, 5]
P = [3, 5]
P = [3]

Is answer the maximum size of a non-increasing subsequence? No!

                 i
P = [3, 6, 8, 7, 5] 
P = [3, 7, 5]
newP = [3, 5]  
O(n²)
P = [5, 4, 3, 2, 1, 8, 1, 2, 2]       

newP = [5, 4 … , 1]

P = [1, 2, 3, 4, 5] 
newP = [1]
           X     x   x
P = [6, 5, 8, 4, 7, 10, 9] d = 0
P = [6, 5, 4, 9]		d = 1
P = [6, 5, 4] 			d = 2
*/

// https://www.geeksforgeeks.org/the-stock-span-problem/
// https://www.hackerrank.com/challenges/poisonous-plants/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues

struct plant {
    int pest;
    int days;
};

int poisonousPlants(vector<int> p) {
    stack<plant> st;
    int maxDays = 0;

    int daysAlive;
    for(const int & elem : p)
    {
        daysAlive = 0;
        while(!st.empty() && elem < st.top().pest)
        {
            daysAlive = max(daysAlive, st.top().days);
            st.pop();
        }

        if(st.empty())
            daysAlive = 0;
        else
            daysAlive++;
        
        maxDays = max(maxDays, daysAlive);

        st.push({elem, daysAlive});
    }

    return maxDays;
}
