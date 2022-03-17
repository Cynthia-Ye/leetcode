#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int pairsNum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] > 2 * nums[j]) {
                    pairsNum++;
                }
            }
        }
        return pairsNum;
    }
};

int main()
{
    vector<int> nums;
    int val = -1;
    cin >> val;
    while (val != -1) {
        nums.push_back(val);
        cin >> val;
    }
    Solution sol;
    cout << sol.reversePairs(nums);
    return 0;
}