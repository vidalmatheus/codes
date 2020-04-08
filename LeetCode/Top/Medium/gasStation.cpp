#include <bits/stdc++.h>

using namespace std;

static int speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class SquareSolution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size()==0 || cost.size()==0 || gas.size()!=cost.size())
            return -1;
        
        for (int i=0;i<gas.size();i++){
            if (canTravel(gas,cost,i))
                return i;
        }
        
        return -1;
    }
    
    bool canTravel(vector<int>& gas, vector<int>& cost, int start){
        int fuel = 0;
        int pos = start;
        do {
            fuel += gas[pos]-cost[pos];
            pos = (pos+1)%gas.size();
        }while (pos!=start && fuel>=0);
        
        return fuel>=0;
    }
};
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size()==0 || cost.size()==0 || gas.size()!=cost.size())
            return -1;
        
        int start = 0;
        int fuel = 0;
        int total = 0;
        for (int i=0;i<gas.size();i++){
            total += gas[i]-cost[i]; // to track the if we have the start point, but not enough total gas to travel
            fuel += gas[i]-cost[i];
            if (fuel<0){
                start = i+1;
                fuel = 0;
            }
        }

        return total>=0 ? start : -1;
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    Solution sol;
    cout << sol.canCompleteCircuit(gas,cost) << endl;

    return 0;
}
