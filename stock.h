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
    void setPrice(long double);
    long double getPrice();

    void setQty(unsigned long long);
    unsigned long long getQty();

    long double getTotal();
    long double getBrokerage();
};

#endif // STOCK_H
