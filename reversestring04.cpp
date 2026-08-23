#include <iostream>
#include <stack>
using namespace std;
void reverseString(string &str) {
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }
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
