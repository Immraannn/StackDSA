#include <iostream>   
#include <stack>      
#include <vector>     
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;          
    vector<int> ans(n);    
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() &&  arr[i])<=s.top() {
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

//Brut force
vector<int> nextSmaller(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(nums[j] < nums[i]) {
                ans[i] = nums[j];
                break;
            }
        }
    }

    return ans;
}
