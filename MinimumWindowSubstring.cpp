#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(const string& s, const string& t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> mp;
        for (auto a : t) {
            mp[a]++;
        }

        int satisfied = 0;
        unordered_map<char, int> tmp;
        int l = 0;
        int startIdx = -1;
        int minLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            char addChar = s[r];
            tmp[addChar]++;

            if (mp.count(addChar) && tmp[addChar] == mp[addChar]) {
                satisfied++;
            }

            while (satisfied == mp.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                char removeChar = s[l];
                if (mp.count(removeChar) && tmp[removeChar] == mp[removeChar]) {
                    satisfied--;
                }
                tmp[removeChar]--;
                l++;
            }
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};

int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("a", "a") << endl;
    cout << sol.minWindow("a", "aa") << endl;
    return 0;
}
