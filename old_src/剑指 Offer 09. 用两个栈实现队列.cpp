/*
 * 剑指 Offer 09. 用两个栈实现队列
 */

// @lc code=start
#include<stack>
using std::stack;

class CQueue {
private:
    stack<int> stack_in;
    stack<int> stack_out;
public:
    CQueue():stack_in(), stack_out() {

    }
    
    void appendTail(int value) {
        stack_in.push(value);
    }
    
    int deleteHead() {
        if(stack_out.empty())
        {
            while(!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }

        if (stack_out.empty())
        {
            return -1;
        }

        int top = stack_out.top();
        stack_out.pop();
        return top;
        
    }
};
// @lc code=end
