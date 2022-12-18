//
// Created by nordi on 12/6/2022.
//

#ifndef METODIK_LABORATION03_PQUEUE_H
#define METODIK_LABORATION03_PQUEUE_H

#include <vector>
#include <algorithm>

namespace metodik_laboration02 {


    template<typename T, typename Comparator = std::greater<>>
    class pQueue {
    public:
        // Constructor
        pQueue() = default;

        explicit pQueue(Comparator comparator = Comparator()) : comparator(comparator) {}

        // Add an element to the queue
        void push(const T &element) {
            // Add the element to the end of the vector
            m_elements.push_back(element);

            // Reorder the vector to maintain the valid heap structure
            std::push_heap(m_elements.begin(), m_elements.end(), comparator);
        }

        // Remove the top element from the queue
        void pop() {
            // Reorder the vector to maintain the valid heap structure
            std::pop_heap(m_elements.begin(), m_elements.end(), comparator);

            // Remove the top element from the end of the vector
            m_elements.pop_back();
        }

        // Return the top element in the queue
        const T &top() const {
            return m_elements.front();
        }
        // Return the element at position in the queue
        const T &at(const size_t &p) const {
            return m_elements.at(p);
        }
        // Erase element at position in the queue
        void eraseElement(const size_t &p){
            m_elements.erase(m_elements.begin() + p);
        }

        // Return number of elements in the queue
        [[nodiscard]] size_t size() const {
            return m_elements.size();
        }

        // Check if the queue is empty
        [[nodiscard]] bool empty() const {
            // Return true if the queue is empty, false otherwise
            return m_elements.empty();
        }

    private:
        // Data structure to store the elements in the queue
        std::vector<T> m_elements;

        // Comparison function object to sort after
        Comparator comparator;
    };

} // metodik_laboration02

#endif //METODIK_LABORATION03_PQUEUE_H
