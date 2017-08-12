#include "stock.h"

Stock::Stock()
{
    price = qty = brokerage = total = 0;
}

long double Stock::getVariableBrokerage(const long double multiplicand)
{
    double brokerage;
    brokerage = 0;
    brokerage += round(multiplicand*100*0.0002)/100 \
    + round(multiplicand*100*0.005)/100 \
    + round(multiplicand*100*0.0005)/100 \
    + round(multiplicand*100*0.00012)/100 \
    + round(multiplicand*100*0.000125)/100 \
    + round(multiplicand*100*0.00125)/100 \
    ;
    return brokerage;
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
    brokerage = 11 + getVariableBrokerage(total);
}

void Stock::setTotal(long double total, long double price, bool buyFlag)
{
    this->total = total;
    calculateBrokerage();
    if(buyFlag)
    {
        this->qty = (this->total - this->brokerage) / price ;
    }
    else
    {
        this->qty = (this->total + this->brokerage) / price ;
    }
/*
    this->total = total;
    this->price = price;
    if(buyFlag) //Calculate for buying operation
    {
        this->qty = (total + 11)/(price - getVariableBrokerage(price));
    }
    else
    {
        this->qty = (total - 11)/(price + getVariableBrokerage(price));
    }
    calculateBrokerage();
*/
}

long double Stock::getTotal()
{
    return total;
}

long double Stock::getBrokerage()
{
    return brokerage;
}


void Stock::reset()
{
    price = total = brokerage = qty = 0;
}
