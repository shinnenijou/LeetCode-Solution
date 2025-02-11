#include "catch_amalgamated.hpp"

#include <vector>

using namespace std;

class RegularExpressionMatching
{
    struct EasyDigraph
    {
        explicit EasyDigraph(const size_t V): graph(V) {}
        void addEdge(const int v, const int w){ graph[v].push_back(w); }
        size_t size() const { return graph.size(); }
        const vector<int>& adj(const int v) const {return graph[v];}
        vector<vector<int>> graph{};
    };

    using StateContainer = vector<int>;

public:
    bool isMatch(const string& text, const string& pattern)
    {
        if (pattern.empty()) return true;

        const EasyDigraph graph(std::move(buildDigraph(pattern)));

        StateContainer states;

        // initial state
        states.push_back(0);
        epsilonTransmit(graph, states);

        for (const char ch : text)
        {
            matchTransmit(ch, pattern, states);
            epsilonTransmit(graph, states);
        }

        return find(states.begin(), states.end(), pattern.size()) != states.end();
    }

private:
    // skip validate pattern
    static EasyDigraph buildDigraph(const string& pattern)
    {
        EasyDigraph graph(pattern.size() + 1);

        for (int i = 0; i < pattern.size(); ++i)
        {
            if (pattern[i] == '*')
            {
                graph.addEdge(i, i - 1);
                graph.addEdge(i, i + 1);
            }
            else if (i + 1 < pattern.size() && pattern[i + 1] == '*')
            {
                graph.addEdge(i, i + 1);
            }
        }

        return graph;
    }

    static void epsilonTransmit(const EasyDigraph& digraph, StateContainer& states)
    {
        StateContainer queue(states);

        while (!queue.empty())
        {
            const int state = queue.back();
            queue.pop_back();

            for (int v : digraph.adj(state))
            {
                if (find(states.begin(), states.end(), v) != states.end()) continue;
                queue.push_back(v);
                states.push_back(v);
            }
        }
    }

    static void matchTransmit(const char text, const string& pattern, StateContainer& states)
    {
        using std::swap;
        StateContainer temp;
        swap(temp, states);

        for (const int state: temp)
        {
            if (state >= pattern.size()) continue;

            // char matched
            if (text == pattern[state] || pattern[state] == '.')
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
    REQUIRE(RegularExpressionMatching().isMatch("aa", "aa") == true);
    REQUIRE(RegularExpressionMatching().isMatch("aa", "a*") == true);
    REQUIRE(RegularExpressionMatching().isMatch("ab", ".*") == true);
    REQUIRE(RegularExpressionMatching().isMatch("aaab", "a*b") == true);
    REQUIRE(RegularExpressionMatching().isMatch("aaabbbb", "a*b*") == true);
    REQUIRE(RegularExpressionMatching().isMatch("cccaaabbbb", ".*b*") == true);
}
