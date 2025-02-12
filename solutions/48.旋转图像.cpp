#include "catch_amalgamated.hpp"
#include <vector>
#include <iostream>
using namespace std;

class RotateImage
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        const int N = matrix.size();
        vector<int> backup{};

        for (int i = 0; i < N >> 1; ++i)
        {
            const int start = i;
            const int end = N - i - 1;

            // backup up
            backup.clear();

            // initial row = i, col = i
            for (int row = start, col = start; col < end; ++col)
            {
                backup.push_back(matrix[row][col]);
            }

            // right: initial row = i
            for (int row = start, col = end; row < end; ++row)
            {
                swap(matrix[row][col], backup[row - start]);
            }

            // down
            for (int row = end, col = end; col > start; --col)
            {
                swap(matrix[row][col], backup[end - col]);
            }

            // left
            for (int row = end, col = start; row > start; --row )
            {
                swap(matrix[row][col], backup[end - row]);
            }

            // up
            for (int row = start, col = start; col < end; ++col)
            {
                swap(matrix[row][col], backup[col - start]);
            }
        }
    }
};

TEST_CASE("RotateImage", "[RotateImage]")
{
    vector<vector<int>> matrix{};

    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    RotateImage().rotate(matrix);
    REQUIRE(matrix == vector<vector<int>>{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});

    matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    RotateImage().rotate(matrix);
    REQUIRE(matrix == vector<vector<int>>{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}});
}
