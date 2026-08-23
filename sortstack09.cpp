#include <iostream>
#include <stack>
using namespace std;
void insertSorted(stack<int> &s, int element) {
    if (s.empty() || element > s.top()) {
        s.push(element);      
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(temp);
}
void sortStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, temp);
}

int main() {
    stack<int> s;
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




