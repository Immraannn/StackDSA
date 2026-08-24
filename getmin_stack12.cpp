#include <iostream>
#include <stack>
using namespace std;
class SpecialStack
{
    stack<int> s;          // Main stack to store all elements
    stack<int> minStack;   // Stores the minimum element at each stage

public:
    void push(int x)
    {
        s.push(x);

        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }
    void pop()
    {
        // Stack underflow
        if (s.empty())
            return;

        // If the element being removed is the current minimum,
        // remove it from minStack as well.
        //
        // This ensures that minStack always stores the correct minimum
        // after every pop operation.
        if (s.top() == minStack.top())
        {
            minStack.pop();
        }

        // Remove element from the main stack
        s.pop();
    }

    // Return the top element of the stack
    int top()
    {
        if (s.empty())
            return -1;
        return s.top();
    }

    // Return the minimum element present in the stack
    int getMin()
    {
        // If no elements exist, return -1
        if (minStack.empty())
            return -1;

        // Top of minStack always stores the current minimum
        return minStack.top();
    }
};

int main()
{
    SpecialStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    st.push(2);

    cout << "Minimum : " << st.getMin() << endl;   // 2

    st.pop();                                      // Remove first 2
    cout << "Minimum : " << st.getMin() << endl;   // Still 2

    st.pop();                                      // Remove second 2
    cout << "Minimum : " << st.getMin() << endl;   // 3

    cout << "Top : " << st.top() << endl;          // 7
}
