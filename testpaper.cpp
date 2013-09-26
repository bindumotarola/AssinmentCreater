#include "testpaper.h"
#include "ui_testpaper.h"

TestPaper::TestPaper(QWidget *parent,QString assinmentFilePath) :
    QMainWindow(parent),
    ui(new Ui::TestPaper)
{
    ui->setupUi(this);

    filepath=assinmentFilePath;
    qustionNo = 0;

   // ui->tabWidget->addTab(new ViewPaper(0,filepath), tr("ViewPaper"));
}

TestPaper::~TestPaper()
{
    delete ui;
}






void TestPaper::on_noOfChoice_currentIndexChanged(const QString &arg1)
{

    if(arg1.toInt()==3)
    {
        ui->answer4->setEnabled(false);
        ui->answer5->setEnabled(false);
        ui->answer6->setEnabled(false);

       ui->answer4lable->setEnabled(false);
       ui->answer5lable->setEnabled(false);
       ui->answer6lable->setEnabled(false);
    }
    if(arg1.toInt()==4)
    {
        ui->answer4->setEnabled(true);
        ui->answer5->setEnabled(false);
        ui->answer6->setEnabled(false);

        ui->answer4lable->setEnabled(true);
        ui->answer5lable->setEnabled(false);
        ui->answer6lable->setEnabled(false);
    }
    if(arg1.toInt()==5)
    {
         ui->answer4->setEnabled(true);
          ui->answer5->setEnabled(true);
          ui->answer6->setEnabled(false);

          ui->answer4lable->setEnabled(true);
          ui->answer5lable->setEnabled(true);
          ui->answer6lable->setEnabled(false);
    }
    if(arg1.toInt()==6)
    {
         ui->answer4->setEnabled(true);
         ui->answer5->setEnabled(true);
         ui->answer6->setEnabled(true);

         ui->answer4lable->setEnabled(true);
         ui->answer5lable->setEnabled(true);
         ui->answer6lable->setEnabled(true);

    }


}

void TestPaper::on_answer3_textChanged()
{
    if(ui->noOfChoice->currentText().toInt()==3)
    {
        if(ui->answer3->toPlainText()==NULL)
         ui->addMcq->setEnabled(false);
        else
          ui->addMcq->setEnabled(true);
    }
}

void TestPaper::on_answer4_textChanged()
{
    if(ui->noOfChoice->currentText().toInt()==4)
    {
        if(ui->answer4->toPlainText()==NULL)
         ui->addMcq->setEnabled(false);
        else
          ui->addMcq->setEnabled(true);
    }




}

void TestPaper::on_answer5_textChanged()
{
    if(ui->noOfChoice->currentText().toInt()==5)
    {
        if(ui->answer5->toPlainText()==NULL)
         ui->addMcq->setEnabled(false);
        else
          ui->addMcq->setEnabled(true);
    }

}

void TestPaper::on_answer6_textChanged()
{
    if(ui->noOfChoice->currentText().toInt()==6)
    {
        if(ui->answer6->toPlainText()==NULL)
         ui->addMcq->setEnabled(false);
        else
          ui->addMcq->setEnabled(true);
    }

}

void TestPaper::on_essayQusion_textChanged()
{
    if(ui->essayQusion->toPlainText()!=NULL)
        ui->addEssay->setEnabled(true);
}

void TestPaper::on_addMcq_clicked()
{


        QFile newPaperFile(filepath);
        if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QDomDocument document;

            document.setContent(&newPaperFile);
            //qDebug()<<document.toString();


            QDomElement root= document.firstChildElement();

              QDomElement Activity= document.createElement("Activity");
              Activity.setAttribute("Type","Mcq");
              qustionNo++;
              Activity.setAttribute("QusetionNo",qustionNo);

               QDomElement Question= document.createElement("Question");
               Question.appendChild(document.createTextNode(ui->msqQuestion->toPlainText()));
               Activity.appendChild(Question);

               for(int x=1;x<=ui->noOfChoice->currentText().toInt();x++)
               {
                   QDomElement Answer= document.createElement("Answer");
                   if(x==1)
                   Answer.appendChild(document.createTextNode(ui->answer1->toPlainText()));
                   if(x==2)
                       Answer.appendChild(document.createTextNode(ui->answer2->toPlainText()));
                   if(x==3)
                       Answer.appendChild(document.createTextNode(ui->answer3->toPlainText()));
                   if(x==4)
                      Answer.appendChild(document.createTextNode(ui->answer4->toPlainText()));
                   if(x==5)
                       Answer.appendChild(document.createTextNode(ui->answer5->toPlainText()));
                   if(x==6)
                       Answer.appendChild(document.createTextNode(ui->answer6->toPlainText()));

                   Activity.appendChild(Answer);
               }



                root.appendChild(Activity);
                document.appendChild(root);

                newPaperFile.close();

                if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
                {
                    qDebug()<<"error";

                }
                else
                {
                    QTextStream stream(&newPaperFile);
                    stream <<document.toString();
                    //qDebug() <<document.toString();
                    newPaperFile.close();
                  QMessageBox::information(this,"Success","Mcq Qustion Added");

                  ui->answer1->clear();
                  ui->answer2->clear();
                  ui->answer3->clear();
                  ui->answer4->clear();
                  ui->answer5->clear();
                  ui->answer6->clear();

                  ui->msqQuestion->clear();


                }

        }





}










