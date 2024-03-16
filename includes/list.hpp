#ifndef LEETCODE_SOLUTION_LIST_HPP
#define LEETCODE_SOLUTION_LIST_HPP

#include <stdexcept>

template<class ValueType>
class List {
    struct ListNode {
        ValueType val;
        ListNode *next;
        explicit ListNode(ValueType value) : val(value), next(nullptr) {}
    };
protected:
    ListNode *head = nullptr;
    ListNode *rear = nullptr;
public:
    [[nodiscard]] inline bool empty() const { return head == nullptr; }

    void push_back(ValueType value);

    void pop_back();

    const ValueType & back() const;

    const ValueType &front() const;

    virtual ~List(){
        while (head != nullptr){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template<class ValueType>
const ValueType &List<ValueType>::front() const {
    if (empty()){
        throw std::out_of_range("List underflow");
    }

    return rear->val;
}

template<class ValueType>
const ValueType & List<ValueType>::back() const {
    if (empty()){
        throw std::out_of_range("List underflow");
    }

    return head->val;
}

template<class ValueType>
void List<ValueType>::pop_back() {
    if (empty()){
        throw std::out_of_range("List underflow");
    }

    ListNode *node = head;

    head = head->next;

    if (empty()){
        rear = nullptr;
    }

    delete node;
}

template<class ValueType>
void List<ValueType>::push_back(ValueType value) {
    auto node = new ListNode(value);

    if (empty()){
        head = rear = node;
    }
    else{
        node->next = head;
        head = node;
    }
}

#endif //LEETCODE_SOLUTION_LIST_HPP
