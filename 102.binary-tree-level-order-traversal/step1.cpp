/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
bfsで階層ごとに配列に詰め込むのがいいだろう。
二重ループとなってしまうが、各階層の最初でlevelSizeを確保してその回数分queueからpopする。
エッジケースとしてrootがnullのときには空配列が返ることが期待されている。
上から順に書きたいので他に考慮すべきことを考える。
エッジケース対応→queueつくってqueueにrootいれてwhile(!q.empty())でlevelSize確保してfot文。
と書いてて返り値定義を最初にすべきということに気づく。コメント内で前に戻るのはいいのだろうか
コード書いてからよりはバグが少なさそうなのでよしとする。改善したい。
返り値最初に定義してエッジケース対応→queueつくってqueueにrootいれてwhile(!q.empty())でlevelSize確保してfor文front pop。
実装する。
vector<int> currentLevelNodeValue;の定義が必要なことを忘れていて戻った。
バグはなくかけた。
*/
#include <queue>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode*> frontier;
        frontier.push(root);
        while (!frontier.empty())
        {
            int levelSize = frontier.size();
            vector<int> currentLevelNodeValue;
            for (int i = 0; i < levelSize; i++)
            {
                auto node = frontier.front();
                frontier.pop();
                currentLevelNodeValue.push_back(node->val);
                if (node->left)
                {
                    frontier.push(node->left);
                }
                if (node->right)
                {
                    frontier.push(node->right);
                }
            }
            result.push_back(currentLevelNodeValue);
        }
        return result;
    }
};
// @lc code=end
