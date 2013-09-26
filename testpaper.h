#ifndef TESTPAPER_H
#define TESTPAPER_H

#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
#include <QtGui>
#include "viewpaper.h"
namespace Ui {
class TestPaper;
}

class TestPaper : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TestPaper(QWidget *parent = 0,QString assinmentFilePath=NULL);
    ~TestPaper();
    QString filepath;
    int qustionNo;
    
   private slots:




    void on_noOfChoice_currentIndexChanged(const QString &arg1);

    void on_answer3_textChanged();

    void on_answer4_textChanged();

    void on_answer5_textChanged();

    void on_answer6_textChanged();

    void on_essayQusion_textChanged();

    void on_addMcq_clicked();

    void on_addEssay_clicked();


    void on_tabWidget_currentChanged(int index);

private:
    Ui::TestPaper *ui;
    void testPaperLayout();

    void ListElements(QDomElement root);

};

#endif // TESTPAPER_H
