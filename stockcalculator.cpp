#include "stockcalculator.h"
#include "ui_stockcalculator.h"

StockCalculator::StockCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockCalculator)
{
    ui->setupUi(this);
}

StockCalculator::~StockCalculator()
{
    delete ui;
}
