#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        
        ans[0].reserve(nums1.size());
        ans[1].reserve(nums2.size());
        
        for (auto n : s1) {
            if (!s2.contains(n))
                ans[0].push_back(n);
        }
        for (auto n : s2) {
            if (!s1.contains(n))
                ans[1].push_back(n);
        }
        return ans;
    }
};

// 結果表示用のヘルパー関数
void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << (j == res[i].size() - 1 ? "" : ",");
        }
        cout << "]" << (i == res.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> n1_1 = {1, 2, 3};
    vector<int> n1_2 = {2, 4, 6};
    cout << "Example 1 Output: ";
    printResult(sol.findDifference(n1_1, n1_2));

    // Example 2
    vector<int> n2_1 = {1, 2, 3, 3};
    vector<int> n2_2 = {1, 1, 2, 2};
    cout << "Example 2 Output: ";
    printResult(sol.findDifference(n2_1, n2_2));

    return 0;
}