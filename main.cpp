#include "assinmentcreater.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AssinmentCreater w;
    w.show();
    
    return a.exec();
}
