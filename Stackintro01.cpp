#include<iostream>     // For input-output operations (cout, endl)
#include<stack>        // For STL stack (used in commented section)
using namespace std;   // To avoid writing std:: again and again

// User-defined Stack class
class Stack {
    // ---------------- PROPERTIES ----------------
    public:
        int *arr;      // Pointer to dynamically allocated array (stack storage)
        int top;       // Index of the top element in stack
        int size;      // Maximum capacity of the stack

    // ---------------- CONSTRUCTOR ----------------
    Stack(int size) {
        this->size = size;     // Assign stack size
        arr = new int[size];   // Dynamically allocate memory
        top = -1;              // Stack is empty initially
    }

    // ---------------- PUSH OPERATION ----------------
    void push(int element) {
        // Check if there is space in stack
        if (size - top > 1) {   // Equivalent to: top < size - 1
            top++;              // Move top upward
            arr[top] = element;// Insert element at top
        }
        else {
            cout << "Stack OverFlow" << endl; // Stack full
        }
    }

    // ---------------- POP OPERATION ----------------
    void pop() {
        if (top >= 0) {   // Stack is not empty
            top--;        // Remove top element (logical deletion)
        }
        else {
            cout << "Stack UnderFlow" << endl; // Stack already empty
        }
    }

    // ---------------- PEEK OPERATION ----------------
    int peek() {
        if (top >= 0) {         // Stack has at least one element
            return arr[top];    // Return top element
        }
        else {
            cout << "Stack is Empty" << endl;
            return -1;          // Invalid value
        }
    }

    // ---------------- EMPTY CHECK ----------------
    bool isEmpty() {
        if (top == -1) {  // No element present
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    // Create stack of size 5
    Stack st(5);

    // Pushing elements into stack
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);  // This will cause Stack Overflow

    // Print top element
    cout << st.peek() << endl;

    // Remove top element
    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    // Check if stack is empty
    if (st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else {
        cout << "Stack is not Empty mere dost " << endl;
    }

    /*
    ---------------- STL STACK (REFERENCE) ----------------

    stack<int> s;       // Create stack using STL

    s.push(2);          // Push element
    s.push(3);

    s.pop();            // Pop top element

    cout << s.top();    // Access top element

    if(s.empty()) {
        cout << "Stack is empty";
    }

    cout << s.size();   // Size of stack
    */

    return 0;   // End of program
}
