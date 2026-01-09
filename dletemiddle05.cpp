#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &s, int count, int mid) {
    // Base case: middle element reached
    if (count == mid) {
        s.pop();   // delete middle element
        return;
    }

    // Store top element
    int temp = s.top();
    s.pop();

    // Recursive call
    deleteMiddle(s, count + 1, mid);

    // Push elements back while returning
    s.push(temp);
}

int main() {
    stack<int> s;

    // Pushing elements into stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    /*
    Stack before deletion (top → bottom):
    50
    40
    30   ← middle element
    20
    10
    */

    int size = s.size();   // size = 5
    int mid = size / 2;    // mid = 2

    deleteMiddle(s, 0, mid);

    // Printing stack after deleting middle element
    cout << "Stack after deleting middle element:\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

/*
OUTPUT:
Stack after deleting middle element:
50 40 20 10
*/
