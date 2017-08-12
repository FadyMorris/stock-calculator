#include "stock.h"

Stock::Stock()
{
    price = qty = brokerage = total = 0;
}

void Stock::setPrice(long double price)
{
    this->price = price;
    calculateTotal();
    calculateBrokerage();
}

long double Stock::getPrice()
{
    return price;
}

void Stock::setQty(unsigned long long qty)
{
    this->qty = qty;
    calculateTotal();
    calculateBrokerage();
}

unsigned long long Stock::getQty()
{
    return qty;
}

void Stock::calculateTotal()
{
    total = price * qty;
}

void Stock::calculateBrokerage()
{
    brokerage = 11 \
            + round(total*100*0.0002)/100 \
            + round(total*100*0.005)/100 \
            + round(total*100*0.0005)/100 \
            + round(total*100*0.00012)/100 \
            + round(total*100*0.000125)/100 \
            + round(total*100*0.00125)/100 \
            ;
}

long double Stock::getTotal()
{
    return total;
}

long double Stock::getBrokerage()
{
    return brokerage;
}


