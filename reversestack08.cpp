#include <iostream>
#include <stack>
using namespace std;

/*
Function to insert an element at the bottom of the stack
*/
void insertAtBottom(stack<int> &s, int element) {

    // Base case: if stack is empty, push element
    if (s.empty()) {
        s.push(element);   // insert element at bottom
        return;
    }

    // Store top element
    int topElement = s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s, element);

    // Push back the stored element
    s.push(topElement);
}

/*
Function to reverse the stack using recursion
*/
void reverseStack(stack<int> &s) {

    // Base case: empty stack
    if (s.empty()) {
        return;
    }

    // Store top element
    int topElement = s.top();
    s.pop();

    // Reverse remaining stack
    reverseStack(s);

    // Insert stored element at bottom
    insertAtBottom(s, topElement);
}

int main() {

    stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Stack before reverse (Top → Bottom):
    // 40
    // 30
    // 20
    // 10

    reverseStack(s);

    // Stack after reverse (Top → Bottom):
    // 10
    // 20
    // 30
    // 40

    cout << "Reversed Stack (Top to Bottom):" << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
