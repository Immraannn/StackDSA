class TwoStack {
    int *arr;      // Pointer to dynamically allocated array (shared by both stacks)
    int top1;      // Top index for Stack 1
    int top2;      // Top index for Stack 2
    int size;      // Total size of the array

public:

    // Constructor: Initialize TwoStack with given size 's'
    TwoStack(int s) {
        this->size = s;     // Store array size
        top1 = -1;          // Stack 1 starts from left, initially empty
        top2 = s;           // Stack 2 starts from right, initially empty
        arr = new int[s];   // Dynamically allocate array of size 's'
    }
    
    // Push an element into Stack 1
    void push1(int num) {
        // Check if at least one empty space is available between two stacks
        if (top2 - top1 > 1) {
            top1++;              // Move top1 to next position
            arr[top1] = num;     // Insert element into Stack 1
        }
        // If no space, push is ignored (stack overflow case)
    }

    // Push an element into Stack 2
    void push2(int num) {
        // Check if at least one empty space is available
        if (top2 - top1 > 1) {
            top2--;              // Move top2 to previous position
            arr[top2] = num;     // Insert element into Stack 2
        }
        // If no space, push is ignored (stack overflow case)
    }

    // Pop an element from Stack 1
    int pop1() {
        // Check if Stack 1 is not empty
        if (top1 >= 0) {
            int ans = arr[top1]; // Store top element of Stack 1
            top1--;              // Remove the element by decrementing top1
            return ans;          // Return popped element
        } else {
            return -1;           // Stack 1 underflow (empty stack)
        }
    }

    // Pop an element from Stack 2
    int pop2() {
        // Check if Stack 2 is not empty
        if (top2 < size) {
            int ans = arr[top2]; // Store top element of Stack 2
            top2++;              // Remove the element by incrementing top2
            return ans;          // Return popped element
        } else {
            return -1;           // Stack 2 underflow (empty stack)
        }
    }
};
