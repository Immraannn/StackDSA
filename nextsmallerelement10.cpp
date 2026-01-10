#include <iostream>   // For input and output
#include <stack>      // For using stack STL
#include <vector>     // For using vector STL
using namespace std;

/*
 Function to find Next Smaller Element for each element in the array
 arr → input array
 n   → size of array
 returns a vector containing next smaller elements
*/
vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;          // Stack to store elements
    vector<int> ans(n);    // Answer array of size n

    // Traverse the array from right to left
    for(int i = n - 1; i >= 0; i--) {

        // Remove all elements from stack
        // which are greater than or equal to current element
        while(!s.empty() && s.top() >= arr[i]) {
            s.pop();       // Pop elements until smaller element is found
        }

        // If stack becomes empty
        // then no smaller element exists on the right
        if(s.empty()) {
            ans[i] = -1;   // Assign -1
        }
        else {
            ans[i] = s.top(); // Top of stack is next smaller element
        }

        // Push current element into stack
        // for future comparisons
        s.push(arr[i]);
    }

    // Return the result array
    return ans;
}

int main() {

    // Input array
    vector<int> arr = {4, 8, 5, 2, 25};

    // Size of array
    int n = arr.size();

    // Call function to find next smaller elements
    vector<int> res = nextSmallerElement(arr, n);

    // Print the result
    for(int x : res) {
        cout << x << " ";
    }

    return 0;  // Indicate successful execution
}
