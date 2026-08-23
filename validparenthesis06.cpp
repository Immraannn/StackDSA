#include <iostream>
#include <stack>
using namespace std;
bool isValid(string str) {
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            if(st.empty())
                return false;
            char top = st.top();

            if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                st.pop();   
            }
            else {
                return false;   // Mismatched bracket
            }
        }
    }
    // If stack is empty, all brackets matched
    return st.empty();
}

int main() {
    string str;
    cout << "Enter expression: ";
    cin >> str;
    if(isValid(str))
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";

    return 0;
}
