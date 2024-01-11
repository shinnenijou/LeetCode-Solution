/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */
#include<vector>
#include<string>
// @lc code=start
class Solution {
private:
    static std::string _fizz(int i){return std::string("Fizz");}
    static std::string _buzz(int i){return std::string("Buzz");}
    static std::string _fizzbuzz(int i){return std::string("FizzBuzz");}
    static std::string _num(int i){return std::to_string(i);}
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::string (*strfunc[15])(int) = {
            _num, _num, _fizz, _num, _buzz, _fizz, _num, _num,
            _fizz, _buzz, _num, _fizz, _num, _num, _fizzbuzz};

        std::vector<std::string> ret;
        for(int i = 1; i != n + 1; i++){
            ret.push_back(strfunc[(i - 1) % 15](i));
        }
        return ret;
    }

};
// @lc code=end

