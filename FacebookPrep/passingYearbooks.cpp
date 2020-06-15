#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findSignatureCountsNaive(vector <int> arr) {
  // Write your code here

  /*
     1-> 2 -> 1 --> count how many edges until it get back to myself
     2-> 1 -> 2
    
     1. I have the edges
     2. do dfs until the yearbook hit myself
  */
  
  int n = arr.size();
  vector<int> output(n,0);
  
  for (int i=0;i<n;++i){
    vector<bool> visited(n+1,false);
  
    stack<int> s;
    s.push(i+1);
    while (!s.empty()){
      int node = s.top();
      s.pop();
      output[node-1]++;
      visited[node] = true;
      
      if (!visited[arr[node-1]]) 
        s.push(arr[node-1]); 
    }
  }

  return output;  
}
// Time: O(n²)
// Space: O(n)

void dfs(vector<int>& arr, vector<bool>& visited, vector<int>& output, int start){
    stack<int> s;
    s.push(start);
    int counter = 0;
    while (!s.empty()){
      int node = s.top();
      s.pop();
      counter++;
      visited[node] = true;
      
      if (!visited[arr[node-1]]) 
        s.push(arr[node-1]); 
    }
    
    int n = arr.size();
    for (int i=1;i<=n;++i){
        if (visited[i] && output[i-1] == 0)
            output[i-1] = counter;
    }
}
// Time: O(k), where k is the sisze of the input graph's component
// Space: O(k)

vector <int> findSignatureCounts(vector <int> arr) {
  // Write your code here

  /*
     1-> 2 -> 1 --> count how many edges until it get back to myself
     2-> 1 -> 2
    
     1. I have the edges
     2. do dfs for each component
  */
  
  int n = arr.size();
  vector<int> output(n,0);
  vector<bool> visited(n+1,false);

  for (int i=1;i<=n;++i){
      if (!visited[i])
        dfs(arr,visited,output,i);
  }

  return output;  
}
// Time: O(n)
// Space: O(n)

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  int n_1 = 2;
  vector <int> arr_1{2, 1};
  vector <int> expected_1{2, 2};
  vector <int> output_1 = findSignatureCounts(arr_1);
  check(expected_1, output_1);

  int n_2 = 2;
  vector <int> arr_2{1, 2};
  vector <int> expected_2{1, 1};
  vector <int> output_2 = findSignatureCounts(arr_2);
  check(expected_2, output_2);

  int n_3 = 5;
  vector <int> arr_3{4, 3, 2, 5, 1};
  vector <int> expected_3{3, 2, 2, 3, 3};
  vector <int> output_3 = findSignatureCounts(arr_3);
  check(expected_3, output_3);
  // Add your own test cases here
  
}