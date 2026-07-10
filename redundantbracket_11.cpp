// Intuition
// Whenever we encounter a closing bracket ):
// Look inside the corresponding opening bracket.
// If there is at least one operator (+, -, *, /), then the brackets are useful.
// If there is no operator, the brackets are redundant.
// We use a stack to examine the contents between matching parentheses.

  
#include <iostream>
#include <stack>
using namespace std;

// Returns true if redundant brackets exist
bool findRedundantBrackets(string str) {

    stack<char> s;

    // Traverse the expression
    for(int i = 0; i < str.length(); i++) {

        char ch = str[i];

        // Push every character except ')'
        if(ch == '(' || ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z')) {

            s.push(ch);
        }

        // Closing bracket encountered
        else if(ch == ')') {

            bool isOperatorPresent = false;

            // Check everything inside the brackets
            while(!s.empty() && s.top() != '(') {

                char top = s.top();

                // If an operator exists, brackets are useful
                if(top == '+' || top == '-' ||
                   top == '*' || top == '/') {

                    isOperatorPresent = true;
                }

                s.pop();
            }

            // Remove the opening bracket '('
            if(!s.empty())
                s.pop();

            // No operator found ⇒ redundant brackets
            if(!isOperatorPresent)
                return true;
        }
    }

    return false;
}

int main() {

    string str;

    cout << "Enter expression: ";
    cin >> str;

    if(findRedundantBrackets(str))
        cout << "Redundant Brackets Present";
    else
        cout << "No Redundant Brackets";

    return 0;
}
