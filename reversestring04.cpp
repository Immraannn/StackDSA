#include<iostream>      // For input-output operations (cout)
#include<stack>         // For using stack data structure
using namespace std;

int main () {

    // Input string which we want to reverse
    string str = "babbar";

    // Create a stack of characters
    // Stack follows LIFO (Last In First Out)
    stack<char> s;

    // Step 1: Push each character of string into the stack
    // Loop runs from index 0 to length-1
    for (int i = 0; i < str.length(); i++) {

        // Take character at index i
        char ch = str[i];

        // Push character into stack
        // First character goes at bottom, last at top
        s.push(ch);
    }

    // This string will store the reversed result
    string ans = "";

    // Step 2: Pop characters from stack until it becomes empty
    while (!s.empty()) {

        // Get the top element of stack
        char ch = s.top();

        // Add this character to answer string
        // This gives reverse order automatically
        ans.push_back(ch);

        // Remove the top element from stack
        s.pop();
    }

    // Print the reversed string
    cout << "answer is: " << ans << endl;

    return 0;   // Program ends successfully
}
