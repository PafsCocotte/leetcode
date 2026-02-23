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
step1
easyって左上に書いてあるのが信じられないくらい困っている。ぱっと思いついたのはAVL,赤黒木で出現する回転の概念だが実装が重くできる自信がない。
左右の深さを調べて2以上の差があったら回転する を子供から親へ続けていく。
書ける自信ないので答えをもうAIに聞いてしまう。
*/
class Solution
{
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        // AVL木のように左右の深さを調べて2以上の差があったら回転する を子供から親へ続けていく。
        // LR回転だなんだあった気がするけど覚えていない
    }
};
// @lc code=end
