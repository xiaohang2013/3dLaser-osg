/********************************************************************************
** Form generated from reading UI file 'markwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKWINDOW_H
#define UI_MARKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MarkWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_mark;
    QLineEdit *le_mark_val;
    QHBoxLayout *ly_mark;
    QPushButton *btn_mark_font;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_mark_para;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_mark_gen;

    void setupUi(QDialog *MarkWindow)
    {
        if (MarkWindow->objectName().isEmpty())
            MarkWindow->setObjectName(QStringLiteral("MarkWindow"));
        MarkWindow->resize(320, 239);
        verticalLayout = new QVBoxLayout(MarkWindow);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_mark = new QLabel(MarkWindow);
        lb_mark->setObjectName(QStringLiteral("lb_mark"));

        verticalLayout->addWidget(lb_mark);

        le_mark_val = new QLineEdit(MarkWindow);
        le_mark_val->setObjectName(QStringLiteral("le_mark_val"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_mark_val->sizePolicy().hasHeightForWidth());
        le_mark_val->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(le_mark_val);

        ly_mark = new QHBoxLayout();
        ly_mark->setSpacing(12);
        ly_mark->setObjectName(QStringLiteral("ly_mark"));
        ly_mark->setContentsMargins(9, -1, 9, -1);
        btn_mark_font = new QPushButton(MarkWindow);
        btn_mark_font->setObjectName(QStringLiteral("btn_mark_font"));

        ly_mark->addWidget(btn_mark_font);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_mark->addItem(horizontalSpacer);

        btn_mark_para = new QPushButton(MarkWindow);
        btn_mark_para->setObjectName(QStringLiteral("btn_mark_para"));

        ly_mark->addWidget(btn_mark_para);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_mark->addItem(horizontalSpacer_2);

        btn_mark_gen = new QPushButton(MarkWindow);
        btn_mark_gen->setObjectName(QStringLiteral("btn_mark_gen"));

        ly_mark->addWidget(btn_mark_gen);


        verticalLayout->addLayout(ly_mark);


        retranslateUi(MarkWindow);
        QObject::connect(btn_mark_font, SIGNAL(toggled(bool)), MarkWindow, SLOT(slot_mark_font()));
        QObject::connect(btn_mark_para, SIGNAL(toggled(bool)), MarkWindow, SLOT(slot_mark_para()));
        QObject::connect(btn_mark_gen, SIGNAL(toggled(bool)), MarkWindow, SLOT(slot_mark_gen()));

        QMetaObject::connectSlotsByName(MarkWindow);
    } // setupUi

    void retranslateUi(QDialog *MarkWindow)
    {
        MarkWindow->setWindowTitle(QApplication::translate("MarkWindow", "\347\274\226\345\217\267\346\240\207\350\256\260\347\224\237\346\210\220", 0));
        lb_mark->setText(QApplication::translate("MarkWindow", "\346\211\223\346\240\207\347\240\201:", 0));
        btn_mark_font->setText(QApplication::translate("MarkWindow", "\345\255\227\344\275\223", 0));
        btn_mark_para->setText(QApplication::translate("MarkWindow", "\345\217\202\346\225\260", 0));
        btn_mark_gen->setText(QApplication::translate("MarkWindow", "\347\224\237\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class MarkWindow: public Ui_MarkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKWINDOW_H
