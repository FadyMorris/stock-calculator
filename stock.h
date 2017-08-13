#ifndef STOCK_H
#define STOCK_H
#include <math.h>

class Stock
{
    long double price, total, brokerage; // Price total and Brokerage
    unsigned long long qty; //Quantity
    void calculateTotal();
    void calculateBrokerage();
public:
    Stock();
    static long double getVariableBrokerage(const long double multiplicand);
    void setPrice(long double);
    long double getPrice();
    void setQty(unsigned long long);
    unsigned long long getQty();

    void setTotal(long double total, bool buyFlag);
    long double getTotal();
    long double getBrokerage();
    void reset();
};

#endif // STOCK_H
