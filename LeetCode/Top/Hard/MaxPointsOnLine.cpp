#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*

(x,y) lie on r if, and only if, y = Ax + B

*/

class FirstSolution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()==0)
            return 0;
        
        if (points.size()==1)
            return 1;
        
        int maxPoints = 0;
        map<vector<double>,int> m;
        for (int i=0;i<points.size();i++){
            for (int j=i+1;j<points.size();j++){
                vector<double> line = buildLine(points[i],points[j]);
                int counter = 0;
                if (line.size()==0)
                    counter = 2;
                else{
                    cout << "A: " << line[0] << endl;
                    cout << "B: " << line[1] << endl;
                    cout << "C: " << line[2] << endl;
                    cout << endl;
                    if (m.find(line)!=m.end())
                        counter = m[line];
                    else {
                        for (int k=0;k<points.size();k++)
                            if (lieOnLine(points[k],line))
                                counter++;
                    }
                }
                
                m[line] = counter;
                maxPoints = max(maxPoints,counter);
            }
        }
        
        return maxPoints;
    }
    
    
    bool lieOnLine(vector<int>& point, vector<double>& line){
        return line[0]*point[0] + line[1]*point[1] + line[2] == 0;    
    }
    
    vector<double> buildLine(vector<int>& P, vector<int>& Q){
        double A,B,C;
        if (P[0] == Q[0]){
            if (Q[0] == Q[0])
                return {};
            else {
                B = 0;
                if (P[0]!=0){
                    C = 1;
                    A = -1.0/P[0];
                }
                else {
                    C = 0;
                    A = 1;
                }
            }
        }
        else if (P[1]==Q[1]) {
            A = 0;
            if (P[1]!=0){
                C = 1;
                B = -1.0/P[1];
            }
            else {
                C = 0;
                B = 1;
            }
        }
        else if ((P[1]-Q[1] - P[1]*(P[0]-Q[0])) == 0) {
            C = 0;
            B = 1;
            A = -(P[1]-Q[1])*1.0/(P[0]-Q[0]);         
        }
        else {
            C = 1;
            B = (P[0]-Q[0])*1.0/(P[1]-Q[1] - P[1]*(P[0]-Q[0]));
            A = -B*(P[1]-Q[1])*1.0/(P[0]-Q[0]);
        }
        
        return {A,B,C};    
    }
};
// Time: O(n^2)
// Space: O(1)

class BruteForceSolution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()<3)
            return points.size();
        
        int maxPoints = 2;
        for (int i=0;i<points.size();i++){
            int samePoints = 1;
            for (int j=i+1;j<points.size();j++){
                long int x1 = points[i][0];
                long int y1 = points[i][1];
                long int x2 = points[j][0];
                long int y2 = points[j][1];
                
                int counter = 0;
                if (x1==x2 && y1==y2){
                    for (int k=0;k<points.size();k++)
                        if (points[k][0] == x1 && points[k][1] == y1)
                            counter++;
                }
                else {
                    for (int k=0;k<points.size();k++){
                        long int x3 = points[k][0];
                        long int y3 = points[k][1];
                        if ((y3 - y2) * (x2-x1) == (x3 - x2) * (y2 - y1))
                            counter++;
                    }
                }
            
                maxPoints = max(maxPoints,counter);  
                
            }
        }
        
        return maxPoints;
    }  
};
// Time: O(n^3)
// Space: O(1)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()<3)
            return points.size();
        
        int maxPoints = 2;
        for (int i=0;i<points.size();i++){
            long double x1 = points[i][0];
            long double y1 = points[i][1];
            unordered_map<long double,int> slopes;
            int samePoints = 1;
            int localMax = 0;
            for (int j=i+1;j<points.size();j++){
                long double x2 = points[j][0];
                long double y2 = points[j][1];
                
                int counter = 0;
                long double slope;
                if (x1==x2 && y1==y2)
                    samePoints++;
                else if (x1==x2){
                    slope = INFINITY;
                    if (slopes.find(slope)!=slopes.end())
                        slopes[slope]++;
                    else slopes[slope] = 1;
                }
                else {
                    slope = (y2-y1)/(x2-x1);
                    if (slopes.find(slope)!=slopes.end())
                        slopes[slope]++;
                    else slopes[slope] = 1;
                }

                localMax = max(localMax,slopes[slope]);
            }
            
            localMax += samePoints;
            maxPoints = max(maxPoints,localMax);
        }
        
        return maxPoints;
    }  
};
// Time: O(n^2)
// Space: O(n^2)


int main(){
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};

    Solution sol;
    cout << sol.maxPoints(points) << endl;

    return 0;
}
