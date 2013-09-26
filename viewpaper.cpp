#include "viewpaper.h"

ViewPaper::ViewPaper(QWidget *parent,QString assinmentFilePath) :
    QWidget(parent)
{
    filepath=assinmentFilePath;

    processPaper();


}

void ViewPaper::processPaper()
{
    QLabel *labale =new QLabel("dfdfdfdfdf");

//    QFile newPaperFile(filepath);
//    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
//    {
//        qDebug()<<"error";

//    }
//    else
//    {
//        QDomDocument document;

//        document.setContent(&newPaperFile);
//        qDebug()<<document.toString();


//        QDomElement root= document.firstChildElement();

//    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(labale);

    setLayout(mainLayout);


}
