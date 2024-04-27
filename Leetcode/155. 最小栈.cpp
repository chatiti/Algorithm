#include <bits/stdc++.h>

using namespace std;

//维护一个与栈顶同步的最小数栈，最小数栈的栈顶值就是此时对应栈的最小值

class MinStack {
private:
    stack<int> ss;
    stack<int> minss;

public:
    MinStack() {
        minss.push(INT_MAX);

    }

    void push(int val) {
        ss.push(val);
        minss.push(min(val, minss.top()));

    }

    void pop() {
        ss.pop();
        minss.pop();
    }

    int top() {
        return ss.top();
    }

    int getMin() {
        return minss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */