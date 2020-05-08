#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size()==2)
            return true;
        
        vector<int> P = coordinates[0];
        vector<int> Q = coordinates[1];
        
        vector<float> coef = buildLine(P,Q);
        
        for (int i=2;i<coordinates.size();i++)
            if (!belongs2Line(coef,coordinates[i]))
                return false;
        
        return true;
    }
    
    vector<float> buildLine(vector<int>& P, vector<int>& Q){
        float A;
        float B;
        float C;
        if (P[0]==Q[0]){
            A = 1;
            B = 0;
            C = P[0];
        }
        else if (P[1]==Q[1]){
            A = 0;
            B = 1;
            C = P[1];
        }
        else {
            A = (P[1]-Q[1])*1.0/((P[1]-Q[1])*P[0] - (P[0]-Q[0])*P[1]);
            B = -A*(P[0]-Q[0])*1.0/(P[1]-Q[1]);
            C = 1;
        }
        
        return {A,B,C};
    }
    
    bool belongs2Line(vector<float>& coef, vector<int>& point){
        return abs(coef[0]*point[0]+coef[1]*point[1] - coef[2]) <= exp(-6*log(10));
    }
};
// Time: O(n)
// Space: O(1)

int main(){
    vector<vector<int>> coordinates{
        {1,2},
        {2,3},
        {3,4},
        {4,5},
        {5,6},
        {6,7}
    };

    Solution sol;
    sol.checkStraightLine(coordinates) ? cout << "true\n" : cout << "false\n";

    return 0;
}
