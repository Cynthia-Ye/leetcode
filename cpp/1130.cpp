#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sum = 0;
        stack<int> monoStack;
        monoStack.push(INT_MAX);
        for (int i = 0; i < arr.size(); i++) {
            while ((!monoStack.empty()) && (arr[i] > monoStack.top())) {
                int topval = monoStack.top();
                monoStack.pop();
                sum += topval * min(monoStack.top(), arr[i]);
            }
            monoStack.push(arr[i]);
        }
        while (monoStack.size() > 2) {
            int topval = monoStack.top();
            monoStack.pop();
            sum += topval * monoStack.top();
        }
        return sum;
    }
};

int main()
{
    int val = 0;
    vector<int> arr;
    cin >> val;
    while (val > 0) {
        arr.push_back(val);
        cin >> val;
    }
    Solution sol;
    cout << sol.mctFromLeafValues(arr);
    return 0;
}