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
        stack<char> stack{};
        tryPush(vec, s, stack, n);
        return vec;
    }

private:
    static constexpr char left = '(';
    static constexpr char right = ')';

    void tryPush(vector<string>& vec, string& s, stack<char>& stack, int remain)
    {
        if (remain == 0) return;

        stack.push(left);
        s.push_back(left);

        if (stack.size() < remain)
        {
            tryPush(vec, s, stack, remain);
        }

        if (!stack.empty())
        {
            tryPop(vec, s, stack, remain);
        }

        stack.pop();
        s.pop_back();
    }

    void tryPop(vector<string>& vec, string& s, stack<char>& stack, int remain)
    {
        if (remain == 0) return;

        char temp = stack.top();
        stack.pop();
        s.push_back(right);

        --remain;

        if (remain == 0)
        {
            vec.push_back(s);
        }
        else
        {
            if (stack.size() < remain)
            {
                tryPush(vec, s, stack, remain);
            }

            if (!stack.empty())
            {
                tryPop(vec, s, stack, remain);
            }
        }

        stack.push(temp);
        s.pop_back();
    }
};

TEST_CASE("GenerateParentheses", "[GenerateParentheses]")
{
    REQUIRE(GenerateParentheses().generateParenthesis(3) == vector<string>{"((()))","(()())","(())()","()(())","()()()"});
    REQUIRE(GenerateParentheses().generateParenthesis(1) == vector<string>{"()"});
}
