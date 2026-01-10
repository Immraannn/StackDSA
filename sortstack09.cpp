#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element in a sorted stack
void insertSorted(stack<int> &s, int element) {

    // Base case:
    // If stack is empty OR element is greater than top
    if (s.empty() || element > s.top()) {
        s.push(element);      // place element at correct position
        return;
    }

    // Remove the top element
    int temp = s.top();
    s.pop();

    // Recursive call to find correct position
    insertSorted(s, element);

    // Put the removed element back
    s.push(temp);
}

// Function to sort the stack
void sortStack(stack<int> &s) {

    // Base case: empty stack
    if (s.empty()) {
        return;
    }

    // Step 1: remove top element
    int temp = s.top();
    s.pop();

    // Step 2: sort remaining stack
    sortStack(s);

    // Step 3: insert removed element in sorted stack
    insertSorted(s, temp);
}

int main() {
    stack<int> s;

    // Pushing elements
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s);

    // Printing sorted stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    // Output: 5 4 2 1 (top to bottom)
}
