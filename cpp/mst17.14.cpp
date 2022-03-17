#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 堆排序，超时，堆排序只有在k远小于arr.size()时效率才高 */
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> min4;
        if (arr.size() <= 0 || k <= 0) {
            return min4;
        }
        for (int i = 0; i < k; i++) {
            min4.push_back(arr[i]);
        }
        sort(min4.begin(), min4.end());
        for (vector<int>::iterator it = arr.begin() + k; it < arr.end(); it++) {
            int pos = k;
            for (int i = k - 1; i >= 0; i--) {
                if ((*it) > min4[i]) {
                    break;
                }
                pos--;
            }
            if (pos < k) {
                min4.insert(min4.begin() + pos, *it);
                min4.pop_back();
            }
        }
        return min4;
    }
};

/* 通过，传统方法 */
class Solution1 {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> min4;
        for (int i = 0; i < k; i++) {
            min4.push_back(arr[i]);
        }
        return min4;
    }
};

int main()
{
    Solution1 sol;
    vector<int> arr;
    vector<int> ret;
    int val = -1;
    int k;
    cin >> val;
    while (val != -1) {
        arr.push_back(val);
        cin >> val;
    }
    cin >> k;
    ret = sol.smallestK(arr, k);
    for (vector<int>::iterator it = ret.begin(); it < ret.end(); it++) {
        cout << *it;
    }
    return 0;
}