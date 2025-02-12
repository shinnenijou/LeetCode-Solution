#include <vector>
#include <array>
#include <catch_amalgamated.hpp>

using namespace std;

class ValidSudoku
{
public:
    bool isValidSudoku(const vector<vector<char>>& board)
    {
        array<char, 9> visited{};

        const int maxRow = board.size();
        const int maxCol = board.front().size();

        // row
        for (int row = 0; row < maxRow; ++row)
        {
            for (int col = 0; col < maxCol; ++col)
            {
                const char c = board[row][col];
                if (c == '.') continue;
                if (visited[c - '1']) return false;
                visited[c - '1'] = 1;
            }

            fill(visited.begin(), visited.end(), 0);
        }

        // col
        for (int col = 0; col < maxCol; ++col)
        {
            for (int row = 0; row < maxRow; ++row)
            {
                const char c = board[row][col];
                if (c == '.') continue;
                if (visited[c - '1']) return false;
                visited[c - '1'] = 1;
            }

            fill(visited.begin(), visited.end(), 0);
        }

        // 3x3 board
        for (int row = 0; row < maxRow; row += 3)
        {
            for (int col = 0; col < maxCol; col += 3)
            {
                for (int i = 0; i < 9; ++i)
                {
                    const char c = board[row + i / 3][col + i % 3];
                    if (c == '.') continue;
                    if (visited[c - '1']) return false;
                    visited[c - '1'] = 1;
                }

                fill(visited.begin(), visited.end(), 0);
            }
        }

        return true;
    }
};

TEST_CASE("ValidSudoku", "[ValidSudoku]")
{
    vector<vector<char>> board;

    board =
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    REQUIRE(ValidSudoku().isValidSudoku(board) == true);

    board =
    {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    REQUIRE(ValidSudoku().isValidSudoku(board) == false);
}
