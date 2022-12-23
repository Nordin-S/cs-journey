#include <iostream>
#include <random>
#include "pQueue.h"

using namespace metodik_laboration02;

// Comparison function template
template<typename U>
struct Order {
    Order(std::string name, U price) : orderName(std::move(name)), price(price) {}

    std::string orderName;
    U price;
};

// Comparison function template
template<typename T>
struct priorityOrderRule {
    bool operator()(const T &lhs, const T &rhs) const {
        // ascending order
        return lhs.price > rhs.price;
    }
};

int main() {
    // Create a priority queue of int elements
    pQueue<Order<double>, priorityOrderRule<Order<double>>> buyOrders((priorityOrderRule<Order<double>>()));
    pQueue<Order<double>, priorityOrderRule<Order<double>>> sellOrders((priorityOrderRule<Order<double>>()));

// Add some elements to the queue
    std::default_random_engine rnd{std::random_device{}()};
    std::uniform_real_distribution<double> dist(15, 30);
    for (int i = 0; i < 7; ++i) {
        buyOrders.push(Order<double>("Erik Pendel", dist(rnd)));
        buyOrders.push(Order<double>("Jarl Wallenburg", dist(rnd)));
        buyOrders.push(Order<double>("Joakim von Anka", dist(rnd)));

        sellOrders.push(Order<double>("Erik Pendel", dist(rnd)));
        sellOrders.push(Order<double>("Jarl Wallenburg", dist(rnd)));
        sellOrders.push(Order<double>("Joakim von Anka", dist(rnd)));
    }

    while (!sellOrders.empty() && !buyOrders.empty()) {
       if (buyOrders.top().price >= sellOrders.top().price) {
            std::cout << "Buyer: " << buyOrders.top().orderName
                      << " seller: " << sellOrders.top().orderName
                      << " agreed: " << sellOrders.top().price << ":- KR \n";
            sellOrders.pop();
            buyOrders.pop();
        } else {
            buyOrders.pop();
        }
    }
    std::cout << "========== " << sellOrders.size()
              << " sellers could not come to an agreement on price. ==========\n";
    return 0;
}
