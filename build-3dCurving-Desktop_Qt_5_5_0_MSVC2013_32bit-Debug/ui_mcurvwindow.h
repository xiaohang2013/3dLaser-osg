/********************************************************************************
** Form generated from reading UI file 'mcurvwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MCURVWINDOW_H
#define UI_MCURVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_McurvWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *ly_mcurv1;
    QCheckBox *cb_mcurv;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cb_voice;
    QGridLayout *ly_mcurv2;
    QLabel *lb_mcurv_num;
    QLabel *lb_num_X;
    QLineEdit *le_space_Y;
    QLabel *lb_space_Y2;
    QLabel *lb_space_Y;
    QLabel *lb_space_X;
    QLineEdit *le_space_X;
    QLabel *lb_mcurv_space;
    QLabel *lb_space_X2;
    QLabel *lb_num_Y;
    QLineEdit *le_num_Y;
    QLineEdit *le_num_X;
    QCheckBox *cb_mcurv_size;
    QHBoxLayout *ly_mcurv3;
    QLabel *lb_mcurv_width;
    QLineEdit *le_mcurv_width;
    QLabel *lb_mcurv_width2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lb_mcurv_len;
    QLineEdit *le_mcurv_len;
    QLabel *lb_mcurv_len2;
    QHBoxLayout *ly_mcurv4;
    QComboBox *cb_mark_type;
    QPushButton *btn_mcurv_mark;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_mcurv_enter;
    QPushButton *btn_mcurv_cancel;

    void setupUi(QDialog *McurvWindow)
    {
        if (McurvWindow->objectName().isEmpty())
            McurvWindow->setObjectName(QStringLiteral("McurvWindow"));
        McurvWindow->resize(337, 240);
        verticalLayout = new QVBoxLayout(McurvWindow);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, -1, 12, -1);
        ly_mcurv1 = new QHBoxLayout();
        ly_mcurv1->setObjectName(QStringLiteral("ly_mcurv1"));
        cb_mcurv = new QCheckBox(McurvWindow);
        cb_mcurv->setObjectName(QStringLiteral("cb_mcurv"));

        ly_mcurv1->addWidget(cb_mcurv);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_mcurv1->addItem(horizontalSpacer_2);

        cb_voice = new QCheckBox(McurvWindow);
        cb_voice->setObjectName(QStringLiteral("cb_voice"));

        ly_mcurv1->addWidget(cb_voice);


        verticalLayout->addLayout(ly_mcurv1);

        ly_mcurv2 = new QGridLayout();
        ly_mcurv2->setObjectName(QStringLiteral("ly_mcurv2"));
        ly_mcurv2->setHorizontalSpacing(6);
        lb_mcurv_num = new QLabel(McurvWindow);
        lb_mcurv_num->setObjectName(QStringLiteral("lb_mcurv_num"));

        ly_mcurv2->addWidget(lb_mcurv_num, 0, 0, 1, 1);

        lb_num_X = new QLabel(McurvWindow);
        lb_num_X->setObjectName(QStringLiteral("lb_num_X"));

        ly_mcurv2->addWidget(lb_num_X, 0, 1, 1, 1);

        le_space_Y = new QLineEdit(McurvWindow);
        le_space_Y->setObjectName(QStringLiteral("le_space_Y"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_space_Y->sizePolicy().hasHeightForWidth());
        le_space_Y->setSizePolicy(sizePolicy);
        le_space_Y->setMaximumSize(QSize(16777215, 16777215));

        ly_mcurv2->addWidget(le_space_Y, 1, 5, 1, 1);

        lb_space_Y2 = new QLabel(McurvWindow);
        lb_space_Y2->setObjectName(QStringLiteral("lb_space_Y2"));

        ly_mcurv2->addWidget(lb_space_Y2, 1, 6, 1, 1);

        lb_space_Y = new QLabel(McurvWindow);
        lb_space_Y->setObjectName(QStringLiteral("lb_space_Y"));

        ly_mcurv2->addWidget(lb_space_Y, 1, 4, 1, 1);

        lb_space_X = new QLabel(McurvWindow);
        lb_space_X->setObjectName(QStringLiteral("lb_space_X"));

        ly_mcurv2->addWidget(lb_space_X, 1, 1, 1, 1);

        le_space_X = new QLineEdit(McurvWindow);
        le_space_X->setObjectName(QStringLiteral("le_space_X"));
        sizePolicy.setHeightForWidth(le_space_X->sizePolicy().hasHeightForWidth());
        le_space_X->setSizePolicy(sizePolicy);
        le_space_X->setMaximumSize(QSize(16777215, 16777215));

        ly_mcurv2->addWidget(le_space_X, 1, 2, 1, 1);

        lb_mcurv_space = new QLabel(McurvWindow);
        lb_mcurv_space->setObjectName(QStringLiteral("lb_mcurv_space"));

        ly_mcurv2->addWidget(lb_mcurv_space, 1, 0, 1, 1);

        lb_space_X2 = new QLabel(McurvWindow);
        lb_space_X2->setObjectName(QStringLiteral("lb_space_X2"));

        ly_mcurv2->addWidget(lb_space_X2, 1, 3, 1, 1);

        lb_num_Y = new QLabel(McurvWindow);
        lb_num_Y->setObjectName(QStringLiteral("lb_num_Y"));

        ly_mcurv2->addWidget(lb_num_Y, 0, 4, 1, 1);

        le_num_Y = new QLineEdit(McurvWindow);
        le_num_Y->setObjectName(QStringLiteral("le_num_Y"));
        sizePolicy.setHeightForWidth(le_num_Y->sizePolicy().hasHeightForWidth());
        le_num_Y->setSizePolicy(sizePolicy);
        le_num_Y->setMaximumSize(QSize(16777215, 16777215));

        ly_mcurv2->addWidget(le_num_Y, 0, 5, 1, 1);

        le_num_X = new QLineEdit(McurvWindow);
        le_num_X->setObjectName(QStringLiteral("le_num_X"));
        sizePolicy.setHeightForWidth(le_num_X->sizePolicy().hasHeightForWidth());
        le_num_X->setSizePolicy(sizePolicy);
        le_num_X->setMaximumSize(QSize(16777215, 16777215));

        ly_mcurv2->addWidget(le_num_X, 0, 2, 1, 1);


        verticalLayout->addLayout(ly_mcurv2);

        cb_mcurv_size = new QCheckBox(McurvWindow);
        cb_mcurv_size->setObjectName(QStringLiteral("cb_mcurv_size"));

        verticalLayout->addWidget(cb_mcurv_size);

        ly_mcurv3 = new QHBoxLayout();
        ly_mcurv3->setObjectName(QStringLiteral("ly_mcurv3"));
        lb_mcurv_width = new QLabel(McurvWindow);
        lb_mcurv_width->setObjectName(QStringLiteral("lb_mcurv_width"));

        ly_mcurv3->addWidget(lb_mcurv_width);

        le_mcurv_width = new QLineEdit(McurvWindow);
        le_mcurv_width->setObjectName(QStringLiteral("le_mcurv_width"));
        sizePolicy.setHeightForWidth(le_mcurv_width->sizePolicy().hasHeightForWidth());
        le_mcurv_width->setSizePolicy(sizePolicy);

        ly_mcurv3->addWidget(le_mcurv_width);

        lb_mcurv_width2 = new QLabel(McurvWindow);
        lb_mcurv_width2->setObjectName(QStringLiteral("lb_mcurv_width2"));

        ly_mcurv3->addWidget(lb_mcurv_width2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_mcurv3->addItem(horizontalSpacer_3);

        lb_mcurv_len = new QLabel(McurvWindow);
        lb_mcurv_len->setObjectName(QStringLiteral("lb_mcurv_len"));

        ly_mcurv3->addWidget(lb_mcurv_len);

        le_mcurv_len = new QLineEdit(McurvWindow);
        le_mcurv_len->setObjectName(QStringLiteral("le_mcurv_len"));
        sizePolicy.setHeightForWidth(le_mcurv_len->sizePolicy().hasHeightForWidth());
        le_mcurv_len->setSizePolicy(sizePolicy);

        ly_mcurv3->addWidget(le_mcurv_len);

        lb_mcurv_len2 = new QLabel(McurvWindow);
        lb_mcurv_len2->setObjectName(QStringLiteral("lb_mcurv_len2"));

        ly_mcurv3->addWidget(lb_mcurv_len2);


        verticalLayout->addLayout(ly_mcurv3);

        ly_mcurv4 = new QHBoxLayout();
        ly_mcurv4->setObjectName(QStringLiteral("ly_mcurv4"));
        cb_mark_type = new QComboBox(McurvWindow);
        cb_mark_type->setObjectName(QStringLiteral("cb_mark_type"));

        ly_mcurv4->addWidget(cb_mark_type);

        btn_mcurv_mark = new QPushButton(McurvWindow);
        btn_mcurv_mark->setObjectName(QStringLiteral("btn_mcurv_mark"));
        btn_mcurv_mark->setEnabled(false);

        ly_mcurv4->addWidget(btn_mcurv_mark);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_mcurv4->addItem(horizontalSpacer);

        btn_mcurv_enter = new QPushButton(McurvWindow);
        btn_mcurv_enter->setObjectName(QStringLiteral("btn_mcurv_enter"));

        ly_mcurv4->addWidget(btn_mcurv_enter);

        btn_mcurv_cancel = new QPushButton(McurvWindow);
        btn_mcurv_cancel->setObjectName(QStringLiteral("btn_mcurv_cancel"));

        ly_mcurv4->addWidget(btn_mcurv_cancel);


        verticalLayout->addLayout(ly_mcurv4);


        retranslateUi(McurvWindow);

        QMetaObject::connectSlotsByName(McurvWindow);
    } // setupUi

    void retranslateUi(QDialog *McurvWindow)
    {
        McurvWindow->setWindowTitle(QApplication::translate("McurvWindow", "\346\211\271\351\207\217\351\233\225\345\210\273\350\256\276\347\275\256", 0));
        cb_mcurv->setText(QApplication::translate("McurvWindow", "\346\211\271\351\207\217\351\233\225\345\210\273", 0));
        cb_voice->setText(QApplication::translate("McurvWindow", "\350\257\255\351\237\263\346\217\220\351\206\222", 0));
        lb_mcurv_num->setText(QApplication::translate("McurvWindow", "\346\225\260\351\207\217", 0));
        lb_num_X->setText(QApplication::translate("McurvWindow", "X:", 0));
        lb_space_Y2->setText(QApplication::translate("McurvWindow", "mm", 0));
        lb_space_Y->setText(QApplication::translate("McurvWindow", "Y:", 0));
        lb_space_X->setText(QApplication::translate("McurvWindow", "X:", 0));
        lb_mcurv_space->setText(QApplication::translate("McurvWindow", "\351\227\264\350\267\235", 0));
        lb_space_X2->setText(QApplication::translate("McurvWindow", "mm", 0));
        lb_num_Y->setText(QApplication::translate("McurvWindow", "Y:", 0));
        cb_mcurv_size->setText(QApplication::translate("McurvWindow", "\344\270\216\346\260\264\346\231\266\345\260\272\345\257\270\347\233\270\345\220\214", 0));
        lb_mcurv_width->setText(QApplication::translate("McurvWindow", "\345\256\275\345\272\246(X):", 0));
        lb_mcurv_width2->setText(QApplication::translate("McurvWindow", "mm", 0));
        lb_mcurv_len->setText(QApplication::translate("McurvWindow", "\351\225\277\345\272\246(Y):", 0));
        lb_mcurv_len2->setText(QApplication::translate("McurvWindow", "mm", 0));
        cb_mark_type->clear();
        cb_mark_type->insertItems(0, QStringList()
         << QApplication::translate("McurvWindow", "Cross", 0)
         << QApplication::translate("McurvWindow", "Square", 0)
        );
        btn_mcurv_mark->setText(QApplication::translate("McurvWindow", "\346\240\207\350\256\260", 0));
        btn_mcurv_enter->setText(QApplication::translate("McurvWindow", "\347\241\256\345\256\232", 0));
        btn_mcurv_cancel->setText(QApplication::translate("McurvWindow", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class McurvWindow: public Ui_McurvWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCURVWINDOW_H
