#ifndef STOCKCALCULATOR_H
#define STOCKCALCULATOR_H

#include <QMainWindow>
#include <QtDebug>
#include "stock.h"
namespace Ui {
class StockCalculator;
}

class StockCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit StockCalculator(QWidget *parent = 0);
    ~StockCalculator();

private:
    Ui::StockCalculator *ui;
};

#endif // STOCKCALCULATOR_H
