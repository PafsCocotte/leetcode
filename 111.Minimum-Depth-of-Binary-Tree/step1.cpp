/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
bfsでleafを見つけて見つけたらその深さを返せばいい。
exampleを見るにrootしかなければそれは深さが1のようなのでrootがnullなら0。
queueの命名が全くできずqとした。
*/
#include <queue>
#include <string>

using namespace std;

// struct TreeNode;

class Solution
{
   public:
    int minDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while (!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();
            if (node->left)
            {
                q.emplace(node->left, depth + 1);
            }
            if (node->right)
            {
                q.emplace(node->right, depth + 1);
            }
            if (!node->left && !node->right)
            {
                return depth;
            }
        }
        return -1;
    }
};
// @lc code=end
