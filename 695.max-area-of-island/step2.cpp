/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * step2
 * dr, dcの書き方を思い出す。int[]でC的に受けるものが多そう？だが、for文のmagic numberが気になったのでvectorを採用。
 * 境界条件別に今回は気にする必要ないけど、n == 0のときも取っといていいなって見返して思ったので追加。
 * 関数の引数がintになっていて暗黙の型変換が起きていることに気づいた。
 * 全て正しくsize_tで引き回すのが難しいのと、あまりここの型変換は問われないとのことなので、あきらめてsize_tをintで受けてしまおうという気持ち。
 *
 */

// @lc code=start
#include <stack>
#include <stdexcept>
#include <tuple>
#include <vector>

using namespace std; // 使う

class Solution
{
public:
    void areaSizeOfIsland(int r, int c, vector<vector<int>> &grid, int &areaSize)
    {
        static const vector<int> dr = {0, 0, 1, -1};
        static const vector<int> dc = {1, -1, 0, 0};
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return;
        if (grid[r][c] == 0)
            return;
        grid[r][c] = 0;
        areaSize++;
        for (int i = 0; i < dr.size(); i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            areaSizeOfIsland(nr, nc, grid, areaSize);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            if ((int)grid[i].size() != n)
                throw logic_error("");
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    int area = 0;
                    areaSizeOfIsland(i, j, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end
