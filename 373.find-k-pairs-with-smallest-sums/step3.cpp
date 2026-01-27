/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * 昨日一度解いた問題です
 * non decreasing orderとわざわざあるのでsortのO(n log n)より小さい計算量で解けるであろう
 * nums1のi番目の要素とnums2[0]と足したものを小さい順のpriority_queueに入れる。i<kでいい(最大k個だから)
 * nums1[i]と、nums2[j]を足したものがtopにいるとき、これをpopしてresultに加え、nums1[i]とnums2[j+1]を入れれば、k回のpopで小さい順に全て取り出せる
 * 長さkの2次元配列があって、一番上の行から各列ちょっとずつ下に降りていくイメージ？
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;
class Solution
{
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        for (size_t i = 0; i < nums1.size() && i < (size_t)k; i++)
        {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }
        vector<vector<int>> result;
        result.reserve(k);
        while (minHeap.size() && result.size() < k)
        {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size())
            {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return result;
    }
};
// @lc code=end
