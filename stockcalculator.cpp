#include "stockcalculator.h"
#include "ui_stockcalculator.h"

StockCalculator::StockCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockCalculator), stock()
{
    ui->setupUi(this);
}

StockCalculator::~StockCalculator()
{
    delete ui;
}


void StockCalculator::on_lineEdit_price_textEdited(const QString &price)
{

    stock.setPrice(price.toDouble());
    updateTotal();
    updateBrokerage();
//    qDebug() << stock.getPrice();
}

/*
void StockCalculator::on_pushButton_clicked()
{
    ui->lineEdit_price->setText(QString::number(i++));
}
*/

void StockCalculator::on_lineEdit_qty_textEdited(const QString &qty)
{
    stock.setQty(qty.toInt());
    updateTotal();
    updateBrokerage();
}

void StockCalculator::on_lineEdit_total_textEdited(const QString &total)
{
    stock.setQty(total.toDouble()/stock.getPrice());
    ui->lineEdit_qty->setText(QString::number(stock.getQty()));
    updateBrokerage();
}

void StockCalculator::on_radioButton_buy_clicked()
{
    updateTotal();
    updateBrokerage();
}

void StockCalculator::on_radioButton_sell_clicked()
{
    updateTotal();
    updateBrokerage();
}


void StockCalculator::updateTotal()
{
    if(ui->radioButton_buy->isChecked())
        ui->lineEdit_total->setText(QString::number(stock.getTotal() + stock.getBrokerage()));
    else
        ui->lineEdit_total->setText(QString::number(stock.getTotal() - stock.getBrokerage()));
}

void StockCalculator::updateBrokerage()
{
    ui->label_brokerage_value->setText(QString::number(stock.getBrokerage()));
}

