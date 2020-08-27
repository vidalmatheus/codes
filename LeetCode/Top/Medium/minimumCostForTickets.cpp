#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    # define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
   i
[1,4,6,7,8,20]

rec(pos):
    if pos == days.size:
        return 0
    
    int response = INT_MAX
    for cost in costs:
        response = min(response, cost + rec(pos+1))
            
    return response
*/

class BruteForceSolution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.size() == 0 || costs.size() == 0)
            return 0;
        
        return rec(days,costs,0);
    }
    
    int rec(vector<int>& days, vector<int>& costs, int pos){
        if (pos >= days.size())
            return 0;
        
        int response = INT_MAX;
        for (int i=0;i<costs.size();i++){
            int cost = costs[i];
            int shift = i == 0 ? 1 : i == 1 ? 7 : 30;
            int nextPos = binarySearch(days,pos,days.size()-1,days[pos]+shift);
                       
            response = min(response, cost + rec(days,costs,nextPos));
        }
        
        return response;
    }
    
    int binarySearch(vector<int>& days, int left, int right, int val){        
        while (left <= right){
            int mid = left + (right - left)/2;
            if (val > days[mid])
                left = mid+1;
            else if (val < days[mid])
                right = mid-1;
            else return mid;
        }
        
        return left;
    }
    
};
// T(n) = 3*logn + 3^n
// Time: O(3^n)
// Space: O(n)

class Solution { // Memoization
private:
    vector<int> memo;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.size() == 0 || costs.size() == 0)
            return 0;
        
        memo.resize(days.size(),-1);
        
        return rec(days,costs,0);
    }
    
    int rec(vector<int>& days, vector<int>& costs, int pos){
        if (pos >= days.size())
            return 0;
        
        if (memo[pos] != -1)
            return memo[pos];
        
        int response = INT_MAX;
        for (int i=0;i<costs.size();i++){
            int cost = costs[i];
            int shift = i == 0 ? 1 : i == 1 ? 7 : 30;
            int nextPos = binarySearch(days,pos,days.size()-1,days[pos]+shift);
                       
            response = min(response, cost + rec(days,costs,nextPos));
        }
        
        return memo[pos] = response;
    }
    
    int binarySearch(vector<int>& days, int left, int right, int val){        
        while (left <= right){
            int mid = left + (right - left)/2;
            if (val > days[mid])
                left = mid+1;
            else if (val < days[mid])
                right = mid-1;
            else return mid;
        }
        
        return left;
    }
    
};
// Time: O(n)
// Space: O(n)

int main(){
    vector<int> days{1,4,6,7,8,20};
    vector<int> costs{2,7,15};

    Solution sol;
    assert(sol.mincostTickets(days,costs) == 11);

    cout << "Passed!" << endl;
    return 0;
}