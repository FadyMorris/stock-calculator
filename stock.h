#ifndef STOCK_H
#define STOCK_H
#include <math.h>

class Stock
{
    double price, total, brokerage; // Price total and Brokerage
    int qty; //Quantity
    void calculateTotal();
    void calculateBrokerage();
public:
    Stock();
    void setPrice(double);
    double getPrice();

    void setQty(int);
    int getQty();

    double getTotal();
    double getBrokerage();
};

#endif // STOCK_H
