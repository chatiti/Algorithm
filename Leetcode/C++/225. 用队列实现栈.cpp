#include "array"
using namespace std;

class MyStack {
public:
    int hh = -1;
    array<int,100> stack ;

    MyStack() {
    }

    void push(int x) {
        stack[++hh] = x;
    }

    int pop() {
        return stack[hh--];
    }

    int top() {
        return stack[hh];
    }

    bool empty() {
        return hh == -1;
    }
};
int main(){
     MyStack* obj = new MyStack();
     obj->push(1);
     int param_2 = obj->pop();
     int param_3 = obj->top();
     bool param_4 = obj->empty();
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */