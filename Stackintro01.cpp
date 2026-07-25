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

// Stack implementation using Linkedlist

#include <iostream>
using namespace std;

// Node of Linked List
class Node {
public:
    int data;       // Stores stack element
    Node* next;     // Points to next node

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Stack using Linked List
class Stack {

    Node* top;       // Points to top of stack

public:

    // Constructor
    Stack() {
        top = NULL;
    }

    // Push an element onto the stack
    void push(int x) {

        // Create new node
        Node* newNode = new Node(x);

        // New node points to current top
        newNode->next = top;

        // Move top to new node
        top = newNode;
    }

    // Remove top element
    void pop() {

        // Stack is empty
        if(top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        // Store current top
        Node* temp = top;

        // Move top to next node
        top = top->next;

        // Delete old top node
        delete temp;
    }

    // Return top element
    int peek() {

        if(top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return top->data;
    }

    // Check whether stack is empty
    bool isEmpty() {

        return top == NULL;
    }

    // Print stack
    void display() {

        if(top == NULL) {
            cout << "Stack is Empty\n";
            return;
        }

        Node* temp = top;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack: ";
    st.display();

    cout << "Top = " << st.peek() << endl;

    st.pop();

    cout << "After Pop: ";
    st.display();

    cout << "Top = " << st.peek() << endl;

    return 0;
}

Stack (size = 5)

Initially
top = -1

Index :   0     1     2     3     4
        +-----+-----+-----+-----+-----+
Array : |     |     |     |     |     |
        +-----+-----+-----+-----+-----+


push(10)
---------
top = ++top = 0

        +-----+-----+-----+-----+-----+
Array : | 10  |     |     |     |     |
        +-----+-----+-----+-----+-----+
          ↑
         top


push(20)
---------
top = ++top = 1

        +-----+-----+-----+-----+-----+
Array : | 10  | 20  |     |     |     |
        +-----+-----+-----+-----+-----+
                ↑
               top


push(30)
---------
top = ++top = 2

        +-----+-----+-----+-----+-----+
Array : | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
                      ↑
                     top


peek()
------
Returns 30

        +-----+-----+-----+-----+-----+
Array : | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
                      ↑
                     top


pop()
-----
top--

        +-----+-----+-----+-----+-----+
Array : | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
                ↑
               top

(Note: 30 still exists in memory but is ignored.)


pop()
-----
top--

        +-----+-----+-----+-----+-----+
Array : | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
          ↑
         top


pop()
-----
top--

top = -1

        +-----+-----+-----+-----+-----+
Array : | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+

Stack is Empty


Overflow
--------
top == size-1

push(60)
❌ Stack Overflow


Underflow
---------
top == -1

pop()
❌ Stack Underflow
