#include "catch_amalgamated.hpp"

#include <vector>

using namespace std;

class WildcardMatching
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
    bool isMatch(const string& text, const string& originPattern)
    {
        const string pattern = toRegex(originPattern);
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
    // convert wildcard match to a regex
    static string toRegex(const string& pattern)
    {
        string result;

        for (const char ch : pattern)
        {
            if (ch == '*')
            {
                result.push_back('?');
            }
            result.push_back(ch);
        }

        return result;
    }

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
        vector<char> visited(digraph.graph.size(), 0);

        while (!queue.empty())
        {
            const int state = queue.back();
            queue.pop_back();
            visited[state] = 1;

            for (int v : digraph.adj(state))
            {
                if (visited[v]) continue;
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
            if (text == pattern[state] || pattern[state] == '?')
            {
                states.push_back(state + 1);
            }
        }
    }
};

TEST_CASE("WildcardMatching", "[WildcardMatching]")
{
    REQUIRE(WildcardMatching().isMatch("aaa", "aaaa") == false);
    REQUIRE(WildcardMatching().isMatch("aa", "a") == false);
    REQUIRE(WildcardMatching().isMatch("aa", "aa") == true);
    REQUIRE(WildcardMatching().isMatch("aa", "a?") == true);
    REQUIRE(WildcardMatching().isMatch("ab", "a?") == true);
    REQUIRE(WildcardMatching().isMatch("ab", "*") == true);
    REQUIRE(WildcardMatching().isMatch("ab", "") == false);
}
