#include "catch_amalgamated.hpp"
#include <vector>
using namespace std;

class BestTimeToBuyAndSellStockII {
public:
    int maxProfit(const vector<int>& prices) {

        int ret = 0;

        for (int i = 0; i < prices.size();)
        {
            int j = i + 1;
            while (j < prices.size() && prices[j] >= prices[j - 1]) ++j;

            if (j - i > 1)
            {
                ret += prices[j - 1] - prices[i];
            }

            i = j;
        }

        return ret;
    }
};

TEST_CASE("BestTimeToBuyAndSellStockII", "[BestTimeToBuyAndSellStockII]")
{
    REQUIRE(BestTimeToBuyAndSellStockII().maxProfit({7,1,5,3,6,4}) == 7);
    REQUIRE(BestTimeToBuyAndSellStockII().maxProfit({1,2,3,4,5}) == 4);
    REQUIRE(BestTimeToBuyAndSellStockII().maxProfit({7,6,4,3,1}) == 0);
}