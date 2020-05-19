#include<bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class FirstStockSpanner {
private:
    vector<int> nums;
public:
    FirstStockSpanner() {
    }
    
    int next(int price) { // O(n)
        nums.push_back(price);
        int counter = 0;
        for (int i=nums.size()-1;i>=0;i--)
            if (nums[i]<=price)
                counter++;
            else break;
        
        return counter;
    }
};

class StockSpanner {
private:
    stack<pair<int,int>> st; // descreasing stack
public:
    StockSpanner() {
    }
    
    int next(int price) { // O(n)
        int span = 1;
        while (!st.empty() && st.top().first<=price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    StockSpanner* obj = new StockSpanner();
    cout << obj->next(100) << ", ";
    cout << obj->next(80) << ", ";
    cout << obj->next(60) << ", ";
    cout << obj->next(70) << ", ";
    cout << obj->next(60) << ", ";
    cout << obj->next(75) << ", ";
    cout << obj->next(85);

    return 0;
}
