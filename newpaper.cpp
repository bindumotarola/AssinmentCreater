#include "newpaper.h"
#include "ui_newpaper.h"

NewPaper::NewPaper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPaper)
{
    ui->setupUi(this);
}

NewPaper::~NewPaper()
{
    delete ui;
}

void NewPaper::on_newPaper_clicked()
{
    QString filepath ="D:/dk work/Motarola/project/assinment/";
    filepath.append(ui->fileName->text());
    filepath.append(".xml");

    QFile newPaperFile(filepath);
    if(!newPaperFile.open(QFile::Append| QFile::Text))
    {

    }
    else
    {
        QDomDocument document;


        QDomElement root = document.createElement("Question_Paper");


        QDomElement header= document.createElement("Header");


        QDomElement titlenode=document.createElement("Title");
        titlenode.appendChild(document.createTextNode(ui->titel->text()));
        header.appendChild(titlenode);


        QDomElement classnode=document.createElement("Class");
        classnode.appendChild(document.createTextNode(ui->class_2->text()));
        header.appendChild(classnode);

        QDomElement subjectnode=document.createElement("Subject");
        subjectnode.appendChild(document.createTextNode(ui->subject->text()));
        header.appendChild(subjectnode);

        QDomElement teacherenode=document.createElement("Teacher");
        teacherenode.appendChild(document.createTextNode(ui->teacher->text()));
        header.appendChild(teacherenode);


        root.appendChild(header);
        document.appendChild(root);
        QTextStream stream(&newPaperFile);
        stream <<document.toString();
        newPaperFile.close();
        //wait for write file




    }


    paper = new TestPaper(0,filepath);
    paper->show();
}
