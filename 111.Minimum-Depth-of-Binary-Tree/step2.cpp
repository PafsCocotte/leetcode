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
- pairのかわりにstructを使っている人もいた。保守観点ではそちらのほうがいいだろう。
- https://github.com/dxxsxsxkx/leetcode/pull/22/changes#r2711216752
  曰く未探索のものをfrontierと名付けることがあるそう。
  他にはnodeToProcess, toVisit, pendingNodesなどをgeminiに提示された。
  結局どれも汎用的でqueueをqって書くのとあまり読み手の理解度に影響を与えない気がするし、
  14行の関数なのでqと書いても読めるという説もあるが、今回は勉強なのでfrontierを採用してみる。
- queueに深さ情報を持たせるのではなく、queueのサイズを階層ごとに保持して階層単位で処理するとintがないぶんメモリ効率がいいとAIに言われた。
  二重ループ分、読み手への負荷が上がる気がしたのでこのままにする。
*/
#include <queue>
#include <string>

using namespace std;

class Solution
{
   public:
    struct NodeAndDepth
    {
        TreeNode* node;
        int depth;
    };
    int minDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        queue<NodeAndDepth> frontier;
        frontier.emplace(root, 1);
        while (!frontier.empty())
        {
            auto [node, depth] = frontier.front();
            frontier.pop();
            if (node->left)
            {
                frontier.emplace(node->left, depth + 1);
            }
            if (node->right)
            {
                frontier.emplace(node->right, depth + 1);
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
