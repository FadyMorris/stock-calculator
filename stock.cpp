#include "stock.h"

Stock::Stock()
{
    price = qty = brokerage = total = 0;
}

void Stock::setPrice(double price)
{
    this->price = price;
    calculateTotal();
    calculateBrokerage();
}

double Stock::getPrice()
{
    return price;
}

void Stock::setQty(int qty)
{
    this->qty = qty;
    calculateTotal();
    calculateBrokerage();
}

int Stock::getQty()
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

double Stock::getTotal()
{
    return total;
}

double Stock::getBrokerage()
{
    return brokerage;
}


