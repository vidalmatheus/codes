#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BruteForceSolution {
public:
    int numTeams(vector<int>& rating) {
        if (rating.size()==0)
            return 0;
        
        int counter = 0;
        for (int i=0;i<rating.size();i++){
            for (int j=i+1;j<rating.size();j++){
                for (int k=j+1;k<rating.size();k++){
                    if (rating[i]<rating[j] && rating[j]<rating[k])
                        counter++;
                    if (rating[i]>rating[j] && rating[j]>rating[k])
                        counter++;
                }
            }
        }
        
        return counter;
    }
};
// Time: O(n^3)
// Space: O(1)

class Solution {
private:
    const int BEFORE = 0;
    const int AFTER = 1;
public:
    int numTeams(vector<int>& rating) {
        if (rating.size()==0)
            return 0;
        
        int counter = 0;
        for (int mid=1;mid<rating.size();++mid){
            vector<int> less(2,0);
            vector<int> greater(2,0);
            for (int pos=0;pos<rating.size();++pos){
                if (rating[pos]<rating[mid])
                    less[pos<mid ? BEFORE : AFTER]++;
                if (rating[mid]<rating[pos])
                    greater[pos<mid ? BEFORE : AFTER]++;
            }
            
            counter += less[BEFORE]*greater[AFTER] + greater[BEFORE]*less[AFTER];
        }
        
        return counter;
    }
};
// Time: O(n^2)
// Space: O(1)


int main(){
    vector<int> rating = {2,5,3,4,1};

    Solution sol;
    cout << sol.numTeams(rating) << endl;

    return 0;
}
