#ifndef STOCKCALCULATOR_H
#define STOCKCALCULATOR_H

#include <QMainWindow>
#include <QtDebug>
#include "stock.h"
#include <sstream>
#include <iomanip>
namespace Ui {
class StockCalculator;
}

class StockCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit StockCalculator(QWidget *parent = 0);
    ~StockCalculator();
    static QString qStringFromLongDouble(const long double);
//    int i; //temp


private slots:
    void on_lineEdit_price_textEdited(const QString &price);

   // void on_pushButton_clicked(); //temp

    void on_lineEdit_qty_textEdited(const QString &qty);

    void on_radioButton_buy_clicked();

    void on_radioButton_sell_clicked();

    void on_lineEdit_total_textEdited(const QString &total);

private:
    Ui::StockCalculator *ui;
    Stock stock;
    void updateTotal();
    void updateBrokerage();
};

#endif // STOCKCALCULATOR_H
