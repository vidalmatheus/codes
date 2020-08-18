#include <bits/stdc++.h>

using namespace std;

long goalFromCount (vector<long>& machines, long days){
    long ans = 0;
    for (long d : machines)
        ans += floor(days/d);
    return ans;
}
//O(m) & O(1)

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {// O(m)    
    if (machines.size() == 1)
        return LONG_MAX;

    long left = 0;
    long right = LONG_MAX; 
    while (left < right){
        long mid_day = left + (right-left)/2;
        long local_goal = goalFromCount(machines, mid_day); 
        if (local_goal >= goal)
            right = mid_day;
        else left = mid_day+1;
    }
    return left;
}

int main(){
    vector<long> machines {2,3,2};
    long goal = 10;

    assert(minTime(machines,goal) == 8);

    cout << "Passed!" << endl;

    return 0;
}
