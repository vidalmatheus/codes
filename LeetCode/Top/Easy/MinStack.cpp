#include <bits/stdc++.h>

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MinStack {
private:
    list<int> s;
    vector<int> minElement;
public:
    /** initialize your data structure here. */
    MinStack() {
        minElement.push_back(INT_MAX);
    }
    
    void push(int x) {
        s.push_front(x);
        minElement.push_back(min(x,minElement.back()));
    }
    
    void pop() {
        if (!s.empty()){
            minElement.pop_back();
            s.pop_front();   
        }
    }
    
    int top() {
        return s.front();
    }
    
    int getMin() {
        return minElement.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack minStack;
    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(0);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.getMin() << endl;

    return 0;
}
