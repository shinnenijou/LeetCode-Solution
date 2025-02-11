#include <string>
#include <vector>
#include "catch_amalgamated.hpp"

using namespace std;


class LetterCombinationsOfAPhoneNumber {
public:
    vector<string> letterCombinations(const string &digits) {
        return letterCombinations(digits, digits.size());
    }

private:
    static constexpr char letters[8][4]{
        'a', 'b', 'c', '\0',
        'd', 'e', 'f', '\0',
        'g', 'h', 'i', '\0',
        'j', 'k', 'l', '\0',
        'm', 'n', 'o', '\0',
        'p', 'q', 'r', 's',
        't', 'u', 'v', '\0',
        'w', 'x', 'y', 'z',
    };

    vector<string> letterCombinations(const string &digits, const int end) {
        if (end == 0) return {};

        auto prev = letterCombinations(digits, end - 1);
        if (prev.empty()) prev.push_back("");

        const int row = digits[end - 1] - '2';
        vector<string> ret;

        for (int col = 0; col < 4 && letters[row][col]; ++col) {
            for (const string& s: prev) {
                ret.push_back(s + letters[row][col]);
            }
        }

        return ret;
    }
};

TEST_CASE("LetterCombinationsOfAPhoneNumber", "[LetterCombinationsOfAPhoneNumber]") {
    vector<string> answer;
    vector<string> reference;

    answer = LetterCombinationsOfAPhoneNumber().letterCombinations("23");
    reference = vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    sort(answer.begin(), answer.end());
    sort(reference.begin(), reference.end());
    REQUIRE(answer == reference);


    answer = LetterCombinationsOfAPhoneNumber().letterCombinations("");
    reference = vector<string>{};
    sort(answer.begin(), answer.end());
    sort(reference.begin(), reference.end());
    REQUIRE(answer == reference);

    answer = LetterCombinationsOfAPhoneNumber().letterCombinations("2");
    reference = vector<string>{"a", "b", "c"};
    sort(answer.begin(), answer.end());
    sort(reference.begin(), reference.end());
    REQUIRE(answer == reference);
}
