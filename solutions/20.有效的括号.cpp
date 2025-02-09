/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<stack>
#include<unordered_map>
#include <string>

using namespace std;

using std::stack; using std::unordered_map;
class Solution {
public:
    bool isValid(string &s) {
        if(s.size() & 1) return false;
        unordered_map<char, char> bracket_map({{')', '('}, {']', '['}, {'}', '{'}});
        stack<char> brackets;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                brackets.push(s[i]);
            }
            else{
                if(brackets.empty() || brackets.top() != bracket_map[s[i]]){
                    return false;
                }
                else{
                    brackets.pop();
                }
            }
        }
        if(!brackets.empty()) return false;
        return true;
    }
};
// @lc code=end

