#ifndef VIEWPAPER_H
#define VIEWPAPER_H

#include <QWidget>
#include <QtWidgets>
#include <QtGui>
#include <QAbstractScrollArea>
#include <QtXml>
class ViewPaper : public QWidget
{
    Q_OBJECT
public:
    explicit ViewPaper(QWidget *parent = 0,QString assinmentFilePath=NULL);
    void processPaper();
     QString filepath;


    
signals:
    
public slots:
    
};

#endif // VIEWPAPER_H
