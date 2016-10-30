/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_url;
    QPushButton *btn_review;
    QPushButton *btn_open;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_graphView;
    QTextEdit *tEdit1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(630, 375);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        le_url = new QLineEdit(centralWidget);
        le_url->setObjectName(QStringLiteral("le_url"));

        horizontalLayout_2->addWidget(le_url);

        btn_review = new QPushButton(centralWidget);
        btn_review->setObjectName(QStringLiteral("btn_review"));

        horizontalLayout_2->addWidget(btn_review);

        btn_open = new QPushButton(centralWidget);
        btn_open->setObjectName(QStringLiteral("btn_open"));

        horizontalLayout_2->addWidget(btn_open);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_graphView = new QPushButton(centralWidget);
        btn_graphView->setObjectName(QStringLiteral("btn_graphView"));

        horizontalLayout->addWidget(btn_graphView);


        verticalLayout->addLayout(horizontalLayout);

        tEdit1 = new QTextEdit(centralWidget);
        tEdit1->setObjectName(QStringLiteral("tEdit1"));

        verticalLayout->addWidget(tEdit1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_review->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", 0));
        btn_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        btn_graphView->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
