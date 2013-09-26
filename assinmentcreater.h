#ifndef ASSINMENTCREATER_H
#define ASSINMENTCREATER_H

#include <QMainWindow>
#include "newpaper.h"
namespace Ui {
class AssinmentCreater;
}

class AssinmentCreater : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AssinmentCreater(QWidget *parent = 0);
    ~AssinmentCreater();
    
private slots:
    void on_createPaper_clicked();

private:
    Ui::AssinmentCreater *ui;
    NewPaper *testPaper;


};

#endif // ASSINMENTCREATER_H
