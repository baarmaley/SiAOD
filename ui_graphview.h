/********************************************************************************
** Form generated from reading UI file 'graphview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVIEW_H
#define UI_GRAPHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphView
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_zoomPlus;
    QPushButton *btn_zoomMinus;
    QPushButton *btn_colorize;
    QSpacerItem *verticalSpacer;
    QLineEdit *le_CountColor;

    void setupUi(QWidget *GraphView)
    {
        if (GraphView->objectName().isEmpty())
            GraphView->setObjectName(QStringLiteral("GraphView"));
        GraphView->resize(597, 435);
        GraphView->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout_2 = new QVBoxLayout(GraphView);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(GraphView);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setDragMode(QGraphicsView::NoDrag);

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_zoomPlus = new QPushButton(GraphView);
        btn_zoomPlus->setObjectName(QStringLiteral("btn_zoomPlus"));

        verticalLayout->addWidget(btn_zoomPlus);

        btn_zoomMinus = new QPushButton(GraphView);
        btn_zoomMinus->setObjectName(QStringLiteral("btn_zoomMinus"));

        verticalLayout->addWidget(btn_zoomMinus);

        btn_colorize = new QPushButton(GraphView);
        btn_colorize->setObjectName(QStringLiteral("btn_colorize"));

        verticalLayout->addWidget(btn_colorize);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        le_CountColor = new QLineEdit(GraphView);
        le_CountColor->setObjectName(QStringLiteral("le_CountColor"));

        verticalLayout_2->addWidget(le_CountColor);


        retranslateUi(GraphView);

        QMetaObject::connectSlotsByName(GraphView);
    } // setupUi

    void retranslateUi(QWidget *GraphView)
    {
        GraphView->setWindowTitle(QApplication::translate("GraphView", "\320\223\321\200\320\260\321\204", 0));
        btn_zoomPlus->setText(QApplication::translate("GraphView", "+", 0));
        btn_zoomMinus->setText(QApplication::translate("GraphView", "-", 0));
        btn_colorize->setText(QApplication::translate("GraphView", "\320\240\320\260\321\201\320\272\321\200\320\260\321\201\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphView: public Ui_GraphView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEW_H
