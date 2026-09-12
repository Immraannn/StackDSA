#include<iostream>     
#include<stack>        
using namespace std;   
class Stack {
    public:
        int *arr;      
        int top;       
        int size;      
    Stack(int size) {
        this->size = size;    
        arr = new int[size];   
        top = -1;              
    }
    void push(int element) {
        if (size - top > 1) {  
            top++;              
            arr[top] = element;
        }
        else {
            cout << "Stack OverFlow" << endl; 
        }
    }

    void pop() {
        if (top >= 0) {   
            top--;        
        }
        else {
            cout << "Stack UnderFlow" << endl; 
        }
    }
    int peek() {
        if (top >= 0) {         
            return arr[top];    
        }
        else {
            cout << "Stack is Empty" << endl;
            return -1;         
        }
    }
    bool isEmpty() {
        if (top == -1) { 
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);  // This will cause Stack Overflow
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
class Node {
public:
    int data;      
    Node* next;     
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Stack {
    Node* top;      

public:
    Stack() {
        top = NULL;
    }
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

   
    int peek() {
        if(top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    
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
