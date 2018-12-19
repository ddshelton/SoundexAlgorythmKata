//
// Created by hvalle on 12/17/2018.
//

#ifndef Portfolio_h
#define Portfolio_h

#include <string>
#include <exception>
#include <unordered_map>

class InvalidPurchaseException: public std::exception {
};

class InvalidSellException: public std::exception {
};

class Portfolio {
public:
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount);
    void Sell(const std::string& symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string& symbol) const;

private:
    std::unordered_map<std::string, unsigned int> holdings_;
};

#endif
