#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
[23:59, 00:00, 23:58]

[00:00, 23:58, 23:59, ...]

*/

class SlowSolution { // Ok, but, you're not using the fact that you have times as an input!
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size()==0)
            return 0;
        
        sort(timePoints.begin(),timePoints.end());
        
        int minDif = INT_MAX;
        int size = timePoints.size();
        for (int i=1;i<=size;i++){
            int dif = timeDif(timePoints[i%size],timePoints[i-1]);
            minDif = min(dif, minDif);
        }
        
        return minDif;
    }
    
    int timeDif(string& timeA, string& timeB){
        int minuteA = stoi(timeA.substr(0,2))*60 + stoi(timeA.substr(3,2));    
        int minuteB = stoi(timeB.substr(0,2))*60 + stoi(timeB.substr(3,2));
    
        int dif = abs(minuteA - minuteB);
        return dif>720 ? 1440-dif : dif;
    }
    
};
// Time: O(nlog n)
// Space: O(log n)

class Solution { // Bucket Sort!!!
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size()==0)
            return 0;
        
        vector<bool> buckets(1440,false);
        for (int i=0;i<timePoints.size();i++){
            int minute = toMinute(timePoints[i]);
            if (!buckets[minute]) 
                buckets[minute] = true;
            else return 0;
        }
        
        int minDif = INT_MAX;
        int first = -1;
        int last = -1;
        for (int j=-1,i=0;i<buckets.size();i++){
            if (first == -1 && buckets[i]){
                j = i;
                first = i;
            }
            else if (buckets[i]) {
                minDif = min(minDif,i-j);
                j = i;
                last = i;
            }
        }
            
        return min(first-last+1440,minDif);
    }
    
    int toMinute(string& time){
        return stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<string> timePoints = {"05:31","22:08","00:35"};

    Solution sol;
    cout << sol.findMinDifference(timePoints) << endl;

    return 0;
}
