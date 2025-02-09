/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
#include<climits>
using std::vector; using std::string; using std::unordered_map;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> &shorter = list1.size() < list2.size() ? list1 : list2;
        vector<string> &longer = list1.size() < list2.size() ? list2 : list1;
        unordered_map<string, int> index_map;
        for(int i = 0; i != shorter.size(); i++){
            index_map[shorter[i]] = i;
        }
        vector<string> ret;
        int min = INT_MAX;
        for(int i = 0; i != longer.size(); i++){
            if(index_map.find(longer[i]) != index_map.end()){
                if(index_map[longer[i]] + i < min){
                    ret.clear();
                    min = index_map[longer[i]] + i;
                }
                if(index_map[longer[i]] + i <= min) ret.push_back(longer[i]);
            }
        }
        return ret;
    }
};
// @lc code=end

