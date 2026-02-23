/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
AIにまず聞いた。
第一に葉の定義に沿った書き方をする。
if(!root->left && !root->right && targetSum == 0) return true と書かずに、
if (!root->left && !root->right) return targetSum == 0; とかくのが読みやすさだと思った。
step1のreturn では同じことを2回書いていたが、一時変数 remainingSum などに格納してそれを両方に与えるべきだった。
今回は、targetSum - root->valをあらかじめやっておくことできれいに書けると気づいたのでそちらを採用する。
*/
class Solution
{
   public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        targetSum -= root->val;
        if (!root->left && !root->right)
        {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
// @lc code=end
