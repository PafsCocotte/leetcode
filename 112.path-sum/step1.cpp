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
step1
dfsで合計値を持っておいて、leafにたどり着いたら合計値がtargetSumと一致しているか確認、一致していたらtrueを返すだけ。
合計を再帰関数の引数なりstackの要素なりで渡せばいいだろう。
シグネチャの形がnode+合計値と同じ見た目しているなあと思って、
targetSumを減らしていって,rootがnullptrのときに0になったらtrueを返せば完璧だときづく
nullptrのときにtargetSumが非0ならreturn falseすればよい。
引数にnullptrを入れてokなのでreturn もきれいに書ける。

結果2つの理由でWA
まずexampleを見逃していて、nullptr 0の期待値はfalseだと気づかずWA
これはエッジケースに気づいていたのに勝手に都合よく考えた。よくない。
もう一件はもっと甘くて、以下のコードはleafではない片方が子供のときにもtargetSumを計算してしまっている。
コーディング中気づけなかったのは仕方ないとして、手動テストをexample1に行えば気づけるものである。
node問題なのに舐めてサボったのが悪い。
*/
class Solution
{
   public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root && targetSum == 0)
        {
            return true;
        }
        else if (!root)
        {
            return false;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end
