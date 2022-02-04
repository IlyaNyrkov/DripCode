#include <vector>
#include <climits>

using namespace std;

class MinStack {
public:
    MinStack() : minElem(INT_MIN), topElementIndex(0), minElemIndex(-1) {
    }

    void push(int val) {
        if (data.capacity() == data.size()) {
            data.push_back(val);
        } else {
            data[topElementIndex] = val;
        }

        if (minElem > val) {
            minElemIndex = topElementIndex;
            minElem = val;
        }
        topElementIndex++;
    }

    void pop() {
        if (topElementIndex > 0) {
            topElementIndex--;
        }
    }

    int top() {
        return data[topElementIndex];
    }

    int getMin() {
        return minElem;
    }
private:
    vector<int> data;
    size_t topElementIndex;
    int minElem;
    size_t minElemIndex;
};


int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}

