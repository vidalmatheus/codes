#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
void buildGraph(map<vector<int>,set< vector<int> > >& graph, vector<int>& node){
  if (graph.find(node) != graph.end())
    return;
  int n = node.size();
  for (int i=0;i<n;++i){
    for (int j=i+1;j<n;++j){
      vector<int> neighbor = node;
      reverse(neighbor.begin()+i,neighbor.begin()+j+1);
      graph[node].insert(neighbor);
      buildGraph(graph,neighbor);
    }
  }
}

int bfs(map<vector<int>,set< vector<int> > >& graph, vector<int>& start, vector<int>& last){
  set<vector<int>> visited;
  queue<vector<int>> q;
  q.push(start);
  int level = 0;
  while (!q.empty()){
      int size = q.size();
      for (int i=0;i<size;++i){
        vector<int> node = q.front();
        q.pop();
        if (node == last)
          return level;      
        visited.insert(node);
        
        for (auto neighbor:graph[node]){
          if (visited.find(neighbor) == visited.end()){ // not found
            q.push(neighbor);
          }
        }
      }
      level++;
  }
  
  return level;
}


int minOperations(vector <int> arr) {
    /*
    1. build a graph (do a reversal from node to its neighbor)
    2. bfs from input to the sorted input -> shortest path 
    Time: O(N! * N^3*log N)
    Space: O(N! * N)
    */
    vector<int> last = arr;
    sort(last.begin(),last.end());
    map<vector<int>,set< vector<int> >> graph;
    buildGraph(graph,arr);
  
    /*
    for (auto elem:graph){
      cout << "[ ";
      for (int i:elem.first)
        cout << i << " ";
      cout << "]: ";
      for (auto neigh:elem.second){
        for (int i:neigh)
          cout << i << " ";
         cout << " ";
      }
      cout << endl;
    }
    */
  
    return bfs(graph,arr,last);
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  int n_1 = 5;
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}