#include <climits>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        if (x <= min) {
            min = x;
            minstk.push(x);
        }
        stk.push(x);
    }

    void pop() {
        int x = stk.top();
        if (x == min) {
            minstk.pop();
            if (minstk.empty()) {
                min = INT_MAX;
            } else {
                min = minstk.top();
            }
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min;
    }

private:
    stack<int> stk;
    stack<int> minstk;
    int min = INT_MAX;
};
