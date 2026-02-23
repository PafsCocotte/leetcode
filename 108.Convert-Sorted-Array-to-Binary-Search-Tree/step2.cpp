/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
step2
回答を見た、そもそもシグネチャを勘違いしていたが昇順vectorなので真ん中とって再帰的に作ればいいよねという単純な話だった。
引数がTreeNode*のとき(LeetCode 1382)も新しく作るならば回転いらないからvector作ってO(N)でやるのがいいよとaiに言われた。なるほど。
深さの差が2以上にならないのか戸惑った。厳密に証明するのが難しい。log_2 N の差が1を超えないみたいな説明だろうか？
合計ノード数が0,1,2,3のいずれのときも平衡になるしn+1は平衡になりそうって雰囲気でひとまず納得することにした。
*/
#include <vector>

using namespace std;

class Solution
{
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(const vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = helper(nums, left, mid - 1);
        node->right = helper(nums, mid + 1, right);
        return node;
    }
};
// @lc code=end
