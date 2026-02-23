/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
AIに書かせたら以下の回答。step1と本質的に同じコードだが読みやすい。三項演算子を多用している割に読みやすい。
t1がnullptrならt2を直接渡してしまえばメモリ節約できるともいわれたが、deleteが大変すぎるので採用しない。
他の方を見たらbfsや親から子に伝搬する形で書く人が多いか
https://discord.com/channels/1084280443945353267/1295357747545505833/1329746604114055191
はtreeがn個になったときに綺麗だが、cppらしい書き方はわからない。lambdaとかか？
*/

#include <string>

using namespace std;

struct TreeNode;

class Solution
{
   public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2)
        {
            return nullptr;
        }

        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        TreeNode* merged = new TreeNode(val);

        merged->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        merged->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

        return merged;
    }
};
// @lc code=end
