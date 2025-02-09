/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        if(grid.empty() || grid.front().empty()) return 0;


        int perimeter = 0;
        // horizonal
        for(int i = 0; i != grid.size(); i++){
            int prev = 0;
            for(int j = 0; j != grid.front().size(); j ++){
                perimeter += (grid[i][j] + prev) & 1;
                prev = grid[i][j];
            }
            perimeter += prev & 1;
        }

        // vertical
        for(int i = 0; i != grid.front().size(); i++){
            int prev = 0;
            for(int j = 0; j != grid.size(); j ++){
                perimeter += (grid[j][i] + prev) & 1;
                prev = grid[j][i];
            }
            perimeter += prev & 1;
        }
        return perimeter;
    }
};
// @lc code=end

