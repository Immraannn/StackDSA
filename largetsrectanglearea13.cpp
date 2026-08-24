#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        // Stack stores INDEXES of bars
        // The heights of these indexes are kept in increasing order
        stack<int> st;

        // Stores the maximum rectangle area found so far
        int maxArea = 0;

        // We go one extra position beyond the array
        // At the extra position, we pretend height = 0
        //
        // Why?
        // To force all remaining bars in the stack to be popped
        // and calculate their areas.
        for (int i = 0; i <= heights.size(); i++) {

            // Current height
            int currHeight;

            // If i reaches the end of the array,
            // pretend there is a bar of height 0.
            if (i == heights.size())
                currHeight = 0;
            else
                currHeight = heights[i];


            // If current bar is smaller than the bar at stack top,
            // the taller bar can no longer extend to the right.
            //
            // Therefore, calculate the rectangle area
            // of the taller bar.
            while (!st.empty() &&
                   currHeight < heights[st.top()]) {

                // Height of the rectangle
                // We take the height of the bar being removed.
                int h = heights[st.top()];

                // Remove that bar from the stack
                st.pop();

                int width;

                // If stack becomes empty,
                // there is no smaller bar on the left.
                //
                // Therefore, the rectangle can extend
                // from index 0 to index i-1.
                if (st.empty()) {

                    width = i;
                }

                // Otherwise, st.top() is the index of the
                // first smaller bar on the LEFT.
                //
                // Current i is the first smaller bar on the RIGHT.
                //
                // Therefore:
                //
                // LEFT boundary  = st.top()
                // RIGHT boundary = i
                //
                // Actual width = i - st.top() - 1
                else {

                    width = i - st.top() - 1;
                }

                // Rectangle area = height × width
                int area = h * width;

                // Update maximum area
                maxArea = max(maxArea, area);
            }

            // Put current index into the stack.
            //
            // The stack maintains indexes of bars
            // whose heights are increasing.
            st.push(i);
        }

        return maxArea;
    }
};
