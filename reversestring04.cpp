#include <iostream>
#include <stack>
using namespace std;

// Function to reverse the string using a stack
void reverseString(string &str) {

    stack<char> st;

    // Push each character of the string into the stack
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }

    // Pop characters from the stack and overwrite the string
    for(int i = 0; i < str.length(); i++) {
        str[i] = st.top();
        st.pop();
    }
}

int main() {

    string str;

    cout << "Enter a string: ";
    cin >> str;

    reverseString(str);

    cout << "Reversed String: " << str << endl;

    return 0;
}
//output
// Enter a string: HELLO
// Reversed String: OLLEH
