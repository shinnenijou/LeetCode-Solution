#include <string>
#include <vector>
#include <stack>

#include "catch_amalgamated.hpp"
using namespace std;


class GenerateParentheses
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> vec{};
        string s{};
        parenthesis(vec, s, 0, n, n);
        return vec;
    }

private:
    static constexpr char left = '(';
    static constexpr char right = ')';

    void parenthesis(vector<string>& vec, string& s, int onStack, int remain, int n)
    {
        if (s.size() == n << 1)
        {
            vec.push_back(s);
            return;
        }

        if ( onStack < remain )
        {
            s.push_back(left);
            parenthesis(vec, s, onStack + 1, remain, n);
            s.pop_back();
        }

        if (onStack > 0)
        {
            s.push_back(right);
            parenthesis(vec, s, onStack - 1, remain - 1, n);
            s.pop_back();
        }
    }
};

TEST_CASE("GenerateParentheses", "[GenerateParentheses]")
{
    REQUIRE(GenerateParentheses().generateParenthesis(3) == vector<string>{"((()))","(()())","(())()","()(())","()()()"});
    REQUIRE(GenerateParentheses().generateParenthesis(2) == vector<string>{"(())", "()()"});
    REQUIRE(GenerateParentheses().generateParenthesis(1) == vector<string>{"()"});
}
