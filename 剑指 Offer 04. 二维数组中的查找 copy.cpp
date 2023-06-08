/*
 * 剑指 Offer 04. 二维数组中的查找
 */

// @lc code=start
#include<vector>
using std::vector;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty())
        {
            return false;
        }

        return findNumberIn2DArray(matrix, target, 0, matrix.size(), 0, matrix.front().size());
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target, int i1, int i2, int j1, int j2)
    {
        if (i1 >= i2 || j1 >= j2)
        {
            return false;
        }

        int j = horizon_search(matrix, target, i2 - 1, j1, j2);
        int i = vertical_search(matrix, target, j2 - 1, i1, i2);

        if(j != j2 && matrix[i2 - 1][j] == target)
        {
            return true;
        }

        if(i != i2 && matrix[i][j2 - 1] == target)
        {
            return true;
        }

        return findNumberIn2DArray(matrix, target, i, i2 - 1, j, j2 - 1);
    }

    // 返回第i行 >= target的最小索引
    int horizon_search(vector<vector<int>>& matrix, int target, int i,int start, int end)
    {
        int left = start, right = end;
        while(left < right)
        {
            int mid = left + ((right - left) >> 2);
            if (matrix[i][mid] == target)
            {
                right = mid;
                break;
            }
            else if (matrix[i][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return right;
    }
    // 返回第j列 >= target的最小索引
    int vertical_search(vector<vector<int>>& matrix, int target, int j, int start, int end)
    {
        int left = start, right = end;
        while(left < right)
        {
            int mid = left + ((right - left) >> 2);
            if (matrix[mid][j] == target)
            {
                right = mid;
                break;
            }
            else if (matrix[mid][j] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return right;
    }
};
// @lc code=end
