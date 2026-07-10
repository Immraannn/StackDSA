// Why do we use a stack?
// A stack follows LIFO (Last In, First Out). The most recently encountered opening bracket must be
// the first one to be matched with a closing bracket. This behavior matches the nesting property of
// parentheses exactly, which is why a stack is the ideal data structure for this problem.

// #include <iostream>
#include <stack>
using namespace std;

// Function to check whether parentheses are valid
bool isValid(string str) {

    stack<char> st;

    // Traverse every character of the string
    for(int i = 0; i < str.length(); i++) {

        char ch = str[i];

        // Push every opening bracket
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        // Current character is a closing bracket
        else {

            // No opening bracket available
            if(st.empty())
                return false;

            char top = st.top();

            // Check for matching pair
            if((ch == ')' && top == '(') ||
               (ch == '}' && top == '{') ||
               (ch == ']' && top == '[')) {

                st.pop();   // Remove matched opening bracket
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
