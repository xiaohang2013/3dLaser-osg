/********************************************************************************
** Form generated from reading UI file 'parawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAWINDOW_H
#define UI_PARAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParaWindow
{
public:
    QWidget *w_para_btn;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_sortingMethod;
    QLabel *lb_para_sort;
    QPushButton *pb_laserAndScanner;
    QLabel *lb_para_scan;
    QPushButton *pb_PlatformMotor;
    QLabel *lb_para_motor;
    QScrollArea *sa_sortingMethod;
    QWidget *w_para_sort;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gb_para_crystal;
    QHBoxLayout *horizontalLayout_26;
    QLabel *lb_para_c_w;
    QDoubleSpinBox *dsb_crystalSizeX;
    QLabel *lb_para_c_w2;
    QLabel *lb_para_c_l;
    QDoubleSpinBox *dsb_crystalSizeY;
    QLabel *lb_para_c_l2;
    QLabel *lb_para_c_h;
    QDoubleSpinBox *dsb_crystalSizeZ;
    QLabel *lb_para_c_h2;
    QHBoxLayout *ly_para_s_m;
    QGroupBox *gb_para_s;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *ly_para_s;
    QRadioButton *rb_squenceY2X;
    QRadioButton *rb_squenceX2Y;
    QRadioButton *rb_ShortestPath;
    QGridLayout *ly_para_s_2;
    QLabel *lb_para_w;
    QLabel *lb_para_w2;
    QLabel *lb_para_r;
    QLabel *lb_para_r2;
    QDoubleSpinBox *dsb_blockWidth;
    QDoubleSpinBox *dsb_boundaryDisable;
    QGroupBox *gb_para_m;
    QVBoxLayout *verticalLayout_26;
    QHBoxLayout *ly_min_layer;
    QLabel *lb_min_layer;
    QDoubleSpinBox *dsb_minLayerDis;
    QLabel *lb_min_layer2;
    QSpacerItem *sp_m_1;
    QGridLayout *ly_para_m_correct;
    QSpacerItem *sp_m_correct1;
    QRadioButton *rb_YXCorrect;
    QRadioButton *rb_XYCorrect;
    QRadioButton *rb_noneCorrect;
    QSpacerItem *sp_m_correct2;
    QSpacerItem *sp_m_correct3;
    QLabel *lb_m_correct;
    QSpacerItem *sp_m_correct4;
    QSpacerItem *sp_m_correct5;
    QSpacerItem *sp_m_correct6;
    QSpacerItem *sp_m_correct7;
    QSpacerItem *sp_m_correct8;
    QGroupBox *gb_para_split;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *ly_split_border;
    QLabel *lb_split_border;
    QRadioButton *rb_verticalBorder;
    QRadioButton *rb_inclinedBorder;
    QSpacerItem *sp_split_1;
    QHBoxLayout *ly_split_size;
    QLabel *lb_split_size;
    QLabel *lb_split_size_X;
    QDoubleSpinBox *dsb_blockSizeX;
    QLabel *lb_split_size_X2;
    QLabel *lb_split_size_Y;
    QDoubleSpinBox *dsb_blockSizeY;
    QLabel *lb_split_size_Y2;
    QLabel *lb_split_size_Z;
    QDoubleSpinBox *dsb_blockSizeZ;
    QLabel *lb_split_size_Z2;
    QSpacerItem *sp_split_2;
    QHBoxLayout *ly_split_border_para;
    QLabel *lb_split_border_para;
    QLabel *lb_border_w;
    QDoubleSpinBox *dsb_borderWidth;
    QLabel *lb_border_w2;
    QLabel *lb_border_a;
    QDoubleSpinBox *dsb_borderAngle;
    QLabel *lb_border_a2;
    QSpacerItem *sp_split_border1;
    QScrollArea *sa_laserAndScanner;
    QWidget *w_para_laser;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gb_la_test;
    QHBoxLayout *horizontalLayout_3;
    QWidget *w_laser_pulse;
    QLabel *lb_laser_pulse_title;
    QLabel *lb_highPulseTime;
    QLabel *lb_lwoPulseTime;
    QVBoxLayout *ly_la_test_r_f;
    QHBoxLayout *ly_test_r;
    QLabel *lb_test_r;
    QLabel *lb_laserRatio;
    QLabel *lb_laser_r_v_2;
    QSlider *s_laserRatio;
    QHBoxLayout *ly_test_f;
    QLabel *lb_test_f;
    QLabel *lb_laserFrequency;
    QLabel *lb_test_f2;
    QSlider *s_laserFrequency;
    QGroupBox *gb_la_set;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *ly_la_set_t;
    QGridLayout *ly_la_set_l;
    QLabel *lb_set_lpoint2;
    QLabel *lb_set_lpoint;
    QLabel *lb_set_ltime2;
    QLabel *lb_set_ldelay;
    QLabel *lb_set_ltime;
    QLabel *lb_set_ldelay2;
    QDoubleSpinBox *dsb_focalLength;
    QSpinBox *sb_laserSimmerTime;
    QSpinBox *sb_laserDelay;
    QGridLayout *ly_la_set_r;
    QLabel *lb_set_sdelay;
    QLabel *lb_set_sdelay2;
    QLabel *lb_set_sv;
    QLabel *lb_set_sv2;
    QLabel *lb_set_udelay;
    QLabel *lb_set_udelay2;
    QSpinBox *sb_scannerDelay;
    QSpinBox *sb_scannerSpeed;
    QSpinBox *sb_microStepDelay;
    QHBoxLayout *ly_la_set_b;
    QCheckBox *cb_exchangeXYScanner;
    QCheckBox *cb_stepOverMicroStep;
    QGroupBox *gb_la_para;
    QGridLayout *gridLayout;
    QLabel *lb_la_r_X2;
    QLabel *lb_la_r_Y;
    QLabel *lb_la_r_X;
    QLabel *lb_la_u_Y;
    QLabel *lb_la_u_X;
    QLabel *lb_la_v_X;
    QLabel *lb_la_v_X_2;
    QLabel *lb_la_r_Y2;
    QDoubleSpinBox *dsb_scannerRatioX;
    QDoubleSpinBox *dsb_scannerRatioY;
    QDoubleSpinBox *dsb_scannerAdjustX;
    QDoubleSpinBox *dsb_scannerAdjustY;
    QDoubleSpinBox *dsb_scannerPlatformAdjustX;
    QDoubleSpinBox *dsb_scannerPlatformAdjustY;
    QGroupBox *gb_la_ctrl;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cb_la_r232;
    QScrollArea *sa_platformAndMotor;
    QWidget *w_para_motor;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *gb_par_motor;
    QHBoxLayout *horizontalLayout_14;
    QLabel *lb_mo_X;
    QDoubleSpinBox *dsb_motorRatioX;
    QLabel *lb_mo_X2;
    QSpacerItem *sp_mo_1;
    QLabel *lb_mo_Y;
    QDoubleSpinBox *dsb_motorRatioY;
    QLabel *lb_mo_Y2;
    QSpacerItem *sp_mo_2;
    QLabel *lb_mo_Z;
    QDoubleSpinBox *dsb_motorRatioZ;
    QLabel *lb_mo_Z2;
    QGroupBox *gb_para_up;
    QHBoxLayout *horizontalLayout_15;
    QLabel *sp_up_X;
    QSpinBox *sb_marginX;
    QLabel *lb_up_X2;
    QSpacerItem *sp_up_1;
    QLabel *lb_up_Y;
    QSpinBox *sb_marginY;
    QLabel *lb_up_Y2;
    QSpacerItem *sp_up_2;
    QLabel *lb_up_Z;
    QSpinBox *sb_marginZ;
    QLabel *lb_up_Z2;
    QGroupBox *gb_para_s0;
    QHBoxLayout *horizontalLayout_16;
    QLabel *lb_s0_X;
    QDoubleSpinBox *dsb_initOffsetX;
    QLabel *lb_s0_X2;
    QSpacerItem *sp_s0_1;
    QLabel *lb_s0_Y;
    QDoubleSpinBox *dsb_initOffsetY;
    QLabel *lb_s0_Y2;
    QSpacerItem *sp_s0_2;
    QLabel *lb_s0_Z;
    QDoubleSpinBox *dsb_initOffsetZ;
    QLabel *lb_s0_Z2;
    QGroupBox *gb_para_speed_v0;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *ly_para_speed_v0;
    QLabel *lb_sp_v0;
    QSpacerItem *sp_sp_v0_3;
    QLabel *lb_sp_v0_X;
    QSpinBox *sb_startSpeedX;
    QSpacerItem *sp_sp_v0_1;
    QLabel *lb_sp_v0_Y;
    QSpinBox *sb_startSpeedY;
    QSpacerItem *sp_sp_v0_2;
    QLabel *lb_sp_v0_Z;
    QSpinBox *sb_startSpeedZ;
    QHBoxLayout *ly_para_speed_v;
    QLabel *lb_sp_v;
    QSpacerItem *sp_sp_v0_4;
    QLabel *lb_sp_v_X;
    QSpinBox *sb_runSpeedX;
    QSpacerItem *sp_sp_v_1;
    QLabel *lb_sp_v_Y;
    QSpinBox *sb_runSpeedY;
    QSpacerItem *sp_sp_v_2;
    QLabel *lb_sp_v_Z;
    QSpinBox *sb_runSpeedZ;
    QHBoxLayout *ly_para_sp_acc;
    QLabel *lb_sp_a;
    QSpacerItem *sp_sp_v0_5;
    QLabel *lb_sp_a_X;
    QSpinBox *sb_motorAccX;
    QSpacerItem *sp_sp_a_1;
    QLabel *lb_sp_a_Y;
    QSpinBox *sb_motorAccY;
    QSpacerItem *sp_sp_a_2;
    QLabel *lb_sp_a_Z;
    QSpinBox *sb_motorAccZ;
    QGroupBox *gb_para_plat;
    QGridLayout *gridLayout_7;
    QCheckBox *cb_sphereMachine;
    QCheckBox *cb_reverseScannerXY;
    QCheckBox *cb_reverseXDir;
    QCheckBox *cb_reverseZDir;
    QCheckBox *cb_reverseScannerZ;
    QCheckBox *cb_reverseYDir;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *sp_para_btn2;
    QPushButton *pb_setDefaultParam;
    QPushButton *pb_getDefaultParam;
    QSpacerItem *sp_para_btn1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ParaWindow)
    {
        if (ParaWindow->objectName().isEmpty())
            ParaWindow->setObjectName(QStringLiteral("ParaWindow"));
        ParaWindow->setWindowModality(Qt::NonModal);
        ParaWindow->resize(1171, 936);
        ParaWindow->setContextMenuPolicy(Qt::NoContextMenu);
        w_para_btn = new QWidget(ParaWindow);
        w_para_btn->setObjectName(QStringLiteral("w_para_btn"));
        w_para_btn->setGeometry(QRect(10, 10, 100, 450));
        w_para_btn->setMinimumSize(QSize(100, 0));
        w_para_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        verticalLayout = new QVBoxLayout(w_para_btn);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pb_sortingMethod = new QPushButton(w_para_btn);
        pb_sortingMethod->setObjectName(QStringLiteral("pb_sortingMethod"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_sortingMethod->sizePolicy().hasHeightForWidth());
        pb_sortingMethod->setSizePolicy(sizePolicy);
        pb_sortingMethod->setStyleSheet(QStringLiteral("border-image: url(:/prefix/resource/sort.png);"));
        pb_sortingMethod->setIconSize(QSize(16, 16));
        pb_sortingMethod->setAutoExclusive(true);

        verticalLayout->addWidget(pb_sortingMethod);

        lb_para_sort = new QLabel(w_para_btn);
        lb_para_sort->setObjectName(QStringLiteral("lb_para_sort"));
        lb_para_sort->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_para_sort);

        pb_laserAndScanner = new QPushButton(w_para_btn);
        pb_laserAndScanner->setObjectName(QStringLiteral("pb_laserAndScanner"));
        sizePolicy.setHeightForWidth(pb_laserAndScanner->sizePolicy().hasHeightForWidth());
        pb_laserAndScanner->setSizePolicy(sizePolicy);
        pb_laserAndScanner->setStyleSheet(QStringLiteral("border-image: url(:/prefix/resource/scan.png);"));

        verticalLayout->addWidget(pb_laserAndScanner);

        lb_para_scan = new QLabel(w_para_btn);
        lb_para_scan->setObjectName(QStringLiteral("lb_para_scan"));
        lb_para_scan->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_para_scan);

        pb_PlatformMotor = new QPushButton(w_para_btn);
        pb_PlatformMotor->setObjectName(QStringLiteral("pb_PlatformMotor"));
        sizePolicy.setHeightForWidth(pb_PlatformMotor->sizePolicy().hasHeightForWidth());
        pb_PlatformMotor->setSizePolicy(sizePolicy);
        pb_PlatformMotor->setStyleSheet(QStringLiteral("border-image: url(:/prefix/resource/motor.png);"));

        verticalLayout->addWidget(pb_PlatformMotor);

        lb_para_motor = new QLabel(w_para_btn);
        lb_para_motor->setObjectName(QStringLiteral("lb_para_motor"));
        lb_para_motor->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_para_motor);

        sa_sortingMethod = new QScrollArea(ParaWindow);
        sa_sortingMethod->setObjectName(QStringLiteral("sa_sortingMethod"));
        sa_sortingMethod->setGeometry(QRect(640, 10, 511, 450));
        sa_sortingMethod->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sa_sortingMethod->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sa_sortingMethod->setWidgetResizable(true);
        w_para_sort = new QWidget();
        w_para_sort->setObjectName(QStringLiteral("w_para_sort"));
        w_para_sort->setGeometry(QRect(0, 0, 518, 448));
        verticalLayout_2 = new QVBoxLayout(w_para_sort);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        gb_para_crystal = new QGroupBox(w_para_sort);
        gb_para_crystal->setObjectName(QStringLiteral("gb_para_crystal"));
        gb_para_crystal->setMaximumSize(QSize(16777215, 60));
        gb_para_crystal->setStyleSheet(QStringLiteral(""));
        horizontalLayout_26 = new QHBoxLayout(gb_para_crystal);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        lb_para_c_w = new QLabel(gb_para_crystal);
        lb_para_c_w->setObjectName(QStringLiteral("lb_para_c_w"));

        horizontalLayout_26->addWidget(lb_para_c_w);

        dsb_crystalSizeX = new QDoubleSpinBox(gb_para_crystal);
        dsb_crystalSizeX->setObjectName(QStringLiteral("dsb_crystalSizeX"));
        dsb_crystalSizeX->setEnabled(true);
        dsb_crystalSizeX->setDecimals(1);
        dsb_crystalSizeX->setMaximum(9999);
        dsb_crystalSizeX->setValue(60);

        horizontalLayout_26->addWidget(dsb_crystalSizeX);

        lb_para_c_w2 = new QLabel(gb_para_crystal);
        lb_para_c_w2->setObjectName(QStringLiteral("lb_para_c_w2"));

        horizontalLayout_26->addWidget(lb_para_c_w2);

        lb_para_c_l = new QLabel(gb_para_crystal);
        lb_para_c_l->setObjectName(QStringLiteral("lb_para_c_l"));

        horizontalLayout_26->addWidget(lb_para_c_l);

        dsb_crystalSizeY = new QDoubleSpinBox(gb_para_crystal);
        dsb_crystalSizeY->setObjectName(QStringLiteral("dsb_crystalSizeY"));
        dsb_crystalSizeY->setEnabled(true);
        dsb_crystalSizeY->setDecimals(1);
        dsb_crystalSizeY->setMaximum(9999);
        dsb_crystalSizeY->setValue(60);

        horizontalLayout_26->addWidget(dsb_crystalSizeY);

        lb_para_c_l2 = new QLabel(gb_para_crystal);
        lb_para_c_l2->setObjectName(QStringLiteral("lb_para_c_l2"));

        horizontalLayout_26->addWidget(lb_para_c_l2);

        lb_para_c_h = new QLabel(gb_para_crystal);
        lb_para_c_h->setObjectName(QStringLiteral("lb_para_c_h"));

        horizontalLayout_26->addWidget(lb_para_c_h);

        dsb_crystalSizeZ = new QDoubleSpinBox(gb_para_crystal);
        dsb_crystalSizeZ->setObjectName(QStringLiteral("dsb_crystalSizeZ"));
        dsb_crystalSizeZ->setEnabled(true);
        dsb_crystalSizeZ->setDecimals(1);
        dsb_crystalSizeZ->setMaximum(9999);
        dsb_crystalSizeZ->setValue(60);

        horizontalLayout_26->addWidget(dsb_crystalSizeZ);

        lb_para_c_h2 = new QLabel(gb_para_crystal);
        lb_para_c_h2->setObjectName(QStringLiteral("lb_para_c_h2"));

        horizontalLayout_26->addWidget(lb_para_c_h2);


        verticalLayout_2->addWidget(gb_para_crystal);

        ly_para_s_m = new QHBoxLayout();
        ly_para_s_m->setObjectName(QStringLiteral("ly_para_s_m"));
        gb_para_s = new QGroupBox(w_para_sort);
        gb_para_s->setObjectName(QStringLiteral("gb_para_s"));
        verticalLayout_25 = new QVBoxLayout(gb_para_s);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        ly_para_s = new QVBoxLayout();
        ly_para_s->setObjectName(QStringLiteral("ly_para_s"));
        rb_squenceY2X = new QRadioButton(gb_para_s);
        rb_squenceY2X->setObjectName(QStringLiteral("rb_squenceY2X"));

        ly_para_s->addWidget(rb_squenceY2X);

        rb_squenceX2Y = new QRadioButton(gb_para_s);
        rb_squenceX2Y->setObjectName(QStringLiteral("rb_squenceX2Y"));

        ly_para_s->addWidget(rb_squenceX2Y);

        rb_ShortestPath = new QRadioButton(gb_para_s);
        rb_ShortestPath->setObjectName(QStringLiteral("rb_ShortestPath"));
        rb_ShortestPath->setChecked(true);

        ly_para_s->addWidget(rb_ShortestPath);


        verticalLayout_25->addLayout(ly_para_s);

        ly_para_s_2 = new QGridLayout();
        ly_para_s_2->setObjectName(QStringLiteral("ly_para_s_2"));
        lb_para_w = new QLabel(gb_para_s);
        lb_para_w->setObjectName(QStringLiteral("lb_para_w"));

        ly_para_s_2->addWidget(lb_para_w, 0, 0, 1, 1);

        lb_para_w2 = new QLabel(gb_para_s);
        lb_para_w2->setObjectName(QStringLiteral("lb_para_w2"));

        ly_para_s_2->addWidget(lb_para_w2, 0, 2, 1, 1);

        lb_para_r = new QLabel(gb_para_s);
        lb_para_r->setObjectName(QStringLiteral("lb_para_r"));

        ly_para_s_2->addWidget(lb_para_r, 1, 0, 1, 1);

        lb_para_r2 = new QLabel(gb_para_s);
        lb_para_r2->setObjectName(QStringLiteral("lb_para_r2"));

        ly_para_s_2->addWidget(lb_para_r2, 1, 2, 1, 1);

        dsb_blockWidth = new QDoubleSpinBox(gb_para_s);
        dsb_blockWidth->setObjectName(QStringLiteral("dsb_blockWidth"));
        dsb_blockWidth->setEnabled(true);
        dsb_blockWidth->setDecimals(2);
        dsb_blockWidth->setMaximum(9999);
        dsb_blockWidth->setValue(1);

        ly_para_s_2->addWidget(dsb_blockWidth, 0, 1, 1, 1);

        dsb_boundaryDisable = new QDoubleSpinBox(gb_para_s);
        dsb_boundaryDisable->setObjectName(QStringLiteral("dsb_boundaryDisable"));
        dsb_boundaryDisable->setEnabled(true);
        dsb_boundaryDisable->setDecimals(1);
        dsb_boundaryDisable->setMaximum(100);
        dsb_boundaryDisable->setValue(0.1);

        ly_para_s_2->addWidget(dsb_boundaryDisable, 1, 1, 1, 1);


        verticalLayout_25->addLayout(ly_para_s_2);


        ly_para_s_m->addWidget(gb_para_s);

        gb_para_m = new QGroupBox(w_para_sort);
        gb_para_m->setObjectName(QStringLiteral("gb_para_m"));
        verticalLayout_26 = new QVBoxLayout(gb_para_m);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        ly_min_layer = new QHBoxLayout();
        ly_min_layer->setObjectName(QStringLiteral("ly_min_layer"));
        lb_min_layer = new QLabel(gb_para_m);
        lb_min_layer->setObjectName(QStringLiteral("lb_min_layer"));

        ly_min_layer->addWidget(lb_min_layer);

        dsb_minLayerDis = new QDoubleSpinBox(gb_para_m);
        dsb_minLayerDis->setObjectName(QStringLiteral("dsb_minLayerDis"));
        dsb_minLayerDis->setEnabled(true);
        dsb_minLayerDis->setDecimals(3);
        dsb_minLayerDis->setMaximum(999);
        dsb_minLayerDis->setSingleStep(0.1);
        dsb_minLayerDis->setValue(0.088);

        ly_min_layer->addWidget(dsb_minLayerDis);

        lb_min_layer2 = new QLabel(gb_para_m);
        lb_min_layer2->setObjectName(QStringLiteral("lb_min_layer2"));

        ly_min_layer->addWidget(lb_min_layer2);

        sp_m_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_min_layer->addItem(sp_m_1);


        verticalLayout_26->addLayout(ly_min_layer);

        ly_para_m_correct = new QGridLayout();
        ly_para_m_correct->setObjectName(QStringLiteral("ly_para_m_correct"));
        sp_m_correct1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct1, 4, 0, 1, 1);

        rb_YXCorrect = new QRadioButton(gb_para_m);
        rb_YXCorrect->setObjectName(QStringLiteral("rb_YXCorrect"));

        ly_para_m_correct->addWidget(rb_YXCorrect, 4, 1, 1, 1);

        rb_XYCorrect = new QRadioButton(gb_para_m);
        rb_XYCorrect->setObjectName(QStringLiteral("rb_XYCorrect"));

        ly_para_m_correct->addWidget(rb_XYCorrect, 3, 1, 1, 1);

        rb_noneCorrect = new QRadioButton(gb_para_m);
        rb_noneCorrect->setObjectName(QStringLiteral("rb_noneCorrect"));

        ly_para_m_correct->addWidget(rb_noneCorrect, 2, 1, 1, 1);

        sp_m_correct2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct2, 2, 0, 1, 1);

        sp_m_correct3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct3, 3, 0, 1, 1);

        lb_m_correct = new QLabel(gb_para_m);
        lb_m_correct->setObjectName(QStringLiteral("lb_m_correct"));

        ly_para_m_correct->addWidget(lb_m_correct, 1, 0, 1, 1);

        sp_m_correct4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct4, 1, 1, 1, 1);

        sp_m_correct5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct5, 1, 2, 1, 1);

        sp_m_correct6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct6, 2, 2, 1, 1);

        sp_m_correct7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct7, 4, 2, 1, 1);

        sp_m_correct8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_m_correct->addItem(sp_m_correct8, 3, 2, 1, 1);


        verticalLayout_26->addLayout(ly_para_m_correct);


        ly_para_s_m->addWidget(gb_para_m);


        verticalLayout_2->addLayout(ly_para_s_m);

        gb_para_split = new QGroupBox(w_para_sort);
        gb_para_split->setObjectName(QStringLiteral("gb_para_split"));
        verticalLayout_4 = new QVBoxLayout(gb_para_split);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        ly_split_border = new QHBoxLayout();
        ly_split_border->setObjectName(QStringLiteral("ly_split_border"));
        lb_split_border = new QLabel(gb_para_split);
        lb_split_border->setObjectName(QStringLiteral("lb_split_border"));

        ly_split_border->addWidget(lb_split_border);

        rb_verticalBorder = new QRadioButton(gb_para_split);
        rb_verticalBorder->setObjectName(QStringLiteral("rb_verticalBorder"));

        ly_split_border->addWidget(rb_verticalBorder);

        rb_inclinedBorder = new QRadioButton(gb_para_split);
        rb_inclinedBorder->setObjectName(QStringLiteral("rb_inclinedBorder"));

        ly_split_border->addWidget(rb_inclinedBorder);

        sp_split_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_split_border->addItem(sp_split_1);


        verticalLayout_4->addLayout(ly_split_border);

        ly_split_size = new QHBoxLayout();
        ly_split_size->setObjectName(QStringLiteral("ly_split_size"));
        lb_split_size = new QLabel(gb_para_split);
        lb_split_size->setObjectName(QStringLiteral("lb_split_size"));

        ly_split_size->addWidget(lb_split_size);

        lb_split_size_X = new QLabel(gb_para_split);
        lb_split_size_X->setObjectName(QStringLiteral("lb_split_size_X"));

        ly_split_size->addWidget(lb_split_size_X);

        dsb_blockSizeX = new QDoubleSpinBox(gb_para_split);
        dsb_blockSizeX->setObjectName(QStringLiteral("dsb_blockSizeX"));
        dsb_blockSizeX->setEnabled(true);
        dsb_blockSizeX->setDecimals(2);
        dsb_blockSizeX->setMaximum(999);
        dsb_blockSizeX->setValue(25);

        ly_split_size->addWidget(dsb_blockSizeX);

        lb_split_size_X2 = new QLabel(gb_para_split);
        lb_split_size_X2->setObjectName(QStringLiteral("lb_split_size_X2"));

        ly_split_size->addWidget(lb_split_size_X2);

        lb_split_size_Y = new QLabel(gb_para_split);
        lb_split_size_Y->setObjectName(QStringLiteral("lb_split_size_Y"));

        ly_split_size->addWidget(lb_split_size_Y);

        dsb_blockSizeY = new QDoubleSpinBox(gb_para_split);
        dsb_blockSizeY->setObjectName(QStringLiteral("dsb_blockSizeY"));
        dsb_blockSizeY->setEnabled(true);
        dsb_blockSizeY->setDecimals(2);
        dsb_blockSizeY->setMaximum(999);
        dsb_blockSizeY->setValue(25);

        ly_split_size->addWidget(dsb_blockSizeY);

        lb_split_size_Y2 = new QLabel(gb_para_split);
        lb_split_size_Y2->setObjectName(QStringLiteral("lb_split_size_Y2"));

        ly_split_size->addWidget(lb_split_size_Y2);

        lb_split_size_Z = new QLabel(gb_para_split);
        lb_split_size_Z->setObjectName(QStringLiteral("lb_split_size_Z"));

        ly_split_size->addWidget(lb_split_size_Z);

        dsb_blockSizeZ = new QDoubleSpinBox(gb_para_split);
        dsb_blockSizeZ->setObjectName(QStringLiteral("dsb_blockSizeZ"));
        dsb_blockSizeZ->setEnabled(false);
        dsb_blockSizeZ->setDecimals(2);
        dsb_blockSizeZ->setMaximum(999);
        dsb_blockSizeZ->setValue(0.1);

        ly_split_size->addWidget(dsb_blockSizeZ);

        lb_split_size_Z2 = new QLabel(gb_para_split);
        lb_split_size_Z2->setObjectName(QStringLiteral("lb_split_size_Z2"));

        ly_split_size->addWidget(lb_split_size_Z2);

        sp_split_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_split_size->addItem(sp_split_2);


        verticalLayout_4->addLayout(ly_split_size);

        ly_split_border_para = new QHBoxLayout();
        ly_split_border_para->setObjectName(QStringLiteral("ly_split_border_para"));
        lb_split_border_para = new QLabel(gb_para_split);
        lb_split_border_para->setObjectName(QStringLiteral("lb_split_border_para"));

        ly_split_border_para->addWidget(lb_split_border_para);

        lb_border_w = new QLabel(gb_para_split);
        lb_border_w->setObjectName(QStringLiteral("lb_border_w"));

        ly_split_border_para->addWidget(lb_border_w);

        dsb_borderWidth = new QDoubleSpinBox(gb_para_split);
        dsb_borderWidth->setObjectName(QStringLiteral("dsb_borderWidth"));
        dsb_borderWidth->setEnabled(true);
        dsb_borderWidth->setDecimals(1);
        dsb_borderWidth->setMaximum(999);
        dsb_borderWidth->setValue(3);

        ly_split_border_para->addWidget(dsb_borderWidth);

        lb_border_w2 = new QLabel(gb_para_split);
        lb_border_w2->setObjectName(QStringLiteral("lb_border_w2"));

        ly_split_border_para->addWidget(lb_border_w2);

        lb_border_a = new QLabel(gb_para_split);
        lb_border_a->setObjectName(QStringLiteral("lb_border_a"));

        ly_split_border_para->addWidget(lb_border_a);

        dsb_borderAngle = new QDoubleSpinBox(gb_para_split);
        dsb_borderAngle->setObjectName(QStringLiteral("dsb_borderAngle"));
        dsb_borderAngle->setEnabled(true);
        dsb_borderAngle->setDecimals(1);
        dsb_borderAngle->setMaximum(999);
        dsb_borderAngle->setValue(5);

        ly_split_border_para->addWidget(dsb_borderAngle);

        lb_border_a2 = new QLabel(gb_para_split);
        lb_border_a2->setObjectName(QStringLiteral("lb_border_a2"));

        ly_split_border_para->addWidget(lb_border_a2);

        sp_split_border1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_split_border_para->addItem(sp_split_border1);


        verticalLayout_4->addLayout(ly_split_border_para);


        verticalLayout_2->addWidget(gb_para_split);

        sa_sortingMethod->setWidget(w_para_sort);
        sa_laserAndScanner = new QScrollArea(ParaWindow);
        sa_laserAndScanner->setObjectName(QStringLiteral("sa_laserAndScanner"));
        sa_laserAndScanner->setGeometry(QRect(640, 470, 511, 450));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sa_laserAndScanner->sizePolicy().hasHeightForWidth());
        sa_laserAndScanner->setSizePolicy(sizePolicy1);
        sa_laserAndScanner->setMaximumSize(QSize(511, 450));
        sa_laserAndScanner->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sa_laserAndScanner->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sa_laserAndScanner->setWidgetResizable(true);
        w_para_laser = new QWidget();
        w_para_laser->setObjectName(QStringLiteral("w_para_laser"));
        w_para_laser->setGeometry(QRect(0, 0, 509, 448));
        verticalLayout_3 = new QVBoxLayout(w_para_laser);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 0, 9, 9);
        gb_la_test = new QGroupBox(w_para_laser);
        gb_la_test->setObjectName(QStringLiteral("gb_la_test"));
        horizontalLayout_3 = new QHBoxLayout(gb_la_test);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        w_laser_pulse = new QWidget(gb_la_test);
        w_laser_pulse->setObjectName(QStringLiteral("w_laser_pulse"));
        w_laser_pulse->setStyleSheet(QStringLiteral("background-color: rgb(200, 200, 200);"));
        lb_laser_pulse_title = new QLabel(w_laser_pulse);
        lb_laser_pulse_title->setObjectName(QStringLiteral("lb_laser_pulse_title"));
        lb_laser_pulse_title->setGeometry(QRect(80, 0, 101, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lb_laser_pulse_title->setFont(font);
        lb_laser_pulse_title->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        lb_highPulseTime = new QLabel(w_laser_pulse);
        lb_highPulseTime->setObjectName(QStringLiteral("lb_highPulseTime"));
        lb_highPulseTime->setGeometry(QRect(20, 10, 41, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lb_highPulseTime->setFont(font1);
        lb_highPulseTime->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        lb_lwoPulseTime = new QLabel(w_laser_pulse);
        lb_lwoPulseTime->setObjectName(QStringLiteral("lb_lwoPulseTime"));
        lb_lwoPulseTime->setEnabled(true);
        lb_lwoPulseTime->setGeometry(QRect(200, 50, 41, 16));
        lb_lwoPulseTime->setFont(font1);
        lb_lwoPulseTime->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        horizontalLayout_3->addWidget(w_laser_pulse);

        ly_la_test_r_f = new QVBoxLayout();
        ly_la_test_r_f->setSpacing(2);
        ly_la_test_r_f->setObjectName(QStringLiteral("ly_la_test_r_f"));
        ly_test_r = new QHBoxLayout();
        ly_test_r->setObjectName(QStringLiteral("ly_test_r"));
        lb_test_r = new QLabel(gb_la_test);
        lb_test_r->setObjectName(QStringLiteral("lb_test_r"));

        ly_test_r->addWidget(lb_test_r);

        lb_laserRatio = new QLabel(gb_la_test);
        lb_laserRatio->setObjectName(QStringLiteral("lb_laserRatio"));
        lb_laserRatio->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        ly_test_r->addWidget(lb_laserRatio);

        lb_laser_r_v_2 = new QLabel(gb_la_test);
        lb_laser_r_v_2->setObjectName(QStringLiteral("lb_laser_r_v_2"));

        ly_test_r->addWidget(lb_laser_r_v_2);


        ly_la_test_r_f->addLayout(ly_test_r);

        s_laserRatio = new QSlider(gb_la_test);
        s_laserRatio->setObjectName(QStringLiteral("s_laserRatio"));
        s_laserRatio->setMaximum(100);
        s_laserRatio->setValue(30);
        s_laserRatio->setSliderPosition(30);
        s_laserRatio->setOrientation(Qt::Horizontal);
        s_laserRatio->setTickPosition(QSlider::NoTicks);
        s_laserRatio->setTickInterval(0);

        ly_la_test_r_f->addWidget(s_laserRatio);

        ly_test_f = new QHBoxLayout();
        ly_test_f->setObjectName(QStringLiteral("ly_test_f"));
        lb_test_f = new QLabel(gb_la_test);
        lb_test_f->setObjectName(QStringLiteral("lb_test_f"));

        ly_test_f->addWidget(lb_test_f);

        lb_laserFrequency = new QLabel(gb_la_test);
        lb_laserFrequency->setObjectName(QStringLiteral("lb_laserFrequency"));
        lb_laserFrequency->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        ly_test_f->addWidget(lb_laserFrequency);

        lb_test_f2 = new QLabel(gb_la_test);
        lb_test_f2->setObjectName(QStringLiteral("lb_test_f2"));

        ly_test_f->addWidget(lb_test_f2);


        ly_la_test_r_f->addLayout(ly_test_f);

        s_laserFrequency = new QSlider(gb_la_test);
        s_laserFrequency->setObjectName(QStringLiteral("s_laserFrequency"));
        s_laserFrequency->setMinimum(500);
        s_laserFrequency->setMaximum(5000);
        s_laserFrequency->setPageStep(100);
        s_laserFrequency->setValue(3000);
        s_laserFrequency->setOrientation(Qt::Horizontal);

        ly_la_test_r_f->addWidget(s_laserFrequency);


        horizontalLayout_3->addLayout(ly_la_test_r_f);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout_3->addWidget(gb_la_test);

        gb_la_set = new QGroupBox(w_para_laser);
        gb_la_set->setObjectName(QStringLiteral("gb_la_set"));
        verticalLayout_5 = new QVBoxLayout(gb_la_set);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(9, -1, 9, -1);
        ly_la_set_t = new QHBoxLayout();
        ly_la_set_t->setSpacing(2);
        ly_la_set_t->setObjectName(QStringLiteral("ly_la_set_t"));
        ly_la_set_l = new QGridLayout();
        ly_la_set_l->setObjectName(QStringLiteral("ly_la_set_l"));
        lb_set_lpoint2 = new QLabel(gb_la_set);
        lb_set_lpoint2->setObjectName(QStringLiteral("lb_set_lpoint2"));

        ly_la_set_l->addWidget(lb_set_lpoint2, 0, 2, 1, 1);

        lb_set_lpoint = new QLabel(gb_la_set);
        lb_set_lpoint->setObjectName(QStringLiteral("lb_set_lpoint"));
        sizePolicy1.setHeightForWidth(lb_set_lpoint->sizePolicy().hasHeightForWidth());
        lb_set_lpoint->setSizePolicy(sizePolicy1);

        ly_la_set_l->addWidget(lb_set_lpoint, 0, 0, 1, 1);

        lb_set_ltime2 = new QLabel(gb_la_set);
        lb_set_ltime2->setObjectName(QStringLiteral("lb_set_ltime2"));

        ly_la_set_l->addWidget(lb_set_ltime2, 1, 2, 1, 1);

        lb_set_ldelay = new QLabel(gb_la_set);
        lb_set_ldelay->setObjectName(QStringLiteral("lb_set_ldelay"));
        sizePolicy1.setHeightForWidth(lb_set_ldelay->sizePolicy().hasHeightForWidth());
        lb_set_ldelay->setSizePolicy(sizePolicy1);

        ly_la_set_l->addWidget(lb_set_ldelay, 2, 0, 1, 1);

        lb_set_ltime = new QLabel(gb_la_set);
        lb_set_ltime->setObjectName(QStringLiteral("lb_set_ltime"));
        sizePolicy1.setHeightForWidth(lb_set_ltime->sizePolicy().hasHeightForWidth());
        lb_set_ltime->setSizePolicy(sizePolicy1);

        ly_la_set_l->addWidget(lb_set_ltime, 1, 0, 1, 1);

        lb_set_ldelay2 = new QLabel(gb_la_set);
        lb_set_ldelay2->setObjectName(QStringLiteral("lb_set_ldelay2"));

        ly_la_set_l->addWidget(lb_set_ldelay2, 2, 2, 1, 1);

        dsb_focalLength = new QDoubleSpinBox(gb_la_set);
        dsb_focalLength->setObjectName(QStringLiteral("dsb_focalLength"));
        dsb_focalLength->setEnabled(true);
        dsb_focalLength->setDecimals(1);
        dsb_focalLength->setMaximum(999);
        dsb_focalLength->setValue(120);

        ly_la_set_l->addWidget(dsb_focalLength, 0, 1, 1, 1);

        sb_laserSimmerTime = new QSpinBox(gb_la_set);
        sb_laserSimmerTime->setObjectName(QStringLiteral("sb_laserSimmerTime"));
        sb_laserSimmerTime->setEnabled(false);
        sb_laserSimmerTime->setMaximum(999999);
        sb_laserSimmerTime->setValue(0);

        ly_la_set_l->addWidget(sb_laserSimmerTime, 1, 1, 1, 1);

        sb_laserDelay = new QSpinBox(gb_la_set);
        sb_laserDelay->setObjectName(QStringLiteral("sb_laserDelay"));
        sb_laserDelay->setEnabled(true);
        sb_laserDelay->setMaximum(999999);
        sb_laserDelay->setValue(205);

        ly_la_set_l->addWidget(sb_laserDelay, 2, 1, 1, 1);


        ly_la_set_t->addLayout(ly_la_set_l);

        ly_la_set_r = new QGridLayout();
        ly_la_set_r->setObjectName(QStringLiteral("ly_la_set_r"));
        lb_set_sdelay = new QLabel(gb_la_set);
        lb_set_sdelay->setObjectName(QStringLiteral("lb_set_sdelay"));
        sizePolicy1.setHeightForWidth(lb_set_sdelay->sizePolicy().hasHeightForWidth());
        lb_set_sdelay->setSizePolicy(sizePolicy1);

        ly_la_set_r->addWidget(lb_set_sdelay, 0, 0, 1, 1);

        lb_set_sdelay2 = new QLabel(gb_la_set);
        lb_set_sdelay2->setObjectName(QStringLiteral("lb_set_sdelay2"));

        ly_la_set_r->addWidget(lb_set_sdelay2, 0, 2, 1, 1);

        lb_set_sv = new QLabel(gb_la_set);
        lb_set_sv->setObjectName(QStringLiteral("lb_set_sv"));
        sizePolicy1.setHeightForWidth(lb_set_sv->sizePolicy().hasHeightForWidth());
        lb_set_sv->setSizePolicy(sizePolicy1);

        ly_la_set_r->addWidget(lb_set_sv, 1, 0, 1, 1);

        lb_set_sv2 = new QLabel(gb_la_set);
        lb_set_sv2->setObjectName(QStringLiteral("lb_set_sv2"));

        ly_la_set_r->addWidget(lb_set_sv2, 1, 2, 1, 1);

        lb_set_udelay = new QLabel(gb_la_set);
        lb_set_udelay->setObjectName(QStringLiteral("lb_set_udelay"));
        sizePolicy1.setHeightForWidth(lb_set_udelay->sizePolicy().hasHeightForWidth());
        lb_set_udelay->setSizePolicy(sizePolicy1);

        ly_la_set_r->addWidget(lb_set_udelay, 2, 0, 1, 1);

        lb_set_udelay2 = new QLabel(gb_la_set);
        lb_set_udelay2->setObjectName(QStringLiteral("lb_set_udelay2"));

        ly_la_set_r->addWidget(lb_set_udelay2, 2, 2, 1, 1);

        sb_scannerDelay = new QSpinBox(gb_la_set);
        sb_scannerDelay->setObjectName(QStringLiteral("sb_scannerDelay"));
        sb_scannerDelay->setEnabled(true);
        sb_scannerDelay->setMaximum(999999);
        sb_scannerDelay->setValue(500);

        ly_la_set_r->addWidget(sb_scannerDelay, 0, 1, 1, 1);

        sb_scannerSpeed = new QSpinBox(gb_la_set);
        sb_scannerSpeed->setObjectName(QStringLiteral("sb_scannerSpeed"));
        sb_scannerSpeed->setEnabled(false);
        sb_scannerSpeed->setMaximum(9999999);
        sb_scannerSpeed->setValue(4130);

        ly_la_set_r->addWidget(sb_scannerSpeed, 1, 1, 1, 1);

        sb_microStepDelay = new QSpinBox(gb_la_set);
        sb_microStepDelay->setObjectName(QStringLiteral("sb_microStepDelay"));
        sb_microStepDelay->setEnabled(false);
        sb_microStepDelay->setMaximum(999999);
        sb_microStepDelay->setValue(10);

        ly_la_set_r->addWidget(sb_microStepDelay, 2, 1, 1, 1);


        ly_la_set_t->addLayout(ly_la_set_r);


        verticalLayout_5->addLayout(ly_la_set_t);

        ly_la_set_b = new QHBoxLayout();
        ly_la_set_b->setObjectName(QStringLiteral("ly_la_set_b"));
        cb_exchangeXYScanner = new QCheckBox(gb_la_set);
        cb_exchangeXYScanner->setObjectName(QStringLiteral("cb_exchangeXYScanner"));
        cb_exchangeXYScanner->setEnabled(false);

        ly_la_set_b->addWidget(cb_exchangeXYScanner);

        cb_stepOverMicroStep = new QCheckBox(gb_la_set);
        cb_stepOverMicroStep->setObjectName(QStringLiteral("cb_stepOverMicroStep"));
        cb_stepOverMicroStep->setChecked(true);

        ly_la_set_b->addWidget(cb_stepOverMicroStep);


        verticalLayout_5->addLayout(ly_la_set_b);


        verticalLayout_3->addWidget(gb_la_set);

        gb_la_para = new QGroupBox(w_para_laser);
        gb_la_para->setObjectName(QStringLiteral("gb_la_para"));
        gridLayout = new QGridLayout(gb_la_para);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        lb_la_r_X2 = new QLabel(gb_la_para);
        lb_la_r_X2->setObjectName(QStringLiteral("lb_la_r_X2"));

        gridLayout->addWidget(lb_la_r_X2, 0, 2, 1, 1);

        lb_la_r_Y = new QLabel(gb_la_para);
        lb_la_r_Y->setObjectName(QStringLiteral("lb_la_r_Y"));

        gridLayout->addWidget(lb_la_r_Y, 0, 3, 1, 1);

        lb_la_r_X = new QLabel(gb_la_para);
        lb_la_r_X->setObjectName(QStringLiteral("lb_la_r_X"));

        gridLayout->addWidget(lb_la_r_X, 0, 0, 1, 1);

        lb_la_u_Y = new QLabel(gb_la_para);
        lb_la_u_Y->setObjectName(QStringLiteral("lb_la_u_Y"));

        gridLayout->addWidget(lb_la_u_Y, 3, 3, 1, 1);

        lb_la_u_X = new QLabel(gb_la_para);
        lb_la_u_X->setObjectName(QStringLiteral("lb_la_u_X"));

        gridLayout->addWidget(lb_la_u_X, 3, 0, 1, 1);

        lb_la_v_X = new QLabel(gb_la_para);
        lb_la_v_X->setObjectName(QStringLiteral("lb_la_v_X"));

        gridLayout->addWidget(lb_la_v_X, 2, 3, 1, 1);

        lb_la_v_X_2 = new QLabel(gb_la_para);
        lb_la_v_X_2->setObjectName(QStringLiteral("lb_la_v_X_2"));

        gridLayout->addWidget(lb_la_v_X_2, 2, 0, 1, 1);

        lb_la_r_Y2 = new QLabel(gb_la_para);
        lb_la_r_Y2->setObjectName(QStringLiteral("lb_la_r_Y2"));

        gridLayout->addWidget(lb_la_r_Y2, 0, 5, 1, 1);

        dsb_scannerRatioX = new QDoubleSpinBox(gb_la_para);
        dsb_scannerRatioX->setObjectName(QStringLiteral("dsb_scannerRatioX"));
        dsb_scannerRatioX->setEnabled(false);
        dsb_scannerRatioX->setDecimals(2);
        dsb_scannerRatioX->setMinimum(-9999);
        dsb_scannerRatioX->setMaximum(9999);
        dsb_scannerRatioX->setValue(-172.34);

        gridLayout->addWidget(dsb_scannerRatioX, 0, 1, 1, 1);

        dsb_scannerRatioY = new QDoubleSpinBox(gb_la_para);
        dsb_scannerRatioY->setObjectName(QStringLiteral("dsb_scannerRatioY"));
        dsb_scannerRatioY->setEnabled(false);
        dsb_scannerRatioY->setDecimals(2);
        dsb_scannerRatioY->setMinimum(-9999);
        dsb_scannerRatioY->setMaximum(9999);
        dsb_scannerRatioY->setValue(171.66);

        gridLayout->addWidget(dsb_scannerRatioY, 0, 4, 1, 1);

        dsb_scannerAdjustX = new QDoubleSpinBox(gb_la_para);
        dsb_scannerAdjustX->setObjectName(QStringLiteral("dsb_scannerAdjustX"));
        dsb_scannerAdjustX->setEnabled(false);
        dsb_scannerAdjustX->setDecimals(1);
        dsb_scannerAdjustX->setMinimum(-999);
        dsb_scannerAdjustX->setMaximum(999);
        dsb_scannerAdjustX->setValue(0);

        gridLayout->addWidget(dsb_scannerAdjustX, 2, 1, 1, 1);

        dsb_scannerAdjustY = new QDoubleSpinBox(gb_la_para);
        dsb_scannerAdjustY->setObjectName(QStringLiteral("dsb_scannerAdjustY"));
        dsb_scannerAdjustY->setEnabled(false);
        dsb_scannerAdjustY->setDecimals(1);
        dsb_scannerAdjustY->setMinimum(-999);
        dsb_scannerAdjustY->setMaximum(999);
        dsb_scannerAdjustY->setValue(0);

        gridLayout->addWidget(dsb_scannerAdjustY, 2, 4, 1, 1);

        dsb_scannerPlatformAdjustX = new QDoubleSpinBox(gb_la_para);
        dsb_scannerPlatformAdjustX->setObjectName(QStringLiteral("dsb_scannerPlatformAdjustX"));
        dsb_scannerPlatformAdjustX->setEnabled(false);
        dsb_scannerPlatformAdjustX->setDecimals(1);
        dsb_scannerPlatformAdjustX->setMinimum(-999);
        dsb_scannerPlatformAdjustX->setMaximum(999);
        dsb_scannerPlatformAdjustX->setValue(0);

        gridLayout->addWidget(dsb_scannerPlatformAdjustX, 3, 1, 1, 1);

        dsb_scannerPlatformAdjustY = new QDoubleSpinBox(gb_la_para);
        dsb_scannerPlatformAdjustY->setObjectName(QStringLiteral("dsb_scannerPlatformAdjustY"));
        dsb_scannerPlatformAdjustY->setEnabled(false);
        dsb_scannerPlatformAdjustY->setDecimals(1);
        dsb_scannerPlatformAdjustY->setMinimum(-999);
        dsb_scannerPlatformAdjustY->setMaximum(999);
        dsb_scannerPlatformAdjustY->setValue(0);

        gridLayout->addWidget(dsb_scannerPlatformAdjustY, 3, 4, 1, 1);


        verticalLayout_3->addWidget(gb_la_para);

        gb_la_ctrl = new QGroupBox(w_para_laser);
        gb_la_ctrl->setObjectName(QStringLiteral("gb_la_ctrl"));
        horizontalLayout_4 = new QHBoxLayout(gb_la_ctrl);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        cb_la_r232 = new QCheckBox(gb_la_ctrl);
        cb_la_r232->setObjectName(QStringLiteral("cb_la_r232"));
        cb_la_r232->setEnabled(false);

        horizontalLayout_4->addWidget(cb_la_r232);


        verticalLayout_3->addWidget(gb_la_ctrl);

        sa_laserAndScanner->setWidget(w_para_laser);
        gb_la_test->raise();
        gb_la_para->raise();
        gb_la_ctrl->raise();
        gb_la_set->raise();
        sa_platformAndMotor = new QScrollArea(ParaWindow);
        sa_platformAndMotor->setObjectName(QStringLiteral("sa_platformAndMotor"));
        sa_platformAndMotor->setGeometry(QRect(120, 10, 511, 450));
        sizePolicy1.setHeightForWidth(sa_platformAndMotor->sizePolicy().hasHeightForWidth());
        sa_platformAndMotor->setSizePolicy(sizePolicy1);
        sa_platformAndMotor->setMaximumSize(QSize(511, 450));
        sa_platformAndMotor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sa_platformAndMotor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sa_platformAndMotor->setWidgetResizable(true);
        w_para_motor = new QWidget();
        w_para_motor->setObjectName(QStringLiteral("w_para_motor"));
        w_para_motor->setGeometry(QRect(0, 0, 509, 449));
        verticalLayout_6 = new QVBoxLayout(w_para_motor);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gb_par_motor = new QGroupBox(w_para_motor);
        gb_par_motor->setObjectName(QStringLiteral("gb_par_motor"));
        horizontalLayout_14 = new QHBoxLayout(gb_par_motor);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        lb_mo_X = new QLabel(gb_par_motor);
        lb_mo_X->setObjectName(QStringLiteral("lb_mo_X"));

        horizontalLayout_14->addWidget(lb_mo_X);

        dsb_motorRatioX = new QDoubleSpinBox(gb_par_motor);
        dsb_motorRatioX->setObjectName(QStringLiteral("dsb_motorRatioX"));
        dsb_motorRatioX->setEnabled(false);
        dsb_motorRatioX->setDecimals(1);
        dsb_motorRatioX->setMaximum(9999);
        dsb_motorRatioX->setValue(640);

        horizontalLayout_14->addWidget(dsb_motorRatioX);

        lb_mo_X2 = new QLabel(gb_par_motor);
        lb_mo_X2->setObjectName(QStringLiteral("lb_mo_X2"));

        horizontalLayout_14->addWidget(lb_mo_X2);

        sp_mo_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(sp_mo_1);

        lb_mo_Y = new QLabel(gb_par_motor);
        lb_mo_Y->setObjectName(QStringLiteral("lb_mo_Y"));

        horizontalLayout_14->addWidget(lb_mo_Y);

        dsb_motorRatioY = new QDoubleSpinBox(gb_par_motor);
        dsb_motorRatioY->setObjectName(QStringLiteral("dsb_motorRatioY"));
        dsb_motorRatioY->setEnabled(false);
        dsb_motorRatioY->setDecimals(1);
        dsb_motorRatioY->setMaximum(9999);
        dsb_motorRatioY->setValue(640);

        horizontalLayout_14->addWidget(dsb_motorRatioY);

        lb_mo_Y2 = new QLabel(gb_par_motor);
        lb_mo_Y2->setObjectName(QStringLiteral("lb_mo_Y2"));

        horizontalLayout_14->addWidget(lb_mo_Y2);

        sp_mo_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(sp_mo_2);

        lb_mo_Z = new QLabel(gb_par_motor);
        lb_mo_Z->setObjectName(QStringLiteral("lb_mo_Z"));

        horizontalLayout_14->addWidget(lb_mo_Z);

        dsb_motorRatioZ = new QDoubleSpinBox(gb_par_motor);
        dsb_motorRatioZ->setObjectName(QStringLiteral("dsb_motorRatioZ"));
        dsb_motorRatioZ->setEnabled(false);
        dsb_motorRatioZ->setDecimals(1);
        dsb_motorRatioZ->setMaximum(9999);
        dsb_motorRatioZ->setValue(427);

        horizontalLayout_14->addWidget(dsb_motorRatioZ);

        lb_mo_Z2 = new QLabel(gb_par_motor);
        lb_mo_Z2->setObjectName(QStringLiteral("lb_mo_Z2"));

        horizontalLayout_14->addWidget(lb_mo_Z2);


        verticalLayout_6->addWidget(gb_par_motor);

        gb_para_up = new QGroupBox(w_para_motor);
        gb_para_up->setObjectName(QStringLiteral("gb_para_up"));
        horizontalLayout_15 = new QHBoxLayout(gb_para_up);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        sp_up_X = new QLabel(gb_para_up);
        sp_up_X->setObjectName(QStringLiteral("sp_up_X"));

        horizontalLayout_15->addWidget(sp_up_X);

        sb_marginX = new QSpinBox(gb_para_up);
        sb_marginX->setObjectName(QStringLiteral("sb_marginX"));
        sb_marginX->setEnabled(false);
        sb_marginX->setMaximum(9999);

        horizontalLayout_15->addWidget(sb_marginX);

        lb_up_X2 = new QLabel(gb_para_up);
        lb_up_X2->setObjectName(QStringLiteral("lb_up_X2"));

        horizontalLayout_15->addWidget(lb_up_X2);

        sp_up_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(sp_up_1);

        lb_up_Y = new QLabel(gb_para_up);
        lb_up_Y->setObjectName(QStringLiteral("lb_up_Y"));

        horizontalLayout_15->addWidget(lb_up_Y);

        sb_marginY = new QSpinBox(gb_para_up);
        sb_marginY->setObjectName(QStringLiteral("sb_marginY"));
        sb_marginY->setEnabled(false);
        sb_marginY->setMaximum(9999);

        horizontalLayout_15->addWidget(sb_marginY);

        lb_up_Y2 = new QLabel(gb_para_up);
        lb_up_Y2->setObjectName(QStringLiteral("lb_up_Y2"));

        horizontalLayout_15->addWidget(lb_up_Y2);

        sp_up_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(sp_up_2);

        lb_up_Z = new QLabel(gb_para_up);
        lb_up_Z->setObjectName(QStringLiteral("lb_up_Z"));

        horizontalLayout_15->addWidget(lb_up_Z);

        sb_marginZ = new QSpinBox(gb_para_up);
        sb_marginZ->setObjectName(QStringLiteral("sb_marginZ"));
        sb_marginZ->setEnabled(false);
        sb_marginZ->setMaximum(9999);

        horizontalLayout_15->addWidget(sb_marginZ);

        lb_up_Z2 = new QLabel(gb_para_up);
        lb_up_Z2->setObjectName(QStringLiteral("lb_up_Z2"));

        horizontalLayout_15->addWidget(lb_up_Z2);


        verticalLayout_6->addWidget(gb_para_up);

        gb_para_s0 = new QGroupBox(w_para_motor);
        gb_para_s0->setObjectName(QStringLiteral("gb_para_s0"));
        horizontalLayout_16 = new QHBoxLayout(gb_para_s0);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        lb_s0_X = new QLabel(gb_para_s0);
        lb_s0_X->setObjectName(QStringLiteral("lb_s0_X"));

        horizontalLayout_16->addWidget(lb_s0_X);

        dsb_initOffsetX = new QDoubleSpinBox(gb_para_s0);
        dsb_initOffsetX->setObjectName(QStringLiteral("dsb_initOffsetX"));
        dsb_initOffsetX->setDecimals(1);
        dsb_initOffsetX->setMaximum(9999);
        dsb_initOffsetX->setValue(295);

        horizontalLayout_16->addWidget(dsb_initOffsetX);

        lb_s0_X2 = new QLabel(gb_para_s0);
        lb_s0_X2->setObjectName(QStringLiteral("lb_s0_X2"));

        horizontalLayout_16->addWidget(lb_s0_X2);

        sp_s0_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(sp_s0_1);

        lb_s0_Y = new QLabel(gb_para_s0);
        lb_s0_Y->setObjectName(QStringLiteral("lb_s0_Y"));

        horizontalLayout_16->addWidget(lb_s0_Y);

        dsb_initOffsetY = new QDoubleSpinBox(gb_para_s0);
        dsb_initOffsetY->setObjectName(QStringLiteral("dsb_initOffsetY"));
        dsb_initOffsetY->setDecimals(1);
        dsb_initOffsetY->setMaximum(9999);
        dsb_initOffsetY->setValue(20);

        horizontalLayout_16->addWidget(dsb_initOffsetY);

        lb_s0_Y2 = new QLabel(gb_para_s0);
        lb_s0_Y2->setObjectName(QStringLiteral("lb_s0_Y2"));

        horizontalLayout_16->addWidget(lb_s0_Y2);

        sp_s0_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(sp_s0_2);

        lb_s0_Z = new QLabel(gb_para_s0);
        lb_s0_Z->setObjectName(QStringLiteral("lb_s0_Z"));

        horizontalLayout_16->addWidget(lb_s0_Z);

        dsb_initOffsetZ = new QDoubleSpinBox(gb_para_s0);
        dsb_initOffsetZ->setObjectName(QStringLiteral("dsb_initOffsetZ"));
        dsb_initOffsetZ->setDecimals(1);
        dsb_initOffsetZ->setMaximum(9999);
        dsb_initOffsetZ->setValue(200);

        horizontalLayout_16->addWidget(dsb_initOffsetZ);

        lb_s0_Z2 = new QLabel(gb_para_s0);
        lb_s0_Z2->setObjectName(QStringLiteral("lb_s0_Z2"));

        horizontalLayout_16->addWidget(lb_s0_Z2);


        verticalLayout_6->addWidget(gb_para_s0);

        gb_para_speed_v0 = new QGroupBox(w_para_motor);
        gb_para_speed_v0->setObjectName(QStringLiteral("gb_para_speed_v0"));
        verticalLayout_9 = new QVBoxLayout(gb_para_speed_v0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        ly_para_speed_v0 = new QHBoxLayout();
        ly_para_speed_v0->setObjectName(QStringLiteral("ly_para_speed_v0"));
        lb_sp_v0 = new QLabel(gb_para_speed_v0);
        lb_sp_v0->setObjectName(QStringLiteral("lb_sp_v0"));

        ly_para_speed_v0->addWidget(lb_sp_v0);

        sp_sp_v0_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_speed_v0->addItem(sp_sp_v0_3);

        lb_sp_v0_X = new QLabel(gb_para_speed_v0);
        lb_sp_v0_X->setObjectName(QStringLiteral("lb_sp_v0_X"));

        ly_para_speed_v0->addWidget(lb_sp_v0_X);

        sb_startSpeedX = new QSpinBox(gb_para_speed_v0);
        sb_startSpeedX->setObjectName(QStringLiteral("sb_startSpeedX"));
        sb_startSpeedX->setEnabled(false);
        sb_startSpeedX->setReadOnly(false);
        sb_startSpeedX->setMaximum(99999);
        sb_startSpeedX->setValue(6000);

        ly_para_speed_v0->addWidget(sb_startSpeedX);

        sp_sp_v0_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_speed_v0->addItem(sp_sp_v0_1);

        lb_sp_v0_Y = new QLabel(gb_para_speed_v0);
        lb_sp_v0_Y->setObjectName(QStringLiteral("lb_sp_v0_Y"));

        ly_para_speed_v0->addWidget(lb_sp_v0_Y);

        sb_startSpeedY = new QSpinBox(gb_para_speed_v0);
        sb_startSpeedY->setObjectName(QStringLiteral("sb_startSpeedY"));
        sb_startSpeedY->setEnabled(false);
        sb_startSpeedY->setReadOnly(false);
        sb_startSpeedY->setMaximum(99999);
        sb_startSpeedY->setValue(6000);

        ly_para_speed_v0->addWidget(sb_startSpeedY);

        sp_sp_v0_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_speed_v0->addItem(sp_sp_v0_2);

        lb_sp_v0_Z = new QLabel(gb_para_speed_v0);
        lb_sp_v0_Z->setObjectName(QStringLiteral("lb_sp_v0_Z"));

        ly_para_speed_v0->addWidget(lb_sp_v0_Z);

        sb_startSpeedZ = new QSpinBox(gb_para_speed_v0);
        sb_startSpeedZ->setObjectName(QStringLiteral("sb_startSpeedZ"));
        sb_startSpeedZ->setEnabled(false);
        sb_startSpeedZ->setReadOnly(false);
        sb_startSpeedZ->setMaximum(99999);
        sb_startSpeedZ->setValue(6000);

        ly_para_speed_v0->addWidget(sb_startSpeedZ);


        verticalLayout_9->addLayout(ly_para_speed_v0);

        ly_para_speed_v = new QHBoxLayout();
        ly_para_speed_v->setObjectName(QStringLiteral("ly_para_speed_v"));
        lb_sp_v = new QLabel(gb_para_speed_v0);
        lb_sp_v->setObjectName(QStringLiteral("lb_sp_v"));

        ly_para_speed_v->addWidget(lb_sp_v);

        sp_sp_v0_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_speed_v->addItem(sp_sp_v0_4);

        lb_sp_v_X = new QLabel(gb_para_speed_v0);
        lb_sp_v_X->setObjectName(QStringLiteral("lb_sp_v_X"));

        ly_para_speed_v->addWidget(lb_sp_v_X);

        sb_runSpeedX = new QSpinBox(gb_para_speed_v0);
        sb_runSpeedX->setObjectName(QStringLiteral("sb_runSpeedX"));
        sb_runSpeedX->setEnabled(false);
        sb_runSpeedX->setReadOnly(false);
        sb_runSpeedX->setMaximum(99999);
        sb_runSpeedX->setValue(16000);

        ly_para_speed_v->addWidget(sb_runSpeedX);

        sp_sp_v_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_speed_v->addItem(sp_sp_v_1);

        lb_sp_v_Y = new QLabel(gb_para_speed_v0);
        lb_sp_v_Y->setObjectName(QStringLiteral("lb_sp_v_Y"));

        ly_para_speed_v->addWidget(lb_sp_v_Y);

        sb_runSpeedY = new QSpinBox(gb_para_speed_v0);
        sb_runSpeedY->setObjectName(QStringLiteral("sb_runSpeedY"));
        sb_runSpeedY->setEnabled(false);
        sb_runSpeedY->setReadOnly(false);
        sb_runSpeedY->setMaximum(99999);
        sb_runSpeedY->setValue(19200);

        ly_para_speed_v->addWidget(sb_runSpeedY);

        sp_sp_v_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_speed_v->addItem(sp_sp_v_2);

        lb_sp_v_Z = new QLabel(gb_para_speed_v0);
        lb_sp_v_Z->setObjectName(QStringLiteral("lb_sp_v_Z"));

        ly_para_speed_v->addWidget(lb_sp_v_Z);

        sb_runSpeedZ = new QSpinBox(gb_para_speed_v0);
        sb_runSpeedZ->setObjectName(QStringLiteral("sb_runSpeedZ"));
        sb_runSpeedZ->setEnabled(false);
        sb_runSpeedZ->setReadOnly(false);
        sb_runSpeedZ->setMaximum(99999);
        sb_runSpeedZ->setValue(15000);

        ly_para_speed_v->addWidget(sb_runSpeedZ);


        verticalLayout_9->addLayout(ly_para_speed_v);

        ly_para_sp_acc = new QHBoxLayout();
        ly_para_sp_acc->setObjectName(QStringLiteral("ly_para_sp_acc"));
        lb_sp_a = new QLabel(gb_para_speed_v0);
        lb_sp_a->setObjectName(QStringLiteral("lb_sp_a"));

        ly_para_sp_acc->addWidget(lb_sp_a);

        sp_sp_v0_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_sp_acc->addItem(sp_sp_v0_5);

        lb_sp_a_X = new QLabel(gb_para_speed_v0);
        lb_sp_a_X->setObjectName(QStringLiteral("lb_sp_a_X"));

        ly_para_sp_acc->addWidget(lb_sp_a_X);

        sb_motorAccX = new QSpinBox(gb_para_speed_v0);
        sb_motorAccX->setObjectName(QStringLiteral("sb_motorAccX"));
        sb_motorAccX->setEnabled(false);
        sb_motorAccX->setReadOnly(false);
        sb_motorAccX->setMaximum(99999);
        sb_motorAccX->setValue(50000);

        ly_para_sp_acc->addWidget(sb_motorAccX);

        sp_sp_a_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_sp_acc->addItem(sp_sp_a_1);

        lb_sp_a_Y = new QLabel(gb_para_speed_v0);
        lb_sp_a_Y->setObjectName(QStringLiteral("lb_sp_a_Y"));

        ly_para_sp_acc->addWidget(lb_sp_a_Y);

        sb_motorAccY = new QSpinBox(gb_para_speed_v0);
        sb_motorAccY->setObjectName(QStringLiteral("sb_motorAccY"));
        sb_motorAccY->setEnabled(false);
        sb_motorAccY->setReadOnly(false);
        sb_motorAccY->setMaximum(99999);
        sb_motorAccY->setValue(50000);

        ly_para_sp_acc->addWidget(sb_motorAccY);

        sp_sp_a_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_para_sp_acc->addItem(sp_sp_a_2);

        lb_sp_a_Z = new QLabel(gb_para_speed_v0);
        lb_sp_a_Z->setObjectName(QStringLiteral("lb_sp_a_Z"));

        ly_para_sp_acc->addWidget(lb_sp_a_Z);

        sb_motorAccZ = new QSpinBox(gb_para_speed_v0);
        sb_motorAccZ->setObjectName(QStringLiteral("sb_motorAccZ"));
        sb_motorAccZ->setEnabled(false);
        sb_motorAccZ->setReadOnly(false);
        sb_motorAccZ->setMaximum(99999);
        sb_motorAccZ->setValue(50000);

        ly_para_sp_acc->addWidget(sb_motorAccZ);


        verticalLayout_9->addLayout(ly_para_sp_acc);


        verticalLayout_6->addWidget(gb_para_speed_v0);

        gb_para_plat = new QGroupBox(w_para_motor);
        gb_para_plat->setObjectName(QStringLiteral("gb_para_plat"));
        gridLayout_7 = new QGridLayout(gb_para_plat);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        cb_sphereMachine = new QCheckBox(gb_para_plat);
        cb_sphereMachine->setObjectName(QStringLiteral("cb_sphereMachine"));
        cb_sphereMachine->setEnabled(false);

        gridLayout_7->addWidget(cb_sphereMachine, 1, 2, 1, 1);

        cb_reverseScannerXY = new QCheckBox(gb_para_plat);
        cb_reverseScannerXY->setObjectName(QStringLiteral("cb_reverseScannerXY"));
        cb_reverseScannerXY->setEnabled(false);

        gridLayout_7->addWidget(cb_reverseScannerXY, 1, 0, 1, 1);

        cb_reverseXDir = new QCheckBox(gb_para_plat);
        cb_reverseXDir->setObjectName(QStringLiteral("cb_reverseXDir"));
        cb_reverseXDir->setEnabled(false);
        cb_reverseXDir->setChecked(true);

        gridLayout_7->addWidget(cb_reverseXDir, 0, 0, 1, 1);

        cb_reverseZDir = new QCheckBox(gb_para_plat);
        cb_reverseZDir->setObjectName(QStringLiteral("cb_reverseZDir"));
        cb_reverseZDir->setEnabled(false);

        gridLayout_7->addWidget(cb_reverseZDir, 0, 2, 1, 1);

        cb_reverseScannerZ = new QCheckBox(gb_para_plat);
        cb_reverseScannerZ->setObjectName(QStringLiteral("cb_reverseScannerZ"));
        cb_reverseScannerZ->setEnabled(false);

        gridLayout_7->addWidget(cb_reverseScannerZ, 1, 1, 1, 1);

        cb_reverseYDir = new QCheckBox(gb_para_plat);
        cb_reverseYDir->setObjectName(QStringLiteral("cb_reverseYDir"));
        cb_reverseYDir->setEnabled(false);
        cb_reverseYDir->setChecked(true);

        gridLayout_7->addWidget(cb_reverseYDir, 0, 1, 1, 1);


        verticalLayout_6->addWidget(gb_para_plat);

        sa_platformAndMotor->setWidget(w_para_motor);
        layoutWidget = new QWidget(ParaWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 470, 621, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sp_para_btn2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(sp_para_btn2);

        pb_setDefaultParam = new QPushButton(layoutWidget);
        pb_setDefaultParam->setObjectName(QStringLiteral("pb_setDefaultParam"));
        pb_setDefaultParam->setEnabled(false);

        horizontalLayout->addWidget(pb_setDefaultParam);

        pb_getDefaultParam = new QPushButton(layoutWidget);
        pb_getDefaultParam->setObjectName(QStringLiteral("pb_getDefaultParam"));
        pb_getDefaultParam->setEnabled(false);

        horizontalLayout->addWidget(pb_getDefaultParam);

        sp_para_btn1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(sp_para_btn1);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        sa_platformAndMotor->raise();
        sa_laserAndScanner->raise();
        layoutWidget->raise();
        w_para_btn->raise();
        sa_sortingMethod->raise();

        retranslateUi(ParaWindow);

        QMetaObject::connectSlotsByName(ParaWindow);
    } // setupUi

    void retranslateUi(QDialog *ParaWindow)
    {
        ParaWindow->setWindowTitle(QApplication::translate("ParaWindow", "\345\217\202\346\225\260", 0));
        pb_sortingMethod->setText(QString());
        lb_para_sort->setText(QApplication::translate("ParaWindow", "\346\216\222\345\272\217\346\226\271\346\263\225", 0));
        pb_laserAndScanner->setText(QString());
        lb_para_scan->setText(QApplication::translate("ParaWindow", "\346\277\200\345\205\211\346\214\257\351\225\234", 0));
        pb_PlatformMotor->setText(QString());
        lb_para_motor->setText(QApplication::translate("ParaWindow", "\345\271\263\345\217\260\347\224\265\346\234\272", 0));
        gb_para_crystal->setTitle(QApplication::translate("ParaWindow", "\346\260\264\346\231\266\351\200\211\351\241\271", 0));
        lb_para_c_w->setText(QApplication::translate("ParaWindow", "\345\256\275(X)", 0));
        lb_para_c_w2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_para_c_l->setText(QApplication::translate("ParaWindow", "\351\225\277(Y)", 0));
        lb_para_c_l2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_para_c_h->setText(QApplication::translate("ParaWindow", "\351\253\230(Z)", 0));
        lb_para_c_h2->setText(QApplication::translate("ParaWindow", "mm", 0));
        gb_para_s->setTitle(QApplication::translate("ParaWindow", "\346\216\222\345\272\217\346\226\271\346\263\225", 0));
        rb_squenceY2X->setText(QApplication::translate("ParaWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(Y-X)", 0));
        rb_squenceX2Y->setText(QApplication::translate("ParaWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(X-Y)", 0));
        rb_ShortestPath->setText(QApplication::translate("ParaWindow", "\346\234\200\347\237\255\350\267\257\345\276\204", 0));
        lb_para_w->setText(QApplication::translate("ParaWindow", "\345\235\227\345\256\275\345\272\246:", 0));
        lb_para_w2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_para_r->setText(QApplication::translate("ParaWindow", "\346\250\241\347\263\212\346\257\224\344\276\213:", 0));
        lb_para_r2->setText(QApplication::translate("ParaWindow", "%", 0));
        gb_para_m->setTitle(QApplication::translate("ParaWindow", "\347\202\271\344\272\221\346\250\241\345\236\213", 0));
        lb_min_layer->setText(QApplication::translate("ParaWindow", "\346\234\200\345\260\217\345\210\206\345\261\202\351\227\264\350\267\235:", 0));
        lb_min_layer2->setText(QApplication::translate("ParaWindow", "mm", 0));
        rb_YXCorrect->setText(QApplication::translate("ParaWindow", "YX\347\237\253\346\255\243", 0));
        rb_XYCorrect->setText(QApplication::translate("ParaWindow", "XY\347\237\253\346\255\243", 0));
        rb_noneCorrect->setText(QApplication::translate("ParaWindow", "\346\227\240", 0));
        lb_m_correct->setText(QApplication::translate("ParaWindow", "\346\211\255\346\233\262\347\237\253\346\255\243:", 0));
        gb_para_split->setTitle(QApplication::translate("ParaWindow", "\345\210\206\345\235\227\345\217\202\346\225\260", 0));
        lb_split_border->setText(QApplication::translate("ParaWindow", "\350\276\271\347\225\214\347\261\273\345\236\213:", 0));
        rb_verticalBorder->setText(QApplication::translate("ParaWindow", "\345\236\202\347\233\264", 0));
        rb_inclinedBorder->setText(QApplication::translate("ParaWindow", "\346\226\234\351\235\242", 0));
        lb_split_size->setText(QApplication::translate("ParaWindow", "\345\210\206\345\235\227\345\244\247\345\260\217", 0));
        lb_split_size_X->setText(QApplication::translate("ParaWindow", "\345\256\275(X)", 0));
        lb_split_size_X2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_split_size_Y->setText(QApplication::translate("ParaWindow", "\351\225\277(Y)", 0));
        lb_split_size_Y2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_split_size_Z->setText(QApplication::translate("ParaWindow", "\351\253\230(Z)", 0));
        lb_split_size_Z2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_split_border_para->setText(QApplication::translate("ParaWindow", "\350\276\271\347\225\214\345\217\202\346\225\260:", 0));
        lb_border_w->setText(QApplication::translate("ParaWindow", "\345\256\275\345\272\246", 0));
        lb_border_w2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_border_a->setText(QApplication::translate("ParaWindow", "\350\247\222\345\272\246", 0));
        lb_border_a2->setText(QApplication::translate("ParaWindow", "\302\260", 0));
        gb_la_test->setTitle(QApplication::translate("ParaWindow", "\346\277\200\345\205\211\346\265\213\350\257\225", 0));
        lb_laser_pulse_title->setText(QApplication::translate("ParaWindow", "Laser Pulse", 0));
        lb_highPulseTime->setText(QApplication::translate("ParaWindow", "100us", 0));
        lb_lwoPulseTime->setText(QApplication::translate("ParaWindow", "900us", 0));
        lb_test_r->setText(QApplication::translate("ParaWindow", "\346\257\224\347\216\207\357\274\232", 0));
        lb_laserRatio->setText(QApplication::translate("ParaWindow", "30", 0));
        lb_laser_r_v_2->setText(QApplication::translate("ParaWindow", "%", 0));
        lb_test_f->setText(QApplication::translate("ParaWindow", "\351\242\221\347\216\207\357\274\232", 0));
        lb_laserFrequency->setText(QApplication::translate("ParaWindow", "3000", 0));
        lb_test_f2->setText(QApplication::translate("ParaWindow", "Hz", 0));
        gb_la_set->setTitle(QApplication::translate("ParaWindow", "\350\256\276\347\275\256", 0));
        lb_set_lpoint2->setText(QApplication::translate("ParaWindow", "mm", 0));
        lb_set_lpoint->setText(QApplication::translate("ParaWindow", "\346\277\200\345\205\211\347\204\246\350\267\235\357\274\232", 0));
        lb_set_ltime2->setText(QApplication::translate("ParaWindow", "s", 0));
        lb_set_ldelay->setText(QApplication::translate("ParaWindow", "\345\207\272\345\205\211\345\273\266\346\227\266\357\274\232", 0));
        lb_set_ltime->setText(QApplication::translate("ParaWindow", "\351\242\204\347\203\255\346\227\266\351\227\264\357\274\232", 0));
        lb_set_ldelay2->setText(QApplication::translate("ParaWindow", "us", 0));
        lb_set_sdelay->setText(QApplication::translate("ParaWindow", "\346\214\257\351\225\234\345\273\266\346\227\266\357\274\232", 0));
        lb_set_sdelay2->setText(QApplication::translate("ParaWindow", "us", 0));
        lb_set_sv->setText(QApplication::translate("ParaWindow", "\346\214\257\351\225\234\351\200\237\345\272\246\357\274\232", 0));
        lb_set_sv2->setText(QApplication::translate("ParaWindow", "bit/ms", 0));
        lb_set_udelay->setText(QApplication::translate("ParaWindow", "\345\276\256\346\255\245\345\273\266\346\227\266\357\274\232", 0));
        lb_set_udelay2->setText(QApplication::translate("ParaWindow", "us", 0));
        cb_exchangeXYScanner->setText(QApplication::translate("ParaWindow", "X<->Y\346\214\257\351\225\234\344\272\222\346\215\242", 0));
        cb_stepOverMicroStep->setText(QApplication::translate("ParaWindow", "\345\276\256\346\255\245\350\267\263\350\275\254", 0));
        gb_la_para->setTitle(QApplication::translate("ParaWindow", "\346\240\207\345\256\232\345\217\202\346\225\260", 0));
        lb_la_r_X2->setText(QApplication::translate("ParaWindow", "%", 0));
        lb_la_r_Y->setText(QApplication::translate("ParaWindow", "Y\346\214\257\351\225\234\346\257\224\347\216\207\357\274\232", 0));
        lb_la_r_X->setText(QApplication::translate("ParaWindow", "X\346\214\257\351\225\234\346\257\224\347\216\207\357\274\232", 0));
        lb_la_u_Y->setText(QApplication::translate("ParaWindow", "Y\346\214\257\351\225\234\345\276\256\350\260\203\357\274\232", 0));
        lb_la_u_X->setText(QApplication::translate("ParaWindow", "X\346\214\257\351\225\234\345\276\256\350\260\203\357\274\232", 0));
        lb_la_v_X->setText(QApplication::translate("ParaWindow", "Y\346\214\257\351\225\234\350\260\203\346\225\264\357\274\232", 0));
        lb_la_v_X_2->setText(QApplication::translate("ParaWindow", "X\346\214\257\351\225\234\350\260\203\346\225\264\357\274\232", 0));
        lb_la_r_Y2->setText(QApplication::translate("ParaWindow", "%", 0));
        gb_la_ctrl->setTitle(QApplication::translate("ParaWindow", "\346\277\200\345\205\211\345\231\250\346\216\247\345\210\266", 0));
        cb_la_r232->setText(QApplication::translate("ParaWindow", "RS232\344\270\262\345\217\243\345\267\262\350\277\236\346\216\245", 0));
        gb_par_motor->setTitle(QApplication::translate("ParaWindow", "\347\224\265\346\234\272\345\217\202\346\225\260(pulse/mm)", 0));
        lb_mo_X->setText(QApplication::translate("ParaWindow", "X:", 0));
        lb_mo_X2->setText(QApplication::translate("ParaWindow", "p/mm", 0));
        lb_mo_Y->setText(QApplication::translate("ParaWindow", "Y:", 0));
        lb_mo_Y2->setText(QApplication::translate("ParaWindow", "p/mm", 0));
        lb_mo_Z->setText(QApplication::translate("ParaWindow", "Z:", 0));
        lb_mo_Z2->setText(QApplication::translate("ParaWindow", "p/mm", 0));
        gb_para_up->setTitle(QApplication::translate("ParaWindow", "\345\276\256\350\260\203(pulse)", 0));
        sp_up_X->setText(QApplication::translate("ParaWindow", "X:", 0));
        lb_up_X2->setText(QApplication::translate("ParaWindow", "p  ", 0));
        lb_up_Y->setText(QApplication::translate("ParaWindow", "Y:", 0));
        lb_up_Y2->setText(QApplication::translate("ParaWindow", "p  ", 0));
        lb_up_Z->setText(QApplication::translate("ParaWindow", "Z:", 0));
        lb_up_Z2->setText(QApplication::translate("ParaWindow", "p  ", 0));
        gb_para_s0->setTitle(QApplication::translate("ParaWindow", "\345\210\235\345\247\213\345\201\217\347\247\273(mm)", 0));
        lb_s0_X->setText(QApplication::translate("ParaWindow", "X:", 0));
        lb_s0_X2->setText(QApplication::translate("ParaWindow", "mm ", 0));
        lb_s0_Y->setText(QApplication::translate("ParaWindow", "Y:", 0));
        lb_s0_Y2->setText(QApplication::translate("ParaWindow", "mm ", 0));
        lb_s0_Z->setText(QApplication::translate("ParaWindow", "Z:", 0));
        lb_s0_Z2->setText(QApplication::translate("ParaWindow", "mm ", 0));
        gb_para_speed_v0->setTitle(QApplication::translate("ParaWindow", "\347\224\265\346\234\272\351\200\237\345\272\246", 0));
        lb_sp_v0->setText(QApplication::translate("ParaWindow", "\345\210\235\345\247\213\351\200\237\345\272\246(p/s):", 0));
        lb_sp_v0_X->setText(QApplication::translate("ParaWindow", "X:", 0));
        lb_sp_v0_Y->setText(QApplication::translate("ParaWindow", "Y:", 0));
        lb_sp_v0_Z->setText(QApplication::translate("ParaWindow", "Z:", 0));
        lb_sp_v->setText(QApplication::translate("ParaWindow", "\345\214\200\351\200\237(p/s):", 0));
        lb_sp_v_X->setText(QApplication::translate("ParaWindow", "X:", 0));
        lb_sp_v_Y->setText(QApplication::translate("ParaWindow", "Y:", 0));
        lb_sp_v_Z->setText(QApplication::translate("ParaWindow", "Z:", 0));
        lb_sp_a->setText(QApplication::translate("ParaWindow", "\345\212\240\351\200\237\345\272\246(p/s^2):", 0));
        lb_sp_a_X->setText(QApplication::translate("ParaWindow", "X:", 0));
        lb_sp_a_Y->setText(QApplication::translate("ParaWindow", "Y:", 0));
        lb_sp_a_Z->setText(QApplication::translate("ParaWindow", "Z:", 0));
        gb_para_plat->setTitle(QApplication::translate("ParaWindow", "\345\271\263\345\217\260\350\260\203\346\225\264", 0));
        cb_sphereMachine->setText(QApplication::translate("ParaWindow", "\351\233\225\347\220\203\346\234\272", 0));
        cb_reverseScannerXY->setText(QApplication::translate("ParaWindow", "\346\214\257\351\225\234\347\247\273\345\212\250-XY", 0));
        cb_reverseXDir->setText(QApplication::translate("ParaWindow", "X\346\226\271\345\220\221", 0));
        cb_reverseZDir->setText(QApplication::translate("ParaWindow", "Z\346\226\271\345\220\221", 0));
        cb_reverseScannerZ->setText(QApplication::translate("ParaWindow", "\346\214\257\351\225\234\347\247\273\345\212\250-Z", 0));
        cb_reverseYDir->setText(QApplication::translate("ParaWindow", "Y\346\226\271\345\220\221", 0));
        pb_setDefaultParam->setText(QApplication::translate("ParaWindow", "\345\206\231\351\273\230\350\256\244\345\200\274", 0));
        pb_getDefaultParam->setText(QApplication::translate("ParaWindow", "\350\257\273\351\273\230\350\256\244\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class ParaWindow: public Ui_ParaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAWINDOW_H
