#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.length();
        int n = version2.length();
        int i = 0;
        int j = 0;
        while ((i < m) || (j < n))
        {
            int subversion1 = 0;
            int subversion2 = 0;
            while ((i < m) && (version1[i] != '.'))
            {
                subversion1 = subversion1 * 10 + version1[i] - '0';
                i++;
            }
            while ((j < n) && (version2[j] != '.'))
            {
                subversion2 = subversion2 * 10 + version2[j] - '0';
                j++;
            }
            if (subversion1 != subversion2)
            {
                return (subversion1 > subversion2) ? 1 : -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};

int main()
{
    Solution sol = Solution();
    string version1, version2;
    cin >> version1 >> version2;
    cout << sol.compareVersion(version1, version2) << endl;
    cout << "Hello world!" << endl;
    return 0;
}