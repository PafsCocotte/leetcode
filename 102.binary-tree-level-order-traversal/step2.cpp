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
step2
AIには完璧と言われた。arai60を上からやっていて似たものを見ていた成果か
コメントを読んだら、エッジケースは最初に処理してから変数定義した方がいいという声。書いててちょっとそれは思ったので、
エッジケースを先に処理するように変更する。
dfsやbfsの要素にstructでTreeNode*, level を与えているのも見たが、今回の問題であれば、levelSize分だけまわす二重ループの書き方のほうが私的には好み。
nullptrをqueueに入れないようにするか、入れて、queueのfrontがnullptrのときにearly returnするかという議論があったが、
今回の書き方では、levelSizeがnull node込みのサイズになるのは相当直感に反するので、nullを入れるという発想が全くなかった。
そこにも個性が出せて、私がこちらを選択したのはlevelSizeが云々だからですというのを説明できるようにはなりたい。
*/
#include <queue>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> result;
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
