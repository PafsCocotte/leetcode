/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * step1
 * dfsで4方向に対し進む。親から子にサイズを伝搬していき、返り値を入れる変数maxAreaを更新していけばいい。(子から親で返り値渡していってもいい)
 * visitedを用意するかわりにgridのvisitedなインデクスを0にしていくことで、重複して数えることをなくせる。
 * 本当はgridはムーブされてくるべきであるが、シグネチャがかわり呼び出し元がmoveしてくれていないと動かないのでそのまま変更する。返り値もuintやsize_tが適切に見える。
 * 製品ならlocalにgridWorkのような変数を用意してこちらを変更すべきという理解。値渡しでもいいが、参照付け忘れと見分けがつかないため。
 * 今回はmemory効率もleetcodeくんに測ってほしいのでgridWorkは作らない。
 * 親から子なので、stackを使うことでも実装できる。メリットはヒープに取れるのでメモリの心配がない。maxAreaやgridを関数に渡し続けるのが癪なので今回はstackで実装する。
 * →方針転換。境界条件をきれいに書きたいのと、ネストが激しいので再帰に変更
 * 次いくとこは{-1,1}とかかけた覚えあるけど綺麗な書き方思い出せないので自力で解く分には不採用
 */

// @lc code=start
#include <stack>
#include <stdexcept>
#include <tuple>
#include <vector>

using namespace std;  // 使う

class Solution
{
public:
    void areaSizeOfIsland(int i, int j, vector<vector<int>>& grid, int& areaSize) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        areaSize++;
        areaSizeOfIsland(i-1, j, grid, areaSize);
        areaSizeOfIsland(i+1, j, grid, areaSize);
        areaSizeOfIsland(i, j-1, grid, areaSize);
        areaSizeOfIsland(i, j+1, grid, areaSize);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.size() == 0)
            return 0;
        size_t m = grid.size();
        size_t n = grid[0].size();

        int maxArea = 0;

        for (size_t i = 0; i < m; i++)
        {
            if (grid[i].size() != n)
                throw logic_error("");
            for (size_t j = 0; j < n; j++)
            {
                int area = 0;
                if (grid[i][j])
                {
                    areaSizeOfIsland(i, j, grid, area);
                }
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
// @lc code=end
