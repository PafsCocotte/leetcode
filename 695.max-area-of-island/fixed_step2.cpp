/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * step2
 *
 */

// @lc code=start
#include <cassert>
#include <stack>
#include <tuple>
#include <vector>

using namespace std; // 使う

class Solution
{
public:
    void calculateAreaSizeAndDestroyIsland(int r, int c, vector<vector<int>> &grid, int &areaSize)
    {
        static const array<int, 4> dr = {0, 0, 1, -1};
        static const array<int, 4> dc = {1, -1, 0, 0};
        if (!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size()))
            return;
        if (grid[r][c] == 0)
            return;
        grid[r][c] = 0;
        areaSize++;
        for (int i = 0; i < dr.size(); i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            calculateAreaSizeAndDestroyIsland(nr, nc, grid, areaSize);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        assert(!grid.empty() && !grid[0].empty());
        int h = grid.size();
        int w = grid[0].size();
        for (auto &row : grid)
        {
            assert(row.size() == w);
        }

        int maxArea = 0;

        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; c++)
            {
                if (grid[r][c])
                {
                    int area = 0;
                    calculateAreaSizeAndDestroyIsland(r, c, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end
