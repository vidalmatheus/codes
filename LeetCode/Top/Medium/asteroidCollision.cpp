#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// 5 10 -5 9 -11

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        if (n == 0)
            return {};

        vector<int> ans;
        ans.push_back(asteroids[0]);

        for (int i=1; i<n; ++i) {
            int num = asteroids[i];

            if (ans.size() > 0 and num < 0 and ans.back() > 0) {
                if (ans.size() > 0 and abs(num) == ans.back()) {
                    // cout << num << " and " << ans.back() << " die" << endl;
                    ans.pop_back();
                }
                else {
                    bool stop = false;
                    while (ans.size() > 0 and abs(num) >= ans.back() and ans.back() > 0) {
                        if (abs(num) == ans.back()){
                            // cout << num << " and " << ans.back() << " die" << endl;
                            ans.pop_back();
                            stop = true;
                            break;
                        }
                        // cout << num << " removes " << ans.back() << endl;
                        ans.pop_back();
                    }

                    if (stop) continue;

                    if (ans.size() == 0)
                        ans.push_back(num);
                    else if ((abs(num) > ans.back() and ans.back() > 0) or ans.back() < 0)
                        ans.push_back(num);
                    // else cout << ans.back() << " removes " << num << endl;
                }

            }
            else ans.push_back(num);

        }

        return ans;
    }
};
// Time: O(n)
// Space: O(1), constant extra space

int main(){
    Solution sol;

    vector<int> asteroids1{5,10,-5};
    vector<int> expec1{5,10};
    vector<int> ans1 = sol.asteroidCollision(asteroids1);
    assert(ans1 == expec1);

    vector<int> asteroids2{8,-8};
    vector<int> expec2{};
    vector<int> ans2 = sol.asteroidCollision(asteroids2);
    assert(ans2 == expec2);

    vector<int> asteroids3{10,2,-5};
    vector<int> expec3{10};
    vector<int> ans3 = sol.asteroidCollision(asteroids3);
    assert(ans3 == expec3);

    vector<int> asteroids4{-2,-1,1,2};
    vector<int> expec4{-2,-1,1,2};
    vector<int> ans4 = sol.asteroidCollision(asteroids4);
    assert(ans4 == expec4);

    vector<int> asteroids5{5,10,-5,9,-11};
    vector<int> expec5{-11};
    vector<int> ans5 = sol.asteroidCollision(asteroids5);
    assert(ans5 == expec5);

    cout << "Passed!" << endl;
    return 0;
}