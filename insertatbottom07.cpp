#include <iostream>          
#include <stack>            
using namespace std;        
void insertAtBottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(topElement);
}

int main() {
    stack<int> s;
    s.push(1);             
    s.push(2);              
    s.push(3);              
    insertAtBottom(s, 0);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}


Call Stack Visualization
Going Down
insertAtBottom(100)
│
├── Pop 50
│
├── Pop 40
│
├── Pop 30
│
├── Pop 20
│
├── Pop 10
│
└── Stack Empty
      │
      └── Push 100
Returning (Backtracking)
Push 10
    ↓
Push 20
    ↓
Push 30
    ↓
Push 40
    ↓
Push 50
