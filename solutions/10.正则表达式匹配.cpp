#include "catch_amalgamated.hpp"

#include <unordered_set>
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

public:
    bool isMatch(const string& text, const string& pattern)
    {
        if (pattern.empty()) return true;

        const EasyDigraph graph(std::move(buildDigraph(pattern)));

        vector<int> states;
        vector<char> visited(graph.size(), 0);

        // initial state
        states.push_back(0);
        epsilonTransmit(graph, visited, states);

        for (const char ch : text)
        {
            matchTransmit(ch, pattern, states);
            epsilonTransmit(graph, visited, states);
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

    static void epsilonTransmit(const EasyDigraph& digraph, vector<char>& visited, vector<int>& states)
    {
        vector<int> temp(states);
        fill(visited.begin(), visited.end(), 0);

        while (!temp.empty())
        {
            const int state = temp.back();
            temp.pop_back();

            if (visited[state]) continue;

            // current state
            visited[state] = 1;

            for (int v : digraph.adj(state))
            {
                if (visited[v]) continue;
                temp.push_back(v);
                states.push_back(v);
            }
        }
    }

    static void matchTransmit(const char text, const string& pattern, vector<int>& states)
    {
        using std::swap;
        vector<int> temp;
        swap(temp, states);

        while (!temp.empty())
        {
            const int state = temp.back();
            temp.pop_back();

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
