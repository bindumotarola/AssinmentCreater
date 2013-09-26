#ifndef NEWPAPER_H
#define NEWPAPER_H

#include <QWidget>
#include <QString>
#include <QTextStream>
#include <QtXml>
#include "testpaper.h"
namespace Ui {
class NewPaper;
}

class NewPaper : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewPaper(QWidget *parent = 0);
    ~NewPaper();
    
private slots:
    void on_newPaper_clicked();

private:
    Ui::NewPaper *ui;
    TestPaper *paper;
};

#endif // NEWPAPER_H
