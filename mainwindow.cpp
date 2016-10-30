#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    graphView = new GraphView;

    connect(ui->btn_graphView, SIGNAL(clicked(bool)), graphView, SLOT(show()));
   // connect(graphView, SIGNAL(UpdateDrawGraph()), this, SLOT(GraphUpdate()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete graphView;
}



void MainWindow::on_btn_review_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open config file"), ".", tr("XML files (*.txt)"));

    qDebug() << fileName;

    ui->le_url->clear();
    ui->le_url->setText(fileName);


}

void MainWindow::on_btn_open_clicked()
{
    QFile file(ui->le_url->text());


    if(file.open(QIODevice::ReadOnly))
    {
        graphView->VertexClear();

        QString str(file.readAll());

        str.replace("\r", "");
        QStringList strList = str.split("\n");


        //Разбиваем на строки
        for(QStringList::Iterator it = strList.begin(); it != strList.end(); it++)
        {

          // На теги
          QStringList subStr = (*it).split("::");

          //Добавляем вершины
          if(subStr[0] == "GROUP")
          {
//              ui->tEdit1->insertPlainText("Ок\n");

              QStringList strSession = subStr[2].split(";;");

              for(QStringList::Iterator it = strSession.begin(); it != strSession.end(); it++)
              {
                    graphView->VertexAdd(subStr[1], (*it));
              }


          }

        }

        graphView->EdgeBuild();

//        QStringList vert = graph->VertexString();

//        for(QStringList::Iterator it = vert.begin(); it != vert.end(); it++)
//        {
//            ui->tEdit1->insertPlainText((*it) + "\n");
//        }

//        for(int i = 0; i < strList.size(); i++)
//            qDebug() << strList[i];


        graphView->DrawGraph();

        ui->tEdit1->insertPlainText("Вершины добавлены!");

        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Ошибка!"), tr("Не удаеться открыть файл!"));
    }
}

void MainWindow::GraphUpdate()
{
    graphView->DrawGraph();
}
