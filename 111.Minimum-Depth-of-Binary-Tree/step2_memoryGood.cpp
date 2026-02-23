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
- queueに深さ情報を持たせるのではなく、queueのサイズを階層ごとに保持して階層単位で処理するとintがないぶんメモリ効率がいいとAIに言われた。
  書いてみた。二重ループ分、読み手への負荷が上がる気がする。
*/
#include <queue>
#include <string>

using namespace std;

class Solution
{
   public:
    int minDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode*> frontier;
        frontier.push(root);
        int depth = 1;
        while (!frontier.empty())
        {
            int levelSize = frontier.size();
            for (int i = 0; i < levelSize; i++)
            {
                auto node = frontier.front();
                frontier.pop();
                if (!node->left && !node->right)
                {
                    return depth;
                }
                if (node->left)
                {
                    frontier.push(node->left);
                }
                if (node->right)
                {
                    frontier.push(node->right);
                }
            }
            depth++;
        }
        return -1;
    }
};
// @lc code=end
