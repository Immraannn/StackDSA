bool isValidParenthesis(string expression)
{
    // Stack to store opening brackets
    stack<char> s;

    // Traverse each character of the string
    for(int i = 0; i < expression.length(); i++) {

        char ch = expression[i];

        // If current character is an opening bracket,
        // push it onto the stack
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else {
            // Current character is a closing bracket

            // Check if stack is not empty
            if(!s.empty()) {

                // Get the top element of the stack
                char top = s.top();

                // Check for matching opening bracket
                if( (ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[') ) {

                    // Matching pair found, pop opening bracket
                    s.pop();
                }
                else {
                    // Closing bracket does not match stack top
                    return false;
                }
            }
            else {
                // Closing bracket found but stack is empty
                // No opening bracket available
                return false;
            }
        }
    }

    // After processing all characters,
    // stack should be empty for valid expression
    if(s.empty())
        return true;
    else
        return false;
}
