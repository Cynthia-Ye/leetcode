#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int num = 0;
        int flag = 0;
        for (string::iterator it = s.begin(); it < s.end(); it++) {
            if (it[0] == 'R') {
                flag++;
            } else {
                flag--;
            }
            if (flag == 0) {
                num++;
            }
        }
        return num;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.balancedStringSplit(s);
    return 0;
}