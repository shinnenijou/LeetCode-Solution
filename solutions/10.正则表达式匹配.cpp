#include "catch_amalgamated.hpp"

#include <vector>

using namespace std;

class RegularExpressionMatching
{
    using StateContainer = vector<int>;

public:
    bool isMatch(const string& text, const string& pattern)
    {
        if (pattern.empty()) return true;

        StateContainer states;

        // initial state
        states.push_back(0);
        epsilonTransmit(pattern, states);

        for (const char ch : text)
        {
            matchTransmit(ch, pattern, states);
            epsilonTransmit(pattern, states);
        }

        return find(states.begin(), states.end(), pattern.size()) != states.end();
    }

private:
    static void epsilonTransmit(const string& pattern, StateContainer& states)
    {
        using std::swap;
        StateContainer queue;
        swap(queue, states);
        vector<bool> visited(pattern.size() + 1, false);

        while (!queue.empty())
        {
            const int state = queue.back();
            queue.pop_back();

            if (visited[state]) continue;

            // current state
            states.push_back(state);
            visited[state] = true;

            if (state < pattern.size() && pattern[state] == '*')
            {
                if (!visited[state - 1]) queue.push_back(state - 1);
                if (!visited[state + 1]) queue.push_back(state + 1);
            }
            else if (state + 1 < pattern.size() && pattern[state + 1] == '*')
            {
                if (!visited[state + 1]) queue.push_back(state + 1);
            }
        }
    }

    static void matchTransmit(const char text, const string& pattern, StateContainer& states)
    {
        using std::swap;
        StateContainer queue;
        swap(queue, states);
        vector<bool> visited(pattern.size() + 1, false);

        // match text char
        while (!queue.empty())
        {
            const int state = queue.back();
            queue.pop_back();

            if (visited[state]) continue;
            visited[state] = true;

            if (state < pattern.size() && (text == pattern[state] || pattern[state] == '.'))
            {
                states.push_back(state + 1);
            }
        }
    }
};

TEST_CASE("RegularExpressionMatching", "[RegularExpressionMatching]")
{
    REQUIRE(RegularExpressionMatching().isMatch("aaa", "aaaa") == false);
    REQUIRE(RegularExpressionMatching().isMatch("aa", "a") == false);
    REQUIRE(RegularExpressionMatching().isMatch("aa", "a*") == true);
    REQUIRE(RegularExpressionMatching().isMatch("ab", ".*") == true);
    REQUIRE(RegularExpressionMatching().isMatch("aaaaaaaab", "a*b") == true);
}
