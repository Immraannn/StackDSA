#include <iostream>          // Header file for input-output operations
#include <stack>             // Header file for stack STL
using namespace std;         // Allows using std names without std::

/*
 Function: insertAtBottom
 Purpose : Inserts element x at the bottom of stack s
*/
void insertAtBottom(stack<int> &s, int x) {

    // Base case: if stack is empty
    if (s.empty()) {

        // Push element x when stack is empty
        // This ensures x goes to the bottom
        s.push(x);

        // Stop recursion
        return;
    }

    // Store the top element of stack temporarily
    int topElement = s.top();

    // Remove the top element
    s.pop();

    // Recursive call to reach bottom of stack
    insertAtBottom(s, x);

    // Push back the stored element
    // This restores the original stack order
    s.push(topElement);
}

int main() {

    // Declare a stack of integers
    stack<int> s;

    // Push elements into stack
    s.push(1);               // Stack: 1
    s.push(2);               // Stack: 2 1
    s.push(3);               // Stack: 3 2 1  (Top → Bottom)

    // Insert 0 at the bottom of the stack
    insertAtBottom(s, 0);
    /*
       Stack after insertion:
       Top
        ↓
       3
       2
       1
       0
       Bottom
    */

    // Print stack elements (top to bottom)
    while (!s.empty()) {

        // Print current top element
        cout << s.top() << " ";

        // Remove printed element
        s.pop();
    }

    // End of program
    return 0;
}

/*
======================
 Program Output:
======================
3 2 1 0
======================

Explanation:
- 0 is inserted at the bottom
- Stack is printed from top to bottom
*/
