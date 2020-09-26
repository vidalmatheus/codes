#include <bits/stdc++.h>

using namespace std;

/*

t = 2  

i-j
  j         i
. .         .
X,X,_,_,_,_,X,X,_ -> [1,n+t]

prev: 0
counter: (2-0) + (2-1) + (2-0) = 5


1)
duration = 2
[1,4]

4-1 = 3 >= duration

counter: 2 + 2 = 4
prev = 1


[1,_,_,4]
 1,2
       4,5


2)
duration = 2
[1,2]

2-1 = 1 < 2

counter: 2 + (2-1) = 3
prev = 1

3)
duration = 5
[1,2,3,4,5]

1,2,3,4,5          -> +5
  2,3,4,5,6        -> +1
    3,4,5,6,7      -> +1
      4,5,6,7,8    -> +1
        5,6,7,8,9  -> +1
                    ------
                       9
4)
duration = 2
[1,2,_,_5,6,_,_,9]
 1,2
   2,3
        5,6
          6,7
                9,10

First approach:
if (cur > lastTimePoisoned){
    counter += duration
}
else counter += cur + duration - 1 - lastTimePoisoned 

lasTimePoisoned = cur + duration - 1
 
Obs.: Another Solution: merge intervals!
[1,2], [2,3], [5,6], [6,7], [9,10]
[1,3], [5,7], [9,10] -> 3 + 3 + 2 = 8

*/

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0 || duration == 0)
            return 0;
    
        int lastTimePoisoned = -1;
        int counter = 0;
        int n = timeSeries.size();
        for (int i=0;i<n;i++){
            int cur = timeSeries[i];
            if (cur > lastTimePoisoned){
                counter += duration;
            }
            else counter += cur + duration - 1 - lastTimePoisoned;

            lastTimePoisoned = cur + duration - 1;
        }
        
        return counter;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    Solution sol;
    
    vector<int> timeSeries1{1,4};
    int duration1 = 2;
    assert(sol.findPoisonedDuration(timeSeries1,duration1) == 4);

    vector<int> timeSeries2{1,2};
    int duration2 = 2;
    assert(sol.findPoisonedDuration(timeSeries2,duration2) == 3);

    vector<int> timeSeries3{1,2,3,4,5,6,7,8,9};
    int duration3 = 1;
    assert(sol.findPoisonedDuration(timeSeries3,duration3) == 9);

    vector<int> timeSeries4{1,2,5,6,9};
    int duration4 = 2;
    assert(sol.findPoisonedDuration(timeSeries4,duration4) == 8);

    vector<int> timeSeries5{1,2,3,4,5};
    int duration5 = 5;
    assert(sol.findPoisonedDuration(timeSeries5,duration5) == 9);
    
    cout << "Passed!" << endl;
    return 0;
}