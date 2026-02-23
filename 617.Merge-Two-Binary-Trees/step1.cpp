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
step1
root1あるいはroot2のどっちかにノードがあるならノードを作成して値を入れる というのがやること。
今回作る関数はheadを返すだけなのでdeleteは関数ユーザーの責任。
nullptr参照に気を付けるべき。とくにroot1とroot2の深さが2以上違う場合。
leetcodeの引数名をleftRoot, rightRootにする。
シグネチャが子から親へ返していく形のdfsなのでそれで書く。
全ノード探索すればいいので親から子へ渡すdfsでもbfsでも書ける。
bugなしではかけたが、leftLeftなどちょっと複雑になってしまった。
*/

#include <string>

using namespace std;

struct TreeNode;

class Solution
{
   public:
    TreeNode* mergeTrees(TreeNode* leftRoot, TreeNode* rightRoot)
    {
        if (!leftRoot && !rightRoot)
        {
            return nullptr;
        }
        int val = 0;
        TreeNode* leftLeft = nullptr;
        TreeNode* leftRight = nullptr;
        TreeNode* rightLeft = nullptr;
        TreeNode* rightRight = nullptr;
        if (leftRoot)
        {
            val += leftRoot->val;
            leftLeft = leftRoot->left;
            leftRight = leftRoot->right;
        }
        if (rightRoot)
        {
            val += rightRoot->val;
            rightLeft = rightRoot->left;
            rightRight = rightRoot->right;
        }
        TreeNode* merged = new TreeNode(val);
        merged->left = mergeTrees(leftLeft, rightLeft);
        merged->right = mergeTrees(leftRight, rightRight);
        return merged;
    }
};
// @lc code=end
