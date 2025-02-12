#include "catch_amalgamated.hpp"
#include <vector>
using namespace std;

class JumpGameDP
{
public:
    bool canJump(const vector<int>& nums)
    {
        int leftMostReachable = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (i + nums[i] >= leftMostReachable)
            {
                leftMostReachable = i;
            }
        }

        return leftMostReachable == 0;
    }
};

class JumpGameGraph
{
    static constexpr char VISITED = 1;
    static constexpr char NOT_VISITED = 0;

public:
    bool canJump(const vector<int>& nums)
    {
        if (nums.empty()) return true;
        vector<char> visited(nums.size(), NOT_VISITED);
        visited.front() = VISITED;
        dfs(nums, visited, 0);
        return visited.back() == VISITED;
    }

private:
    void dfs(const vector<int>& nums, vector<char>& visited, int v)
    {
        if (v >= nums.size()) return;
        if (visited.back() == VISITED) return;

        for (int w = v + 1; w <= v + nums[v] && w < nums.size(); ++w)
        {
            if (visited[w] == VISITED) continue;
            visited[w] = VISITED;
            dfs(nums, visited, w);
        }
    }
};

TEST_CASE("JumpGameDP", "[JumpGame]")
{
    REQUIRE(JumpGameDP().canJump({2,3,1,1,4}) == true);
    REQUIRE(JumpGameDP().canJump({3,2,1,0,4}) == false);
    REQUIRE(JumpGameDP().canJump({1, 0, 8, 0}) == false);
}

TEST_CASE("JumpGameGraph", "[JumpGame]")
{
    REQUIRE(JumpGameGraph().canJump({2,3,1,1,4}) == true);
    REQUIRE(JumpGameGraph().canJump({3,2,1,0,4}) == false);
    REQUIRE(JumpGameGraph().canJump({1, 0, 8, 0}) == false);
}
