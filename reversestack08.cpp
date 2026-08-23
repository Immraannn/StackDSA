#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);   
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(topElement);
}

void reverseStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int topElement = s.top();
    s.pop();
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
    reverseStack(s);
    cout << "Reversed Stack (Top to Bottom):" << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}


Call Stack Visualization
Going Down
reverseStack()
│
├── Pop 50
│
├── reverseStack()
│      │
│      ├── Pop 40
│      │
│      ├── reverseStack()
│      │      │
│      │      ├── Pop 30
│      │      │
│      │      ├── reverseStack()
│      │      │      │
│      │      │      ├── Pop 20
│      │      │      │
│      │      │      ├── reverseStack()
│      │      │      │      │
│      │      │      │      ├── Pop 10
│      │      │      │      │
│      │      │      │      └── Stack Empty
Returning (Backtracking)
Insert 10 at Bottom
        ↓
Insert 20 at Bottom
        ↓
Insert 30 at Bottom
        ↓
Insert 40 at Bottom
        ↓
Insert 50 at Bottom
