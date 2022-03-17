#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* 两个单调栈，可再优化成1个单调栈 */
class Solution {
private:
    vector<int> GetRightEnd(vector<int>& heights)
    {
        vector<int> rightEnd(heights.size(), heights.size());
        stack<int> monoStack;
        monoStack.push(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!monoStack.empty() && heights[i] < heights[monoStack.top()]) {
                rightEnd[monoStack.top()] = i;
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return rightEnd;
    }

    vector<int> GetLeftEnd(vector<int>& heights)
    {
        vector<int> leftEnd(heights.size(), -1);
        stack<int> monoStack;
        monoStack.push(heights.size() - 1);
        for (int i = heights.size() - 2; i >= 0; i--) {
            while (!monoStack.empty() && heights[i] < heights[monoStack.top()]) {
                leftEnd[monoStack.top()] = i;
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return leftEnd;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        vector<int> rightEnd = GetRightEnd(heights);
        vector<int> leftEnd = GetLeftEnd(heights);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, (rightEnd[i] - leftEnd[i] - 1) * heights[i]);
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> heights;
    int val = -1;
    cin >> val;
    while (val >= 0) {
        heights.push_back(val);
        cin >> val;
    }
    cout << sol.largestRectangleArea(heights);
    return 0;
}