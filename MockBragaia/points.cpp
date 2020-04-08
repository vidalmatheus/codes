#include <bits/stdc++.h>
using namespace std;

/*
17:05 - 17:45

array of points on <x,y> plane
<0,1> <0,2> <0,3> <0,4> <0,5>
k=3 closest points to origin
{ <0,1> <0,2> <0,3> }

*/

/*

// max_heap solution -> Time: O(n*log(k)), Space: O(k)
// pops: Time: O(k), Space: O(k)

// Overall: Time: O(n*log(k)), Space: O(k) 

<<0,1>,1>

{ <0,1> , <3,4>, <1,1>, <0,3> }

k: 2
max_heap: {}
ans: {<1,1>,<0,1>} 
top: 

*/

double dist (pair<double,double>& point){
  return point.first*point.first + point.second*point.second;
}

vector<pair<double,double>> solution(vector<pair<double,double>>& points, int k){
  priority_queue<pair<double,pair<double,double>>> h;
  
  for (int i=0;i<k;i++){
    h.push(make_pair(dist(points[i]),points[i]));
  }
  
  for (int i=k;i<(int)points.size();i++){
    if (dist(points[i])<h.top().first){
      h.pop();
      h.push(make_pair(dist(points[i]),points[i]));
    }
  }
  
  vector<pair<double,double>> ans;
  for (int i=0;i<k;i++){
    ans.push_back(h.top().second);
    h.pop();
  }
  
  return ans;
}
  
int main() {
  vector<pair<double,double>> points = {{0,1} , {3,4}, {1,1}, {0,3}};
  int k = 2;
  
  vector<pair<double,double>> ans = solution(points,k);
  
  for (auto p:ans){
    cout << "<" << p.first << ", " << p.second << ">  ";
  }
  
  
  return 0;
}