void TestPaper::on_addEssay_clicked()
{
    QFile newPaperFile(filepath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }

    QDomDocument document;

    document.setContent(&newPaperFile);

    QDomElement root= document.firstChildElement();

      QDomElement Activity= document.createElement("Activity");
      Activity.setAttribute("Type","Essay");
      qustionNo++;
      Activity.setAttribute("QusetionNo",qustionNo);

      QDomElement Question= document.createElement("Question");
      Question.appendChild(document.createTextNode(ui->essayQusion->toPlainText()));
      Activity.appendChild(Question);


      root.appendChild(Activity);
      document.appendChild(root);

      newPaperFile.close();

      if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
      {
          qDebug()<<"error";

      }
      else
      {
          QTextStream stream(&newPaperFile);
          stream <<document.toString();
          //qDebug() <<document.toString();
          newPaperFile.close();
          QMessageBox::information(this,"Success","Eassy Qustion Added");

          ui->essayQusion->clear();

      }



}



void TestPaper::on_tabWidget_currentChanged(int index)
{
    if(index==1)
    {


    testPaperLayout();


    }

}









void TestPaper::ListElements(QDomElement root)
{
    QGridLayout *layout= new QGridLayout;

    QDomNodeList items = root.elementsByTagName("Header");

    qDebug()<<"Total items"<<items.count();
       QDomNode itemNode = items.at(0);
      QDomElement itemElement=itemNode.toElement();
      QDomNode title=itemElement.elementsByTagName("Title").at(0);
      QDomNode className=itemElement.elementsByTagName("Class").at(0);
      QDomNode subject=itemElement.elementsByTagName("Subject").at(0);
      QDomNode teacther=itemElement.elementsByTagName("Teacher").at(0);

      qDebug()<<title.firstChild().nodeValue();
      qDebug()<<className.firstChild().nodeValue();
      qDebug()<<subject.firstChild().nodeValue();
      qDebug()<<teacther.firstChild().nodeValue();

      //crating labale in header

      QLabel *titleLable=new QLabel(title.firstChild().nodeValue());
      QLabel *classNameLable=new QLabel(title.firstChild().nodeValue());
      QLabel *subjectLable=new QLabel(title.firstChild().nodeValue());
      QLabel *teactherLable=new QLabel(title.firstChild().nodeValue());

      layout->addWidget(titleLable,0,50);
      layout->addWidget(classNameLable,3,0,1,1);
      layout->addWidget(subjectLable,5,0,1,1);
      layout->addWidget(teactherLable,7,0,1,1);





      QDomNodeList activityItems = root.elementsByTagName("Activity");

      qDebug()<<"Total Activity items"<<activityItems.count();

      for (int i=0;i<activityItems.count();i++)
      {
          QDomNode itemNode = activityItems.at(i);


          if(itemNode.isElement())
          {

              if(itemNode.toElement().attribute("Type")=="Mcq")
              {


                  QDomElement itemElement=itemNode.toElement();
                  QDomNode question=itemElement.elementsByTagName("Question").at(0);
                  QDomNode answer1=itemElement.elementsByTagName("Answer").at(0);
                  QDomNode answer2=itemElement.elementsByTagName("Answer").at(1);
                  QDomNode answer3=itemElement.elementsByTagName("Answer").at(2);

                  qDebug()<<question.firstChild().nodeValue();
                  qDebug()<<answer1.firstChild().nodeValue();
                  qDebug()<<answer2.firstChild().nodeValue();
                  qDebug()<<answer3.firstChild().nodeValue();

              }
              if(itemNode.toElement().attribute("Type")=="Essay")
              {
                  QDomElement itemElement=itemNode.toElement();
                  QDomNode question=itemElement.elementsByTagName("Question").at(0);
                  qDebug()<<question.firstChild().nodeValue();

              }

          }


      }
      qDebug()<<"layout row"<<layout->rowCount();
      qDebug()<<"layout colomn"<<layout->columnCount();

      ui->tab_2->setLayout(layout);


}

void TestPaper::testPaperLayout()
{

    QLabel *labale =new QLabel("dfdfdfdfdf");
    QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(labale);


      //  ui->tab_2->setLayout(mainLayout);



        QFile newPaperFile(filepath);
        if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QDomDocument document;

            document.setContent(&newPaperFile);
            qDebug()<<document.toString();

            QDomElement root= document.firstChildElement();

            ListElements(root);
        }


}
