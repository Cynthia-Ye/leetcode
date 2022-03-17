#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    static constexpr int SEG_COUNT = 4;

private:
    vector<string> ret;
    vector<int> segments;

private:
    void AddRet()
    {
        string ip = "";
        for (int i = 0; i < SEG_COUNT; i++) {
            ip += to_string(segments[i]);
            if (i != SEG_COUNT - 1) {
                ip += ".";
            }
        }
        ret.push_back(move(ip));
        return;
    }

    void Dfs(string& s, int segId, int segStart) {
        if (segId == SEG_COUNT) {
            if (segStart == s.size()) {
                AddRet();
            }
            return;
        }

        if (segStart == s.size()) {
            return;
        }

        if (s[segStart] == '0') {
            segments[segId] = 0;
            Dfs(s, segId + 1, segStart + 1);
            return;
        }

        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); segEnd++) {
            addr = addr * 10 + s[segEnd] - '0';
            if (addr > 0xFF) {
                return;
            }
            segments[segId] = addr;
            Dfs(s, segId + 1, segEnd + 1);
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        Dfs(s, 0, 0);
        return ret;
    }
};