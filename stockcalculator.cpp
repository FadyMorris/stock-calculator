#include "stockcalculator.h"
#include "ui_stockcalculator.h"

StockCalculator::StockCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockCalculator), stock()
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->mainToolBar->hide();
}

StockCalculator::~StockCalculator()
{
    delete ui;
}


QString StockCalculator::qStringFromLongDouble(const long double myLongDouble)
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(2) << myLongDouble;
  return QString::fromStdString(ss.str());
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
    stock.setQty(qty.toULongLong());
    updateTotal();
    updateBrokerage();
}

void StockCalculator::on_lineEdit_total_textEdited(const QString &total)
{
    if(ui->radioButton_buy->isChecked())
    {
        //stock.setQty((total.toDouble() - stock.getBrokerage())/stock.getPrice());
        stock.setTotal(total.toDouble(), true);
    }
    else
    {
        //stock.setQty((total.toDouble() + stock.getBrokerage())/stock.getPrice());
        stock.setTotal(total.toDouble(), false);

    }
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
    {
        ui->lineEdit_total->setText(StockCalculator::qStringFromLongDouble(stock.getTotal() + stock.getBrokerage()));
    }
    else
    {
        ui->lineEdit_total->setText(qStringFromLongDouble(stock.getTotal() - stock.getBrokerage()));
    }
}

void StockCalculator::updateBrokerage()
{
    ui->label_brokerage_value->setText(qStringFromLongDouble(stock.getBrokerage()));
}


void StockCalculator::on_pushButton_reset_clicked()
{
    ui->radioButton_buy->setChecked(true);
    ui->lineEdit_price->setText("");
    ui->lineEdit_qty->setText("");
    ui->lineEdit_total->setText("");
    ui->label_brokerage_value->setText("");
    stock.reset();
}



void StockCalculator::on_lineEdit_stockname_editingFinished()
{
    QWidget::setWindowTitle(ui->lineEdit_stockname->text());
}

