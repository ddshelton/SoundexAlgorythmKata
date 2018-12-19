//
// Created by hvalle on 12/17/2018.
//

#ifndef Portfolio_h
#define Portfolio_h

#include <string>
#include <exception>
#include <unordered_map>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <vector>

class InvalidPurchaseException: public std::exception {
};

class InvalidSellException: public std::exception {
};
struct PurchaseRecord
{
    PurchaseRecord(unsigned int shareCount, const boost ::gregorian::date& date)
    : ShareCount(shareCount), Date(date){};
    unsigned int ShareCount;
    boost::gregorian::date Date;
};

class Portfolio {
public:
    static const boost::gregorian::date FIXED_PURCHASE_DATE;
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount);
    void Sell(const std::string& symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string& symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string& symbol)const;

private:
    std::unordered_map<std::string, unsigned int> holdings_;
    std::vector<PurchaseRecord> purchases_;
};

#endif
