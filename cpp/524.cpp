#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool MyCmp(const string& a, const string& b)
{
    int lena = a.length();
    int lenb = b.length();
    if (lena != lenb)
    {
        return (lena > lenb) ? true : false;
    }
    return b > a;
}
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int lens = s.length();
        sort(dictionary.begin(), dictionary.end(), MyCmp);
        for (vector<string>::iterator it = dictionary.begin(); it < dictionary.end(); it++)
        {
            cout << *it << endl;
            int len = (*it).length();
            int i = 0;
            int j = 0;
            while ((i < lens) && (j < len))
            {
                if (s[i] == (*it)[j]) {
                    i++;
                    j++;
                    continue;
                }
                i++;
            }
            if (j == len) {
                return (*it);
            }
        }
        return "";
    }
};

int main()
{
    Solution sol = Solution();
    string s;
    vector<string> dictionary = {"ale","apple","monkey","plea", "bpple"};
    cin >> s;
    cout << sol.findLongestWord(s, dictionary) << endl;
    return 0;
}