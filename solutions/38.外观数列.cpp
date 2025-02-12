#include "catch_amalgamated.hpp"

#include <string>
#include <iostream>
using namespace std;

class CountAndSayRecursive
{
public:
    string countAndSay(int n)
    {
        if (n <= 1) return "1";

        const string prev = countAndSay(n - 1);

        string result{""};
        int i = 0; // point to start

        for (int j = 1; j < prev.length(); ++j)
        {
            if (prev[j] == prev[i]) continue;
            result.append(to_string(j - i));
            result.push_back(prev[i]);
            i = j;
        }

        result.append(to_string(prev.size() - i));
        result.push_back(prev[i]);

        return result;
    }
};

class CountAndSayIterator
{
public:
    string countAndSay(int n)
    {
        using std::swap;
        string prev = "";
        string curr = "1";

        while (--n > 0)
        {
            swap(prev, curr);
            curr.clear();

            int i = 0; // point to start

            for (int j = 1; j < prev.length(); ++j)
            {
                if (prev[j] == prev[i]) continue;
                curr.push_back((j - i) + '0');
                curr.push_back(prev[i]);
                i = j;
            }

            curr.append(to_string(prev.size() - i));
            curr.push_back(prev[i]);
        }

        return curr;
    }
};

TEST_CASE("CountAndSayRecursive", "[CountAndSay]")
{
    REQUIRE(CountAndSayRecursive().countAndSay(1) == "1");
    REQUIRE(CountAndSayRecursive().countAndSay(2) == "11");
    REQUIRE(CountAndSayRecursive().countAndSay(3) == "21");
    REQUIRE(CountAndSayRecursive().countAndSay(4) == "1211");
}

TEST_CASE("CountAndSayIterator", "[CountAndSay]")
{
    REQUIRE(CountAndSayIterator().countAndSay(1) == "1");
    REQUIRE(CountAndSayIterator().countAndSay(2) == "11");
    REQUIRE(CountAndSayIterator().countAndSay(3) == "21");
    REQUIRE(CountAndSayIterator().countAndSay(4) == "1211");

    cout << CountAndSayIterator().countAndSay(30) << endl;
}
