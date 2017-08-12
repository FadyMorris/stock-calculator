#include "stockcalculator.h"
#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{
    qDebug("started application !");
    QApplication a(argc, argv);
    StockCalculator w;
/*testing new stock class
    Stock stock;
    stock.setPrice(10.38);
    stock.setQty(1500);
    qDebug() << stock.getTotal();
    qDebug() << stock.getBrokerage();
*/
    w.show();


    return a.exec();
}
