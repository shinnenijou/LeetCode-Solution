#ifndef LEETCODE_SOLUTION_LIST_HPP
#define LEETCODE_SOLUTION_LIST_HPP

#include <stdexcept>
#include <vector>

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

    vector<ValueType> toVector() const;

    void push_back(ValueType value);

    void pop_back();

    const ValueType &back() const;

    const ValueType &front() const;

    virtual ~List() {
        while (head) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template<class ValueType>
vector<ValueType> List<ValueType>::toVector() const {
    vector<ValueType> ret;

    if (empty()) {
        return ret;
    }

    ListNode *node = head;

    while (node) {
        ret.insert(ret.begin(), node->val);
        node = node->next;
    }

    return ret;
}

template<class ValueType>
const ValueType &List<ValueType>::front() const {
    if (empty()) {
        throw std::out_of_range("List underflow");
    }

    return rear->val;
}

template<class ValueType>
const ValueType &List<ValueType>::back() const {
    if (empty()) {
        throw std::out_of_range("List underflow");
    }

    return head->val;
}

template<class ValueType>
void List<ValueType>::pop_back() {
    if (empty()) {
        throw std::out_of_range("List underflow");
    }

    ListNode *node = head;

    head = head->next;

    if (empty()) {
        rear = nullptr;
    }

    delete node;
}

template<class ValueType>
void List<ValueType>::push_back(ValueType value) {
    auto node = new ListNode(value);

    if (empty()) {
        head = rear = node;
    } else {
        node->next = head;
        head = node;
    }
}

template<class ValueType>
class DualList {
    struct ListNode {
        ValueType val;
        ListNode *next;
        ListNode *prev;

        explicit ListNode(ValueType value) : val(value), next(nullptr), prev(nullptr) {}
    };

protected:
    ListNode *head = nullptr;
    ListNode *rear = nullptr;
public:
    [[nodiscard]] inline bool empty() const { return head == nullptr; }

    vector<ValueType> toVector() const;

    void push_back(ValueType value);

    void pop_back();

    const ValueType &back() const;

    void push_front(ValueType value);

    void pop_front();

    const ValueType &front() const;

    virtual ~DualList() {
        while (head) {
            ListNode *node = head;
            head = head->next;
            delete node;
        }
    }
};

template<class ValueType>
vector<ValueType> DualList<ValueType>::toVector() const {
    vector<ValueType> ret;

    if (empty()) {
        return ret;
    }

    ListNode *node = rear;

    while (node) {
        ret.push_back(node->val);
        node = node->prev;
    }

    return ret;
}

template<class ValueType>
const ValueType &DualList<ValueType>::back() const {
    if (empty()) {
        throw std::out_of_range("DualList underflow");
    }

    return head->val;
}

template<class ValueType>
void DualList<ValueType>::pop_back() {
    if (empty()) {
        throw std::out_of_range("DualList underflow");
    }

    ListNode *temp = head;

    if (!head->next) {
        head = rear = nullptr;
    } else {
        head->next->prev = nullptr;
        head = head->next;
    }

    delete temp;
}

template<class ValueType>
void DualList<ValueType>::push_back(ValueType value) {
    auto node = new ListNode(value);

    if (empty()) {
        head = rear = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

template<class ValueType>
void DualList<ValueType>::push_front(ValueType value) {
    auto node = new ListNode(value);

    if (empty()) {
        head = rear = node;
    } else {
        node->prev = rear;
        head->next = node;
        rear = node;
    }
}

template<class ValueType>
void DualList<ValueType>::pop_front() {
    if (empty()) {
        throw std::out_of_range("DualList underflow");
    }

    ListNode *temp = rear;

    if (!rear->prev) {
        rear = head = nullptr;
    } else {
        rear->prev->next = nullptr;
        rear = rear->prev;
    }

    delete temp;
}

template<class ValueType>
const ValueType &DualList<ValueType>::front() const {
    if (empty()) {
        throw std::out_of_range("DualList underflow");
    }

    return rear->val;
}

#endif //LEETCODE_SOLUTION_LIST_HPP
