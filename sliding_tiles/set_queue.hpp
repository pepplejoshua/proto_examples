#pragma once
#include <set>

// duplicate free Queue implementation using Set as underlying
// structure.
// It uses a custom Comparator function to order the Set
// to mimic a minHeap
template <typename Type, typename Comparator>
class SetQueue {
public:
    // initializer
    SetQueue(Comparator compare) : impl(compare) {}
    // get the item at the top of the Queue
    const Type top() const { return *impl.begin(); }
    // pop the item at the top of the Queue
    void pop() { impl.erase(impl.begin()); }
    // check if Queue is empty
    bool empty() { return impl.empty(); }
    // return the size of Queue
    size_t size() const { return impl.size(); }
    // push value into Queue, and then order it.
    // if it is a duplicate, it won't be inserted.
    // uses "==" provided on Type
    void push(const Type& value) { impl.insert(value); }
    // erase value if it exists in Set
    void erase(const Type& value) { impl.erase(value); }
    // delete all contents of Set
    void clear() { impl.clear(); }

    auto begin() { return impl.begin(); }
    auto end() { return impl.end(); }

private:
    std::set<Type, Comparator> impl;
};