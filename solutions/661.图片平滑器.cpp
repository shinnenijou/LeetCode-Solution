/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution
{
private:
    int _clamp(int target, int min, int max)
    {
        target = target > max ? max : target;
        target = target < min ? min : target;
        return target;
    }

    int _average_gray_scale(vector<vector<int>> &img, int a, int b, int c, int d)
    {
        int sum = 0;
        for (int i = a; i != b + 1; i++)
        {
            for (int j = c; j != d + 1; j++)
            {
                sum += img[i][j];
            }
        }
        return sum / ((b - a + 1) * (d - c + 1));
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size(), m = img.front().size();
        vector<vector<int>> smooth_img(n, vector<int>(m));
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                smooth_img[i][j] = _average_gray_scale(
                    img, i - 1, i + 1, j - 1, j + 1
                );
            }
        }

        for (int i = 0; i != n; i++)
        {
            for (int j = 0; j != m; j++)
            {
                if(i > 0 && i < n - 1 && j > 0 && j < m - 1){
                    continue;
                }

                smooth_img[i][j] = _average_gray_scale(
                    img, 
                    _clamp(i - 1, 0, n - 1), 
                    _clamp(i + 1, 0, n - 1), 
                    _clamp(j - 1, 0, m - 1), 
                    _clamp(j + 1, 0, m - 1)
                );
            }
        }

        return smooth_img;
    }
};
// @lc code=end
