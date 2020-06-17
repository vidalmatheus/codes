#include <bits/stdc++.h>

using namespace std;

/*
You are given an array and you need to find number of tripets of indices (i, j, k) such that the elements at those indices are in geometric progression for a given common ratio r  and i < j < k.

For example, arr = [1, 4, 16, 64]. If r = 4 , we have [1, 4, 16] and [4, 16, 64] at indices (0, 1, 2) and (1, 2, 3). Ans = 2

Arr = [1, 2, 2, 4] r = 2
(0, 1, 3), (0, 2, 3) ans = 2


[1, 4, 16, 64], r = 4

[]             0
[1]            0
[1, 4]         0
[1, 4, 16]     1
[1, 4, 64, 16] 2
 0  1   2

A:[1, 2, 1, 2, 4, 8] r = 2
   0  1  2  3  4  5
                  i
Number of expectations:
[2_second]: 2
[2_last]:
[4_second]: 2  
[4_last]: 5 
[8_second]: 
[8_last]: 1
[16_second]: 1 

Count = 4  
def countTriplets(arr, r):
    r2 = Counter()
    r3 = Counter()
    count = 0
    
    for v in arr:
        if v in r3:
            count += r3[v]
        
        if v in r2:
            r3[v*r] += r2[v]
        
        r2[v*r] += 1

    return count


2A:[2  4  2  4  8  16]

4A:[4  8  4  8  16 32]

A: look for [1,2,4], using hashmap (linear)

(0, 1, 4)
(1, 4, 5)
[1] [2] [1, 2, 4]
                 


[1]: {0,2}
[2]: {1,3}
[4]: {4}

0->1->4

0->1->4
0->3->4

1->4->x

2->3->4

3->x


[4,4,4,4,4,4], r = 1
 0 1 2 3 4 5
N-1 + n-2
N-1 + n-3
N-1 + n-4
...

(N-1)*(n-3) + n-2 + n-3 + … + 1 = n^2

arr[i]*r = 2

(0,1,4)
(0,3,4)
(2,3,4)
       

Build hash-map -> O(n)
Traverse from index 0 and check a path -> O(n^2)

*/

int countTriplet(vector<int>& nums, int r){
    unordered_map<int,int> second;
    unordered_map<int,int> last;

    int counter = 0;
    for (int i:nums){
        if (second.find(i) != second.end())
            last[i*r] += second[i];

        if (last.find(i) != last.end())
            counter += last[i];

        second[i*r]++;
    }

    return counter;
}

int main(){
    vector<int> nums{1,2,2,4};
    int r = 2;

    cout << countTriplet(nums,r) << endl;

    return 0;
}
