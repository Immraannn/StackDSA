#include <iostream>
using namespace std;


class TwoStack {
private:
    Node* top1;   // Top pointer for Stack 1
    Node* top2;   // Top pointer for Stack 2

public:
    // Constructor
    TwoStack() {
        top1 = NULL;   // Stack 1 initially empty
        top2 = NULL;   // Stack 2 initially empty
    }

    // Push into Stack 1
    void push1(int x) {
        Node* newNode = new Node(x); // create new node
        newNode->next = top1;        // link to previous top
        top1 = newNode;              // update top1
    }

    // Push into Stack 2
    void push2(int x) {
        Node* newNode = new Node(x);
        newNode->next = top2;
        top2 = newNode;
    }

    // Pop from Stack 1
    int pop1() {
        if (top1 == NULL) {
            return -1;               // underflow
        }

        Node* temp = top1;
        int val = temp->data;
        top1 = top1->next;           // move top
        delete temp;                 // free memory
        return val;
    }

    // Pop from Stack 2
    int pop2() {
        if (top2 == NULL) {
            return -1;               // underflow
        }

        Node* temp = top2;
        int val = temp->data;
        top2 = top2->next;
        delete temp;
        return val;
    }
};

/*
    MAIN FUNCTION
    Demonstrates PUSH and POP operations
*/
int main() {
    TwoStack st;

    // PUSH operations
    st.push1(10);
    st.push1(20);
    st.push1(30);

    st.push2(100);
    st.push2(200);
    st.push2(300);

    // POP operations
    cout << "Pop from Stack 1: " << st.pop1() << endl; // 30
    cout << "Pop from Stack 2: " << st.pop2() << endl; // 300

    cout << "Pop from Stack 1: " << st.pop1() << endl; // 20
    cout << "Pop from Stack 2: " << st.pop2() << endl; // 200

    return 0;
}
