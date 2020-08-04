#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int solution(vector<int>& v){
    if (v.size() == 0)
        return -1;
    
    int prev_sum = v[0];
    int curr_sum = v[0];
    for (int i=1;i<(int)v.size();i++){
        prev_sum = curr_sum;
        curr_sum += v[i];
        int start = prev_sum;
        int end = v[i];
        if (start + 1 < end)
            return start+1;

    }

    return curr_sum+1;
}
// Time: O(n)
// Space: O(n)

/*
       i
{1,1,3,4}
prev_sum = 5
(start,end) = (5,4)
curr_sum = 9

*/

int main(){
    vector<int> v = {1, 3, 6, 10, 11, 15};
    assert(solution(v) == 2);

    v = {1, 1, 1, 1};
    assert(solution(v) == 5);

    v = {1, 1, 3, 4};
    assert(solution(v) == 10);

    v = {1, 2, 5, 10, 20, 40};
    assert(solution(v) == 4);

    v = {1, 2, 3, 4, 5, 6};
    assert(solution(v) == 22);

    cout << "Passed!" << endl;

    return 0;
}
