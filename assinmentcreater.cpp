#include "assinmentcreater.h"
#include "ui_assinmentcreater.h"

AssinmentCreater::AssinmentCreater(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AssinmentCreater)
{
    ui->setupUi(this);
}

AssinmentCreater::~AssinmentCreater()
{
    delete ui;
}

void AssinmentCreater::on_createPaper_clicked()
{
    testPaper = new NewPaper;
    testPaper->show();

}
