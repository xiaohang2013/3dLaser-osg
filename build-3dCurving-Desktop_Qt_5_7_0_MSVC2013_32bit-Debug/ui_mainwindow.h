/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_FileOpen;
    QAction *action_FileSave;
    QAction *action_FileRecent;
    QAction *action_FileExit;
    QAction *action_LaserPara;
    QAction *action_LaserRegImp;
    QAction *action_LaserRegExp;
    QAction *action_LaserBatchSet;
    QAction *action_LaserTabGen;
    QAction *action_LaserCal;
    QAction *action_LaserPosTest;
    QAction *action_LaserPlatHor;
    QAction *action_ViewTool;
    QAction *action_ViewState;
    QAction *action_ViewCtrl;
    QAction *action_ViewForth;
    QAction *action_ViewTop;
    QAction *action_ViewRight;
    QAction *action_ViewUpdate;
    QAction *action_ViewOriModel;
    QAction *action_ViewModModel;
    QAction *action_ViewApartModel;
    QAction *action_SortOri;
    QAction *action_SortY2X;
    QAction *action_SortX2Y;
    QAction *action_SlotShort;
    QAction *action_BlockX2Y;
    QAction *action_BlockY2X;
    QAction *action_BlockShort;
    QAction *action_BlockPara;
    QAction *action_OperSaveCurPos2LaserOri;
    QAction *action_OperSetCurPos2LaserOri;
    QAction *action_OperPlatHome;
    QAction *action_OperLaserOri;
    QAction *action_DebugAtchModel;
    QAction *action_DebugSplitModel;
    QAction *action_DebugHotTest;
    QAction *action_DebugStopFun;
    QAction *action_StdModLine;
    QAction *action_StdModPlat;
    QAction *action_StdModCube;
    QAction *action_StdModSphere;
    QAction *action_HelpAboutMe;
    QAction *action_LanCHN;
    QWidget *CenWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuLaser;
    QMenu *menuView;
    QMenu *menuSelect;
    QMenu *menuBlock;
    QMenu *menuOperate;
    QMenu *menu;
    QMenu *menuDebug;
    QMenu *menu_StdMod;
    QMenu *menuHelp;
    QMenu *menuLan;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *gb_ModInfo;
    QGridLayout *ly_gbModInfo;
    QLabel *lb_PointMinValZ;
    QLabel *lb_PointNum;
    QLabel *lb_PointY;
    QLabel *lb_PointX;
    QLabel *lb_PointZ;
    QLabel *lb_PointMinValY;
    QLabel *lb_PointLen;
    QLabel *lb_PointMin;
    QLabel *lb_PointMax;
    QLabel *lb_PointObj;
    QLabel *lb_PointNumVal;
    QLabel *lb_PointMaxValX;
    QLabel *lb_PointMinValX;
    QLabel *lb_PointLenValX;
    QLabel *lb_PointObjValX;
    QLabel *lb_PointMaxValY;
    QLabel *lb_PointLenValY;
    QLabel *lb_PointObjValY;
    QLabel *lb_PointMaxValZ;
    QLabel *lb_PointLenValZ;
    QLabel *lb_PointObjValZ;
    QSpacerItem *sp_Point4;
    QSpacerItem *sp_Point2;
    QSpacerItem *sp_Point3;
    QSpacerItem *sp_Point1;
    QGroupBox *gb_CrvCtrl;
    QVBoxLayout *ly_gbCrvCtrl;
    QHBoxLayout *ly_CrvTimer;
    QLabel *lb_CrvT;
    QLabel *lb_CrvValT;
    QSpacerItem *sp_Crv1;
    QLabel *lb_CrvPct;
    QProgressBar *pb_Crv;
    QHBoxLayout *ly_CrvBtn;
    QPushButton *btn_CrvStart;
    QPushButton *btn_CrvPause;
    QPushButton *btn_CrvStop;
    QPushButton *btn_CrvClsLas;
    QGroupBox *gb_PlatCtrl;
    QVBoxLayout *ly_gbPlatCtrl;
    QGridLayout *ly_PlatCtrlBtn;
    QPushButton *btn_PlatHome;
    QPushButton *btn_PlatZero;
    QPushButton *btn_PlatReset;
    QRadioButton *rbtn_PlatCo;
    QPushButton *btn_PlatXP;
    QPushButton *btn_PlatYP;
    QPushButton *btn_PlatZP;
    QRadioButton *rbtn_PlatDe;
    QPushButton *btn_PlatXN;
    QPushButton *btn_PlatYN;
    QPushButton *btn_PlatZN;
    QSpinBox *sb_PlatStep;
    QGridLayout *ly_PlatCtrlPara;
    QLabel *lb_PlatZ;
    QLabel *lb_PlatAbsValZ;
    QLabel *lb_PlatRelValX;
    QLabel *lb_PlatValZ;
    QLabel *lb_PlatRelValZ;
    QLabel *lb_PlatRelValY;
    QLabel *lb_PlatValY;
    QLabel *lb_PlatAbsValY;
    QLabel *lb_PlatAbsValX;
    QLabel *lb_PlatValX;
    QLabel *lb_PlatY;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *lb_PlatAbs;
    QLabel *lb_PlatAxis;
    QLabel *lb_PlatRel;
    QLabel *lb_PlatX;
    QLineEdit *le_PlatSetValX;
    QLineEdit *le_PlatSetValY;
    QLineEdit *le_PlatSetValZ;
    QHBoxLayout *ly_PlatCtrlMotion;
    QLabel *lb_PlatMXYZ;
    QLineEdit *le_PlatMValX;
    QLineEdit *le_PlatMValY;
    QLineEdit *le_PlatMValZ;
    QPushButton *btn_PlatMRun;
    QPushButton *btn_PlatMStop;
    QGroupBox *gb_CrvEdit;
    QVBoxLayout *ly_gbCrvEdit;
    QHBoxLayout *ly_CrvMat;
    QLabel *lb_CrvMatS;
    QLineEdit *le_MatSzX;
    QLineEdit *le_MatSzY;
    QLineEdit *le_MatSzZ;
    QPushButton *btn_CrvView;
    QHBoxLayout *ly_CrvMod;
    QLabel *lb_CrvModSz;
    QLineEdit *lb_ModSzX;
    QLineEdit *lb_ModSzY;
    QLineEdit *lb_ModSzZ;
    QPushButton *btn_ModMov;
    QGroupBox *gb_BlkPara;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *ly_Blk1;
    QLabel *lb_BlkXY;
    QLineEdit *le_BlkValX;
    QLineEdit *le_BlkVaY;
    QCheckBox *cb_BlkCen;
    QHBoxLayout *ly_Blk2;
    QLabel *lb_BlkFuz;
    QRadioButton *rbtn_BlkUni;
    QRadioButton *rbtn_BlkNor;
    QHBoxLayout *ly_Blk3;
    QLabel *lb_BlkW;
    QLineEdit *le_BlkValW;
    QLabel *lb_BlkA;
    QLineEdit *le_BlkValA;
    QLabel *lb_BlkSd;
    QLineEdit *le_BlkValSd;
    QHBoxLayout *ly_Blk4;
    QSpacerItem *sp_Blk1;
    QPushButton *btn_BlkApp;
    QGroupBox *gb_MCrvSel;
    QVBoxLayout *ly_gbMCrvSel;
    QHBoxLayout *ly_MCrv;
    QComboBox *cmb_MCrvSel;
    QCheckBox *cb_MCrvVo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1280, 816);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setBaseSize(QSize(0, 0));
        action_FileOpen = new QAction(MainWindow);
        action_FileOpen->setObjectName(QStringLiteral("action_FileOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/prefix/resource/fileOpen.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_FileOpen->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        action_FileOpen->setFont(font);
        action_FileSave = new QAction(MainWindow);
        action_FileSave->setObjectName(QStringLiteral("action_FileSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/prefix/resource/fileSave.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_FileSave->setIcon(icon1);
        action_FileRecent = new QAction(MainWindow);
        action_FileRecent->setObjectName(QStringLiteral("action_FileRecent"));
        action_FileRecent->setEnabled(false);
        action_FileExit = new QAction(MainWindow);
        action_FileExit->setObjectName(QStringLiteral("action_FileExit"));
        action_LaserPara = new QAction(MainWindow);
        action_LaserPara->setObjectName(QStringLiteral("action_LaserPara"));
        action_LaserRegImp = new QAction(MainWindow);
        action_LaserRegImp->setObjectName(QStringLiteral("action_LaserRegImp"));
        action_LaserRegExp = new QAction(MainWindow);
        action_LaserRegExp->setObjectName(QStringLiteral("action_LaserRegExp"));
        action_LaserBatchSet = new QAction(MainWindow);
        action_LaserBatchSet->setObjectName(QStringLiteral("action_LaserBatchSet"));
        action_LaserTabGen = new QAction(MainWindow);
        action_LaserTabGen->setObjectName(QStringLiteral("action_LaserTabGen"));
        action_LaserCal = new QAction(MainWindow);
        action_LaserCal->setObjectName(QStringLiteral("action_LaserCal"));
        action_LaserPosTest = new QAction(MainWindow);
        action_LaserPosTest->setObjectName(QStringLiteral("action_LaserPosTest"));
        action_LaserPlatHor = new QAction(MainWindow);
        action_LaserPlatHor->setObjectName(QStringLiteral("action_LaserPlatHor"));
        action_ViewTool = new QAction(MainWindow);
        action_ViewTool->setObjectName(QStringLiteral("action_ViewTool"));
        action_ViewTool->setCheckable(true);
        action_ViewTool->setChecked(true);
        action_ViewState = new QAction(MainWindow);
        action_ViewState->setObjectName(QStringLiteral("action_ViewState"));
        action_ViewState->setCheckable(true);
        action_ViewState->setChecked(true);
        action_ViewCtrl = new QAction(MainWindow);
        action_ViewCtrl->setObjectName(QStringLiteral("action_ViewCtrl"));
        action_ViewCtrl->setCheckable(true);
        action_ViewCtrl->setChecked(true);
        action_ViewForth = new QAction(MainWindow);
        action_ViewForth->setObjectName(QStringLiteral("action_ViewForth"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/prefix/resource/front-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ViewForth->setIcon(icon2);
        action_ViewTop = new QAction(MainWindow);
        action_ViewTop->setObjectName(QStringLiteral("action_ViewTop"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/prefix/resource/top-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ViewTop->setIcon(icon3);
        action_ViewRight = new QAction(MainWindow);
        action_ViewRight->setObjectName(QStringLiteral("action_ViewRight"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/prefix/resource/left-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ViewRight->setIcon(icon4);
        action_ViewUpdate = new QAction(MainWindow);
        action_ViewUpdate->setObjectName(QStringLiteral("action_ViewUpdate"));
        action_ViewUpdate->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/prefix/resource/refresh.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ViewUpdate->setIcon(icon5);
        action_ViewOriModel = new QAction(MainWindow);
        action_ViewOriModel->setObjectName(QStringLiteral("action_ViewOriModel"));
        action_ViewOriModel->setCheckable(true);
        action_ViewOriModel->setChecked(true);
        action_ViewOriModel->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/prefix/resource/center-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ViewOriModel->setIcon(icon6);
        action_ViewModModel = new QAction(MainWindow);
        action_ViewModModel->setObjectName(QStringLiteral("action_ViewModModel"));
        action_ViewModModel->setEnabled(false);
        action_ViewApartModel = new QAction(MainWindow);
        action_ViewApartModel->setObjectName(QStringLiteral("action_ViewApartModel"));
        action_ViewApartModel->setEnabled(false);
        action_SortOri = new QAction(MainWindow);
        action_SortOri->setObjectName(QStringLiteral("action_SortOri"));
        action_SortY2X = new QAction(MainWindow);
        action_SortY2X->setObjectName(QStringLiteral("action_SortY2X"));
        action_SortX2Y = new QAction(MainWindow);
        action_SortX2Y->setObjectName(QStringLiteral("action_SortX2Y"));
        action_SlotShort = new QAction(MainWindow);
        action_SlotShort->setObjectName(QStringLiteral("action_SlotShort"));
        action_SlotShort->setCheckable(true);
        action_SlotShort->setChecked(true);
        action_SlotShort->setEnabled(false);
        action_BlockX2Y = new QAction(MainWindow);
        action_BlockX2Y->setObjectName(QStringLiteral("action_BlockX2Y"));
        action_BlockX2Y->setCheckable(false);
        action_BlockX2Y->setChecked(false);
        action_BlockX2Y->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/prefix/resource/b-X2Y.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_BlockX2Y->setIcon(icon7);
        action_BlockY2X = new QAction(MainWindow);
        action_BlockY2X->setObjectName(QStringLiteral("action_BlockY2X"));
        action_BlockY2X->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/prefix/resource/b-Y2X.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_BlockY2X->setIcon(icon8);
        action_BlockShort = new QAction(MainWindow);
        action_BlockShort->setObjectName(QStringLiteral("action_BlockShort"));
        action_BlockShort->setEnabled(false);
        action_BlockPara = new QAction(MainWindow);
        action_BlockPara->setObjectName(QStringLiteral("action_BlockPara"));
        action_BlockPara->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/prefix/resource/mirror.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_BlockPara->setIcon(icon9);
        action_OperSaveCurPos2LaserOri = new QAction(MainWindow);
        action_OperSaveCurPos2LaserOri->setObjectName(QStringLiteral("action_OperSaveCurPos2LaserOri"));
        action_OperSetCurPos2LaserOri = new QAction(MainWindow);
        action_OperSetCurPos2LaserOri->setObjectName(QStringLiteral("action_OperSetCurPos2LaserOri"));
        action_OperSetCurPos2LaserOri->setCheckable(true);
        action_OperSetCurPos2LaserOri->setChecked(true);
        action_OperPlatHome = new QAction(MainWindow);
        action_OperPlatHome->setObjectName(QStringLiteral("action_OperPlatHome"));
        action_OperLaserOri = new QAction(MainWindow);
        action_OperLaserOri->setObjectName(QStringLiteral("action_OperLaserOri"));
        action_DebugAtchModel = new QAction(MainWindow);
        action_DebugAtchModel->setObjectName(QStringLiteral("action_DebugAtchModel"));
        action_DebugSplitModel = new QAction(MainWindow);
        action_DebugSplitModel->setObjectName(QStringLiteral("action_DebugSplitModel"));
        action_DebugHotTest = new QAction(MainWindow);
        action_DebugHotTest->setObjectName(QStringLiteral("action_DebugHotTest"));
        action_DebugStopFun = new QAction(MainWindow);
        action_DebugStopFun->setObjectName(QStringLiteral("action_DebugStopFun"));
        action_StdModLine = new QAction(MainWindow);
        action_StdModLine->setObjectName(QStringLiteral("action_StdModLine"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/prefix/resource/line.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StdModLine->setIcon(icon10);
        action_StdModPlat = new QAction(MainWindow);
        action_StdModPlat->setObjectName(QStringLiteral("action_StdModPlat"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/prefix/resource/parallel.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StdModPlat->setIcon(icon11);
        action_StdModCube = new QAction(MainWindow);
        action_StdModCube->setObjectName(QStringLiteral("action_StdModCube"));
        action_StdModSphere = new QAction(MainWindow);
        action_StdModSphere->setObjectName(QStringLiteral("action_StdModSphere"));
        action_HelpAboutMe = new QAction(MainWindow);
        action_HelpAboutMe->setObjectName(QStringLiteral("action_HelpAboutMe"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/prefix/resource/info.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_HelpAboutMe->setIcon(icon12);
        action_LanCHN = new QAction(MainWindow);
        action_LanCHN->setObjectName(QStringLiteral("action_LanCHN"));
        CenWidget = new QWidget(MainWindow);
        CenWidget->setObjectName(QStringLiteral("CenWidget"));
        sizePolicy.setHeightForWidth(CenWidget->sizePolicy().hasHeightForWidth());
        CenWidget->setSizePolicy(sizePolicy);
        CenWidget->setMinimumSize(QSize(0, 0));
        MainWindow->setCentralWidget(CenWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuLaser = new QMenu(menuBar);
        menuLaser->setObjectName(QStringLiteral("menuLaser"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuSelect = new QMenu(menuBar);
        menuSelect->setObjectName(QStringLiteral("menuSelect"));
        menuBlock = new QMenu(menuBar);
        menuBlock->setObjectName(QStringLiteral("menuBlock"));
        menuOperate = new QMenu(menuBar);
        menuOperate->setObjectName(QStringLiteral("menuOperate"));
        menu = new QMenu(menuOperate);
        menu->setObjectName(QStringLiteral("menu"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        menu_StdMod = new QMenu(menuDebug);
        menu_StdMod->setObjectName(QStringLiteral("menu_StdMod"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuLan = new QMenu(menuBar);
        menuLan->setObjectName(QStringLiteral("menuLan"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127);"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy1);
        dockWidget->setMinimumSize(QSize(300, 646));
        dockWidget->setMaximumSize(QSize(300, 524287));
        dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gb_ModInfo = new QGroupBox(dockWidgetContents);
        gb_ModInfo->setObjectName(QStringLiteral("gb_ModInfo"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gb_ModInfo->sizePolicy().hasHeightForWidth());
        gb_ModInfo->setSizePolicy(sizePolicy2);
        gb_ModInfo->setMinimumSize(QSize(0, 0));
        ly_gbModInfo = new QGridLayout(gb_ModInfo);
        ly_gbModInfo->setSpacing(1);
        ly_gbModInfo->setContentsMargins(11, 11, 11, 11);
        ly_gbModInfo->setObjectName(QStringLiteral("ly_gbModInfo"));
        ly_gbModInfo->setContentsMargins(3, 0, 3, 0);
        lb_PointMinValZ = new QLabel(gb_ModInfo);
        lb_PointMinValZ->setObjectName(QStringLiteral("lb_PointMinValZ"));
        lb_PointMinValZ->setScaledContents(false);
        lb_PointMinValZ->setAlignment(Qt::AlignCenter);
        lb_PointMinValZ->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMinValZ, 4, 1, 1, 1);

        lb_PointNum = new QLabel(gb_ModInfo);
        lb_PointNum->setObjectName(QStringLiteral("lb_PointNum"));
        lb_PointNum->setScaledContents(false);
        lb_PointNum->setAlignment(Qt::AlignCenter);
        lb_PointNum->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointNum, 0, 0, 1, 1);

        lb_PointY = new QLabel(gb_ModInfo);
        lb_PointY->setObjectName(QStringLiteral("lb_PointY"));
        lb_PointY->setScaledContents(false);
        lb_PointY->setAlignment(Qt::AlignCenter);
        lb_PointY->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointY, 3, 0, 1, 1);

        lb_PointX = new QLabel(gb_ModInfo);
        lb_PointX->setObjectName(QStringLiteral("lb_PointX"));
        lb_PointX->setScaledContents(false);
        lb_PointX->setAlignment(Qt::AlignCenter);
        lb_PointX->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointX, 2, 0, 1, 1);

        lb_PointZ = new QLabel(gb_ModInfo);
        lb_PointZ->setObjectName(QStringLiteral("lb_PointZ"));
        lb_PointZ->setScaledContents(false);
        lb_PointZ->setAlignment(Qt::AlignCenter);
        lb_PointZ->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointZ, 4, 0, 1, 1);

        lb_PointMinValY = new QLabel(gb_ModInfo);
        lb_PointMinValY->setObjectName(QStringLiteral("lb_PointMinValY"));
        lb_PointMinValY->setScaledContents(false);
        lb_PointMinValY->setAlignment(Qt::AlignCenter);
        lb_PointMinValY->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMinValY, 3, 1, 1, 1);

        lb_PointLen = new QLabel(gb_ModInfo);
        lb_PointLen->setObjectName(QStringLiteral("lb_PointLen"));
        lb_PointLen->setScaledContents(false);
        lb_PointLen->setAlignment(Qt::AlignCenter);
        lb_PointLen->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointLen, 1, 3, 1, 1);

        lb_PointMin = new QLabel(gb_ModInfo);
        lb_PointMin->setObjectName(QStringLiteral("lb_PointMin"));
        lb_PointMin->setScaledContents(false);
        lb_PointMin->setAlignment(Qt::AlignCenter);
        lb_PointMin->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMin, 1, 1, 1, 1);

        lb_PointMax = new QLabel(gb_ModInfo);
        lb_PointMax->setObjectName(QStringLiteral("lb_PointMax"));
        lb_PointMax->setScaledContents(false);
        lb_PointMax->setAlignment(Qt::AlignCenter);
        lb_PointMax->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMax, 1, 2, 1, 1);

        lb_PointObj = new QLabel(gb_ModInfo);
        lb_PointObj->setObjectName(QStringLiteral("lb_PointObj"));
        lb_PointObj->setScaledContents(false);
        lb_PointObj->setAlignment(Qt::AlignCenter);
        lb_PointObj->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointObj, 1, 4, 1, 1);

        lb_PointNumVal = new QLabel(gb_ModInfo);
        lb_PointNumVal->setObjectName(QStringLiteral("lb_PointNumVal"));
        lb_PointNumVal->setScaledContents(false);
        lb_PointNumVal->setAlignment(Qt::AlignCenter);
        lb_PointNumVal->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointNumVal, 0, 1, 1, 1);

        lb_PointMaxValX = new QLabel(gb_ModInfo);
        lb_PointMaxValX->setObjectName(QStringLiteral("lb_PointMaxValX"));
        lb_PointMaxValX->setScaledContents(false);
        lb_PointMaxValX->setAlignment(Qt::AlignCenter);
        lb_PointMaxValX->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMaxValX, 2, 2, 1, 1);

        lb_PointMinValX = new QLabel(gb_ModInfo);
        lb_PointMinValX->setObjectName(QStringLiteral("lb_PointMinValX"));
        lb_PointMinValX->setScaledContents(false);
        lb_PointMinValX->setAlignment(Qt::AlignCenter);
        lb_PointMinValX->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMinValX, 2, 1, 1, 1);

        lb_PointLenValX = new QLabel(gb_ModInfo);
        lb_PointLenValX->setObjectName(QStringLiteral("lb_PointLenValX"));
        lb_PointLenValX->setScaledContents(false);
        lb_PointLenValX->setAlignment(Qt::AlignCenter);
        lb_PointLenValX->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointLenValX, 2, 3, 1, 1);

        lb_PointObjValX = new QLabel(gb_ModInfo);
        lb_PointObjValX->setObjectName(QStringLiteral("lb_PointObjValX"));
        lb_PointObjValX->setScaledContents(false);
        lb_PointObjValX->setAlignment(Qt::AlignCenter);
        lb_PointObjValX->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointObjValX, 2, 4, 1, 1);

        lb_PointMaxValY = new QLabel(gb_ModInfo);
        lb_PointMaxValY->setObjectName(QStringLiteral("lb_PointMaxValY"));
        lb_PointMaxValY->setScaledContents(false);
        lb_PointMaxValY->setAlignment(Qt::AlignCenter);
        lb_PointMaxValY->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMaxValY, 3, 2, 1, 1);

        lb_PointLenValY = new QLabel(gb_ModInfo);
        lb_PointLenValY->setObjectName(QStringLiteral("lb_PointLenValY"));
        lb_PointLenValY->setScaledContents(false);
        lb_PointLenValY->setAlignment(Qt::AlignCenter);
        lb_PointLenValY->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointLenValY, 3, 3, 1, 1);

        lb_PointObjValY = new QLabel(gb_ModInfo);
        lb_PointObjValY->setObjectName(QStringLiteral("lb_PointObjValY"));
        lb_PointObjValY->setScaledContents(false);
        lb_PointObjValY->setAlignment(Qt::AlignCenter);
        lb_PointObjValY->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointObjValY, 3, 4, 1, 1);

        lb_PointMaxValZ = new QLabel(gb_ModInfo);
        lb_PointMaxValZ->setObjectName(QStringLiteral("lb_PointMaxValZ"));
        lb_PointMaxValZ->setScaledContents(false);
        lb_PointMaxValZ->setAlignment(Qt::AlignCenter);
        lb_PointMaxValZ->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointMaxValZ, 4, 2, 1, 1);

        lb_PointLenValZ = new QLabel(gb_ModInfo);
        lb_PointLenValZ->setObjectName(QStringLiteral("lb_PointLenValZ"));
        lb_PointLenValZ->setScaledContents(false);
        lb_PointLenValZ->setAlignment(Qt::AlignCenter);
        lb_PointLenValZ->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointLenValZ, 4, 3, 1, 1);

        lb_PointObjValZ = new QLabel(gb_ModInfo);
        lb_PointObjValZ->setObjectName(QStringLiteral("lb_PointObjValZ"));
        lb_PointObjValZ->setScaledContents(false);
        lb_PointObjValZ->setAlignment(Qt::AlignCenter);
        lb_PointObjValZ->setWordWrap(false);

        ly_gbModInfo->addWidget(lb_PointObjValZ, 4, 4, 1, 1);

        sp_Point4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo->addItem(sp_Point4, 1, 0, 1, 1);

        sp_Point2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo->addItem(sp_Point2, 0, 2, 1, 1);

        sp_Point3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo->addItem(sp_Point3, 0, 3, 1, 1);

        sp_Point1 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo->addItem(sp_Point1, 0, 4, 1, 1);


        verticalLayout->addWidget(gb_ModInfo);

        gb_CrvCtrl = new QGroupBox(dockWidgetContents);
        gb_CrvCtrl->setObjectName(QStringLiteral("gb_CrvCtrl"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(gb_CrvCtrl->sizePolicy().hasHeightForWidth());
        gb_CrvCtrl->setSizePolicy(sizePolicy3);
        ly_gbCrvCtrl = new QVBoxLayout(gb_CrvCtrl);
        ly_gbCrvCtrl->setSpacing(1);
        ly_gbCrvCtrl->setContentsMargins(11, 11, 11, 11);
        ly_gbCrvCtrl->setObjectName(QStringLiteral("ly_gbCrvCtrl"));
        ly_gbCrvCtrl->setContentsMargins(3, 0, 3, 3);
        ly_CrvTimer = new QHBoxLayout();
        ly_CrvTimer->setSpacing(1);
        ly_CrvTimer->setObjectName(QStringLiteral("ly_CrvTimer"));
        lb_CrvT = new QLabel(gb_CrvCtrl);
        lb_CrvT->setObjectName(QStringLiteral("lb_CrvT"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lb_CrvT->sizePolicy().hasHeightForWidth());
        lb_CrvT->setSizePolicy(sizePolicy4);

        ly_CrvTimer->addWidget(lb_CrvT);

        lb_CrvValT = new QLabel(gb_CrvCtrl);
        lb_CrvValT->setObjectName(QStringLiteral("lb_CrvValT"));
        sizePolicy2.setHeightForWidth(lb_CrvValT->sizePolicy().hasHeightForWidth());
        lb_CrvValT->setSizePolicy(sizePolicy2);

        ly_CrvTimer->addWidget(lb_CrvValT);

        sp_Crv1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_CrvTimer->addItem(sp_Crv1);

        lb_CrvPct = new QLabel(gb_CrvCtrl);
        lb_CrvPct->setObjectName(QStringLiteral("lb_CrvPct"));
        sizePolicy4.setHeightForWidth(lb_CrvPct->sizePolicy().hasHeightForWidth());
        lb_CrvPct->setSizePolicy(sizePolicy4);

        ly_CrvTimer->addWidget(lb_CrvPct);


        ly_gbCrvCtrl->addLayout(ly_CrvTimer);

        pb_Crv = new QProgressBar(gb_CrvCtrl);
        pb_Crv->setObjectName(QStringLiteral("pb_Crv"));
        sizePolicy3.setHeightForWidth(pb_Crv->sizePolicy().hasHeightForWidth());
        pb_Crv->setSizePolicy(sizePolicy3);
        pb_Crv->setValue(0);
        pb_Crv->setTextVisible(false);

        ly_gbCrvCtrl->addWidget(pb_Crv);

        ly_CrvBtn = new QHBoxLayout();
        ly_CrvBtn->setSpacing(1);
        ly_CrvBtn->setObjectName(QStringLiteral("ly_CrvBtn"));
        ly_CrvBtn->setSizeConstraint(QLayout::SetDefaultConstraint);
        btn_CrvStart = new QPushButton(gb_CrvCtrl);
        btn_CrvStart->setObjectName(QStringLiteral("btn_CrvStart"));
        sizePolicy3.setHeightForWidth(btn_CrvStart->sizePolicy().hasHeightForWidth());
        btn_CrvStart->setSizePolicy(sizePolicy3);

        ly_CrvBtn->addWidget(btn_CrvStart);

        btn_CrvPause = new QPushButton(gb_CrvCtrl);
        btn_CrvPause->setObjectName(QStringLiteral("btn_CrvPause"));
        sizePolicy3.setHeightForWidth(btn_CrvPause->sizePolicy().hasHeightForWidth());
        btn_CrvPause->setSizePolicy(sizePolicy3);

        ly_CrvBtn->addWidget(btn_CrvPause);

        btn_CrvStop = new QPushButton(gb_CrvCtrl);
        btn_CrvStop->setObjectName(QStringLiteral("btn_CrvStop"));
        sizePolicy3.setHeightForWidth(btn_CrvStop->sizePolicy().hasHeightForWidth());
        btn_CrvStop->setSizePolicy(sizePolicy3);

        ly_CrvBtn->addWidget(btn_CrvStop);

        btn_CrvClsLas = new QPushButton(gb_CrvCtrl);
        btn_CrvClsLas->setObjectName(QStringLiteral("btn_CrvClsLas"));
        sizePolicy3.setHeightForWidth(btn_CrvClsLas->sizePolicy().hasHeightForWidth());
        btn_CrvClsLas->setSizePolicy(sizePolicy3);
        btn_CrvClsLas->setMinimumSize(QSize(0, 0));
        btn_CrvClsLas->setMaximumSize(QSize(16777215, 16777215));

        ly_CrvBtn->addWidget(btn_CrvClsLas);


        ly_gbCrvCtrl->addLayout(ly_CrvBtn);

        pb_Crv->raise();

        verticalLayout->addWidget(gb_CrvCtrl);

        gb_PlatCtrl = new QGroupBox(dockWidgetContents);
        gb_PlatCtrl->setObjectName(QStringLiteral("gb_PlatCtrl"));
        ly_gbPlatCtrl = new QVBoxLayout(gb_PlatCtrl);
        ly_gbPlatCtrl->setSpacing(1);
        ly_gbPlatCtrl->setContentsMargins(11, 11, 11, 11);
        ly_gbPlatCtrl->setObjectName(QStringLiteral("ly_gbPlatCtrl"));
        ly_gbPlatCtrl->setContentsMargins(3, 0, 3, 0);
        ly_PlatCtrlBtn = new QGridLayout();
        ly_PlatCtrlBtn->setSpacing(1);
        ly_PlatCtrlBtn->setObjectName(QStringLiteral("ly_PlatCtrlBtn"));
        btn_PlatHome = new QPushButton(gb_PlatCtrl);
        btn_PlatHome->setObjectName(QStringLiteral("btn_PlatHome"));
        sizePolicy2.setHeightForWidth(btn_PlatHome->sizePolicy().hasHeightForWidth());
        btn_PlatHome->setSizePolicy(sizePolicy2);
        btn_PlatHome->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatHome, 0, 0, 1, 1);

        btn_PlatZero = new QPushButton(gb_PlatCtrl);
        btn_PlatZero->setObjectName(QStringLiteral("btn_PlatZero"));
        sizePolicy2.setHeightForWidth(btn_PlatZero->sizePolicy().hasHeightForWidth());
        btn_PlatZero->setSizePolicy(sizePolicy2);
        btn_PlatZero->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatZero, 0, 1, 1, 1);

        btn_PlatReset = new QPushButton(gb_PlatCtrl);
        btn_PlatReset->setObjectName(QStringLiteral("btn_PlatReset"));
        sizePolicy2.setHeightForWidth(btn_PlatReset->sizePolicy().hasHeightForWidth());
        btn_PlatReset->setSizePolicy(sizePolicy2);
        btn_PlatReset->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatReset, 0, 2, 1, 1);

        rbtn_PlatCo = new QRadioButton(gb_PlatCtrl);
        rbtn_PlatCo->setObjectName(QStringLiteral("rbtn_PlatCo"));
        sizePolicy3.setHeightForWidth(rbtn_PlatCo->sizePolicy().hasHeightForWidth());
        rbtn_PlatCo->setSizePolicy(sizePolicy3);

        ly_PlatCtrlBtn->addWidget(rbtn_PlatCo, 0, 3, 1, 1);

        btn_PlatXP = new QPushButton(gb_PlatCtrl);
        btn_PlatXP->setObjectName(QStringLiteral("btn_PlatXP"));
        sizePolicy2.setHeightForWidth(btn_PlatXP->sizePolicy().hasHeightForWidth());
        btn_PlatXP->setSizePolicy(sizePolicy2);
        btn_PlatXP->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatXP, 1, 0, 1, 1);

        btn_PlatYP = new QPushButton(gb_PlatCtrl);
        btn_PlatYP->setObjectName(QStringLiteral("btn_PlatYP"));
        sizePolicy2.setHeightForWidth(btn_PlatYP->sizePolicy().hasHeightForWidth());
        btn_PlatYP->setSizePolicy(sizePolicy2);
        btn_PlatYP->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatYP, 1, 1, 1, 1);

        btn_PlatZP = new QPushButton(gb_PlatCtrl);
        btn_PlatZP->setObjectName(QStringLiteral("btn_PlatZP"));
        sizePolicy2.setHeightForWidth(btn_PlatZP->sizePolicy().hasHeightForWidth());
        btn_PlatZP->setSizePolicy(sizePolicy2);
        btn_PlatZP->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatZP, 1, 2, 1, 1);

        rbtn_PlatDe = new QRadioButton(gb_PlatCtrl);
        rbtn_PlatDe->setObjectName(QStringLiteral("rbtn_PlatDe"));
        sizePolicy3.setHeightForWidth(rbtn_PlatDe->sizePolicy().hasHeightForWidth());
        rbtn_PlatDe->setSizePolicy(sizePolicy3);

        ly_PlatCtrlBtn->addWidget(rbtn_PlatDe, 1, 3, 1, 1);

        btn_PlatXN = new QPushButton(gb_PlatCtrl);
        btn_PlatXN->setObjectName(QStringLiteral("btn_PlatXN"));
        sizePolicy2.setHeightForWidth(btn_PlatXN->sizePolicy().hasHeightForWidth());
        btn_PlatXN->setSizePolicy(sizePolicy2);
        btn_PlatXN->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatXN, 2, 0, 1, 1);

        btn_PlatYN = new QPushButton(gb_PlatCtrl);
        btn_PlatYN->setObjectName(QStringLiteral("btn_PlatYN"));
        sizePolicy2.setHeightForWidth(btn_PlatYN->sizePolicy().hasHeightForWidth());
        btn_PlatYN->setSizePolicy(sizePolicy2);
        btn_PlatYN->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatYN, 2, 1, 1, 1);

        btn_PlatZN = new QPushButton(gb_PlatCtrl);
        btn_PlatZN->setObjectName(QStringLiteral("btn_PlatZN"));
        sizePolicy2.setHeightForWidth(btn_PlatZN->sizePolicy().hasHeightForWidth());
        btn_PlatZN->setSizePolicy(sizePolicy2);
        btn_PlatZN->setAutoDefault(false);

        ly_PlatCtrlBtn->addWidget(btn_PlatZN, 2, 2, 1, 1);

        sb_PlatStep = new QSpinBox(gb_PlatCtrl);
        sb_PlatStep->setObjectName(QStringLiteral("sb_PlatStep"));
        sizePolicy3.setHeightForWidth(sb_PlatStep->sizePolicy().hasHeightForWidth());
        sb_PlatStep->setSizePolicy(sizePolicy3);

        ly_PlatCtrlBtn->addWidget(sb_PlatStep, 2, 3, 1, 1);

        ly_PlatCtrlBtn->setColumnStretch(0, 1);
        ly_PlatCtrlBtn->setColumnStretch(1, 1);
        ly_PlatCtrlBtn->setColumnStretch(2, 1);
        ly_PlatCtrlBtn->setColumnStretch(3, 1);

        ly_gbPlatCtrl->addLayout(ly_PlatCtrlBtn);

        ly_PlatCtrlPara = new QGridLayout();
        ly_PlatCtrlPara->setSpacing(1);
        ly_PlatCtrlPara->setObjectName(QStringLiteral("ly_PlatCtrlPara"));
        ly_PlatCtrlPara->setContentsMargins(0, -1, 0, -1);
        lb_PlatZ = new QLabel(gb_PlatCtrl);
        lb_PlatZ->setObjectName(QStringLiteral("lb_PlatZ"));

        ly_PlatCtrlPara->addWidget(lb_PlatZ, 3, 0, 1, 1);

        lb_PlatAbsValZ = new QLabel(gb_PlatCtrl);
        lb_PlatAbsValZ->setObjectName(QStringLiteral("lb_PlatAbsValZ"));

        ly_PlatCtrlPara->addWidget(lb_PlatAbsValZ, 3, 2, 1, 1);

        lb_PlatRelValX = new QLabel(gb_PlatCtrl);
        lb_PlatRelValX->setObjectName(QStringLiteral("lb_PlatRelValX"));

        ly_PlatCtrlPara->addWidget(lb_PlatRelValX, 1, 1, 1, 1);

        lb_PlatValZ = new QLabel(gb_PlatCtrl);
        lb_PlatValZ->setObjectName(QStringLiteral("lb_PlatValZ"));

        ly_PlatCtrlPara->addWidget(lb_PlatValZ, 3, 3, 1, 1);

        lb_PlatRelValZ = new QLabel(gb_PlatCtrl);
        lb_PlatRelValZ->setObjectName(QStringLiteral("lb_PlatRelValZ"));

        ly_PlatCtrlPara->addWidget(lb_PlatRelValZ, 3, 1, 1, 1);

        lb_PlatRelValY = new QLabel(gb_PlatCtrl);
        lb_PlatRelValY->setObjectName(QStringLiteral("lb_PlatRelValY"));

        ly_PlatCtrlPara->addWidget(lb_PlatRelValY, 2, 1, 1, 1);

        lb_PlatValY = new QLabel(gb_PlatCtrl);
        lb_PlatValY->setObjectName(QStringLiteral("lb_PlatValY"));

        ly_PlatCtrlPara->addWidget(lb_PlatValY, 2, 3, 1, 1);

        lb_PlatAbsValY = new QLabel(gb_PlatCtrl);
        lb_PlatAbsValY->setObjectName(QStringLiteral("lb_PlatAbsValY"));

        ly_PlatCtrlPara->addWidget(lb_PlatAbsValY, 2, 2, 1, 1);

        lb_PlatAbsValX = new QLabel(gb_PlatCtrl);
        lb_PlatAbsValX->setObjectName(QStringLiteral("lb_PlatAbsValX"));

        ly_PlatCtrlPara->addWidget(lb_PlatAbsValX, 1, 2, 1, 1);

        lb_PlatValX = new QLabel(gb_PlatCtrl);
        lb_PlatValX->setObjectName(QStringLiteral("lb_PlatValX"));

        ly_PlatCtrlPara->addWidget(lb_PlatValX, 1, 3, 1, 1);

        lb_PlatY = new QLabel(gb_PlatCtrl);
        lb_PlatY->setObjectName(QStringLiteral("lb_PlatY"));

        ly_PlatCtrlPara->addWidget(lb_PlatY, 2, 0, 1, 1);

        label_6 = new QLabel(gb_PlatCtrl);
        label_6->setObjectName(QStringLiteral("label_6"));

        ly_PlatCtrlPara->addWidget(label_6, 0, 3, 1, 1);

        label_8 = new QLabel(gb_PlatCtrl);
        label_8->setObjectName(QStringLiteral("label_8"));

        ly_PlatCtrlPara->addWidget(label_8, 0, 4, 1, 1);

        lb_PlatAbs = new QLabel(gb_PlatCtrl);
        lb_PlatAbs->setObjectName(QStringLiteral("lb_PlatAbs"));

        ly_PlatCtrlPara->addWidget(lb_PlatAbs, 0, 2, 1, 1);

        lb_PlatAxis = new QLabel(gb_PlatCtrl);
        lb_PlatAxis->setObjectName(QStringLiteral("lb_PlatAxis"));

        ly_PlatCtrlPara->addWidget(lb_PlatAxis, 0, 0, 1, 1);

        lb_PlatRel = new QLabel(gb_PlatCtrl);
        lb_PlatRel->setObjectName(QStringLiteral("lb_PlatRel"));

        ly_PlatCtrlPara->addWidget(lb_PlatRel, 0, 1, 1, 1);

        lb_PlatX = new QLabel(gb_PlatCtrl);
        lb_PlatX->setObjectName(QStringLiteral("lb_PlatX"));
        sizePolicy2.setHeightForWidth(lb_PlatX->sizePolicy().hasHeightForWidth());
        lb_PlatX->setSizePolicy(sizePolicy2);

        ly_PlatCtrlPara->addWidget(lb_PlatX, 1, 0, 1, 1);

        le_PlatSetValX = new QLineEdit(gb_PlatCtrl);
        le_PlatSetValX->setObjectName(QStringLiteral("le_PlatSetValX"));
        le_PlatSetValX->setEnabled(false);
        sizePolicy3.setHeightForWidth(le_PlatSetValX->sizePolicy().hasHeightForWidth());
        le_PlatSetValX->setSizePolicy(sizePolicy3);
        le_PlatSetValX->setMinimumSize(QSize(0, 0));
        le_PlatSetValX->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlPara->addWidget(le_PlatSetValX, 1, 4, 1, 1);

        le_PlatSetValY = new QLineEdit(gb_PlatCtrl);
        le_PlatSetValY->setObjectName(QStringLiteral("le_PlatSetValY"));
        le_PlatSetValY->setEnabled(false);
        sizePolicy3.setHeightForWidth(le_PlatSetValY->sizePolicy().hasHeightForWidth());
        le_PlatSetValY->setSizePolicy(sizePolicy3);
        le_PlatSetValY->setMinimumSize(QSize(0, 0));
        le_PlatSetValY->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlPara->addWidget(le_PlatSetValY, 2, 4, 1, 1);

        le_PlatSetValZ = new QLineEdit(gb_PlatCtrl);
        le_PlatSetValZ->setObjectName(QStringLiteral("le_PlatSetValZ"));
        le_PlatSetValZ->setEnabled(false);
        sizePolicy3.setHeightForWidth(le_PlatSetValZ->sizePolicy().hasHeightForWidth());
        le_PlatSetValZ->setSizePolicy(sizePolicy3);
        le_PlatSetValZ->setMinimumSize(QSize(0, 0));
        le_PlatSetValZ->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlPara->addWidget(le_PlatSetValZ, 3, 4, 1, 1);

        ly_PlatCtrlPara->setColumnStretch(0, 1);
        ly_PlatCtrlPara->setColumnStretch(1, 1);
        ly_PlatCtrlPara->setColumnStretch(2, 1);
        ly_PlatCtrlPara->setColumnStretch(3, 1);
        ly_PlatCtrlPara->setColumnStretch(4, 1);

        ly_gbPlatCtrl->addLayout(ly_PlatCtrlPara);

        ly_PlatCtrlMotion = new QHBoxLayout();
        ly_PlatCtrlMotion->setSpacing(0);
        ly_PlatCtrlMotion->setObjectName(QStringLiteral("ly_PlatCtrlMotion"));
        lb_PlatMXYZ = new QLabel(gb_PlatCtrl);
        lb_PlatMXYZ->setObjectName(QStringLiteral("lb_PlatMXYZ"));

        ly_PlatCtrlMotion->addWidget(lb_PlatMXYZ);

        le_PlatMValX = new QLineEdit(gb_PlatCtrl);
        le_PlatMValX->setObjectName(QStringLiteral("le_PlatMValX"));
        sizePolicy3.setHeightForWidth(le_PlatMValX->sizePolicy().hasHeightForWidth());
        le_PlatMValX->setSizePolicy(sizePolicy3);
        le_PlatMValX->setMinimumSize(QSize(0, 0));
        le_PlatMValX->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlMotion->addWidget(le_PlatMValX);

        le_PlatMValY = new QLineEdit(gb_PlatCtrl);
        le_PlatMValY->setObjectName(QStringLiteral("le_PlatMValY"));
        sizePolicy3.setHeightForWidth(le_PlatMValY->sizePolicy().hasHeightForWidth());
        le_PlatMValY->setSizePolicy(sizePolicy3);
        le_PlatMValY->setMinimumSize(QSize(0, 0));
        le_PlatMValY->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlMotion->addWidget(le_PlatMValY);

        le_PlatMValZ = new QLineEdit(gb_PlatCtrl);
        le_PlatMValZ->setObjectName(QStringLiteral("le_PlatMValZ"));
        sizePolicy3.setHeightForWidth(le_PlatMValZ->sizePolicy().hasHeightForWidth());
        le_PlatMValZ->setSizePolicy(sizePolicy3);
        le_PlatMValZ->setMinimumSize(QSize(0, 0));
        le_PlatMValZ->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlMotion->addWidget(le_PlatMValZ);

        btn_PlatMRun = new QPushButton(gb_PlatCtrl);
        btn_PlatMRun->setObjectName(QStringLiteral("btn_PlatMRun"));
        sizePolicy3.setHeightForWidth(btn_PlatMRun->sizePolicy().hasHeightForWidth());
        btn_PlatMRun->setSizePolicy(sizePolicy3);
        btn_PlatMRun->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlMotion->addWidget(btn_PlatMRun);

        btn_PlatMStop = new QPushButton(gb_PlatCtrl);
        btn_PlatMStop->setObjectName(QStringLiteral("btn_PlatMStop"));
        sizePolicy3.setHeightForWidth(btn_PlatMStop->sizePolicy().hasHeightForWidth());
        btn_PlatMStop->setSizePolicy(sizePolicy3);
        btn_PlatMStop->setMaximumSize(QSize(16777215, 16777215));

        ly_PlatCtrlMotion->addWidget(btn_PlatMStop);


        ly_gbPlatCtrl->addLayout(ly_PlatCtrlMotion);


        verticalLayout->addWidget(gb_PlatCtrl);

        gb_CrvEdit = new QGroupBox(dockWidgetContents);
        gb_CrvEdit->setObjectName(QStringLiteral("gb_CrvEdit"));
        ly_gbCrvEdit = new QVBoxLayout(gb_CrvEdit);
        ly_gbCrvEdit->setSpacing(1);
        ly_gbCrvEdit->setContentsMargins(11, 11, 11, 11);
        ly_gbCrvEdit->setObjectName(QStringLiteral("ly_gbCrvEdit"));
        ly_gbCrvEdit->setContentsMargins(3, 0, 3, 0);
        ly_CrvMat = new QHBoxLayout();
        ly_CrvMat->setSpacing(1);
        ly_CrvMat->setObjectName(QStringLiteral("ly_CrvMat"));
        lb_CrvMatS = new QLabel(gb_CrvEdit);
        lb_CrvMatS->setObjectName(QStringLiteral("lb_CrvMatS"));
        sizePolicy3.setHeightForWidth(lb_CrvMatS->sizePolicy().hasHeightForWidth());
        lb_CrvMatS->setSizePolicy(sizePolicy3);
        lb_CrvMatS->setMinimumSize(QSize(80, 0));

        ly_CrvMat->addWidget(lb_CrvMatS);

        le_MatSzX = new QLineEdit(gb_CrvEdit);
        le_MatSzX->setObjectName(QStringLiteral("le_MatSzX"));
        sizePolicy3.setHeightForWidth(le_MatSzX->sizePolicy().hasHeightForWidth());
        le_MatSzX->setSizePolicy(sizePolicy3);
        le_MatSzX->setMaximumSize(QSize(35, 16777215));

        ly_CrvMat->addWidget(le_MatSzX);

        le_MatSzY = new QLineEdit(gb_CrvEdit);
        le_MatSzY->setObjectName(QStringLiteral("le_MatSzY"));
        sizePolicy3.setHeightForWidth(le_MatSzY->sizePolicy().hasHeightForWidth());
        le_MatSzY->setSizePolicy(sizePolicy3);
        le_MatSzY->setMaximumSize(QSize(35, 16777215));

        ly_CrvMat->addWidget(le_MatSzY);

        le_MatSzZ = new QLineEdit(gb_CrvEdit);
        le_MatSzZ->setObjectName(QStringLiteral("le_MatSzZ"));
        sizePolicy3.setHeightForWidth(le_MatSzZ->sizePolicy().hasHeightForWidth());
        le_MatSzZ->setSizePolicy(sizePolicy3);
        le_MatSzZ->setMaximumSize(QSize(35, 16777215));

        ly_CrvMat->addWidget(le_MatSzZ);

        btn_CrvView = new QPushButton(gb_CrvEdit);
        btn_CrvView->setObjectName(QStringLiteral("btn_CrvView"));
        sizePolicy3.setHeightForWidth(btn_CrvView->sizePolicy().hasHeightForWidth());
        btn_CrvView->setSizePolicy(sizePolicy3);
        btn_CrvView->setMaximumSize(QSize(40, 16777215));

        ly_CrvMat->addWidget(btn_CrvView);


        ly_gbCrvEdit->addLayout(ly_CrvMat);

        ly_CrvMod = new QHBoxLayout();
        ly_CrvMod->setSpacing(1);
        ly_CrvMod->setObjectName(QStringLiteral("ly_CrvMod"));
        lb_CrvModSz = new QLabel(gb_CrvEdit);
        lb_CrvModSz->setObjectName(QStringLiteral("lb_CrvModSz"));

        ly_CrvMod->addWidget(lb_CrvModSz);

        lb_ModSzX = new QLineEdit(gb_CrvEdit);
        lb_ModSzX->setObjectName(QStringLiteral("lb_ModSzX"));
        sizePolicy3.setHeightForWidth(lb_ModSzX->sizePolicy().hasHeightForWidth());
        lb_ModSzX->setSizePolicy(sizePolicy3);
        lb_ModSzX->setMaximumSize(QSize(35, 16777215));

        ly_CrvMod->addWidget(lb_ModSzX);

        lb_ModSzY = new QLineEdit(gb_CrvEdit);
        lb_ModSzY->setObjectName(QStringLiteral("lb_ModSzY"));
        sizePolicy3.setHeightForWidth(lb_ModSzY->sizePolicy().hasHeightForWidth());
        lb_ModSzY->setSizePolicy(sizePolicy3);
        lb_ModSzY->setMaximumSize(QSize(35, 16777215));

        ly_CrvMod->addWidget(lb_ModSzY);

        lb_ModSzZ = new QLineEdit(gb_CrvEdit);
        lb_ModSzZ->setObjectName(QStringLiteral("lb_ModSzZ"));
        sizePolicy3.setHeightForWidth(lb_ModSzZ->sizePolicy().hasHeightForWidth());
        lb_ModSzZ->setSizePolicy(sizePolicy3);
        lb_ModSzZ->setMaximumSize(QSize(35, 16777215));

        ly_CrvMod->addWidget(lb_ModSzZ);

        btn_ModMov = new QPushButton(gb_CrvEdit);
        btn_ModMov->setObjectName(QStringLiteral("btn_ModMov"));
        btn_ModMov->setEnabled(false);
        sizePolicy3.setHeightForWidth(btn_ModMov->sizePolicy().hasHeightForWidth());
        btn_ModMov->setSizePolicy(sizePolicy3);
        btn_ModMov->setMaximumSize(QSize(40, 16777215));

        ly_CrvMod->addWidget(btn_ModMov);


        ly_gbCrvEdit->addLayout(ly_CrvMod);


        verticalLayout->addWidget(gb_CrvEdit);

        gb_BlkPara = new QGroupBox(dockWidgetContents);
        gb_BlkPara->setObjectName(QStringLiteral("gb_BlkPara"));
        verticalLayout_5 = new QVBoxLayout(gb_BlkPara);
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 0, 3, 0);
        ly_Blk1 = new QHBoxLayout();
        ly_Blk1->setSpacing(1);
        ly_Blk1->setObjectName(QStringLiteral("ly_Blk1"));
        lb_BlkXY = new QLabel(gb_BlkPara);
        lb_BlkXY->setObjectName(QStringLiteral("lb_BlkXY"));

        ly_Blk1->addWidget(lb_BlkXY);

        le_BlkValX = new QLineEdit(gb_BlkPara);
        le_BlkValX->setObjectName(QStringLiteral("le_BlkValX"));

        ly_Blk1->addWidget(le_BlkValX);

        le_BlkVaY = new QLineEdit(gb_BlkPara);
        le_BlkVaY->setObjectName(QStringLiteral("le_BlkVaY"));

        ly_Blk1->addWidget(le_BlkVaY);

        cb_BlkCen = new QCheckBox(gb_BlkPara);
        cb_BlkCen->setObjectName(QStringLiteral("cb_BlkCen"));

        ly_Blk1->addWidget(cb_BlkCen);


        verticalLayout_5->addLayout(ly_Blk1);

        ly_Blk2 = new QHBoxLayout();
        ly_Blk2->setSpacing(1);
        ly_Blk2->setObjectName(QStringLiteral("ly_Blk2"));
        lb_BlkFuz = new QLabel(gb_BlkPara);
        lb_BlkFuz->setObjectName(QStringLiteral("lb_BlkFuz"));

        ly_Blk2->addWidget(lb_BlkFuz);

        rbtn_BlkUni = new QRadioButton(gb_BlkPara);
        rbtn_BlkUni->setObjectName(QStringLiteral("rbtn_BlkUni"));

        ly_Blk2->addWidget(rbtn_BlkUni);

        rbtn_BlkNor = new QRadioButton(gb_BlkPara);
        rbtn_BlkNor->setObjectName(QStringLiteral("rbtn_BlkNor"));

        ly_Blk2->addWidget(rbtn_BlkNor);


        verticalLayout_5->addLayout(ly_Blk2);

        ly_Blk3 = new QHBoxLayout();
        ly_Blk3->setSpacing(1);
        ly_Blk3->setObjectName(QStringLiteral("ly_Blk3"));
        lb_BlkW = new QLabel(gb_BlkPara);
        lb_BlkW->setObjectName(QStringLiteral("lb_BlkW"));

        ly_Blk3->addWidget(lb_BlkW);

        le_BlkValW = new QLineEdit(gb_BlkPara);
        le_BlkValW->setObjectName(QStringLiteral("le_BlkValW"));

        ly_Blk3->addWidget(le_BlkValW);

        lb_BlkA = new QLabel(gb_BlkPara);
        lb_BlkA->setObjectName(QStringLiteral("lb_BlkA"));

        ly_Blk3->addWidget(lb_BlkA);

        le_BlkValA = new QLineEdit(gb_BlkPara);
        le_BlkValA->setObjectName(QStringLiteral("le_BlkValA"));

        ly_Blk3->addWidget(le_BlkValA);

        lb_BlkSd = new QLabel(gb_BlkPara);
        lb_BlkSd->setObjectName(QStringLiteral("lb_BlkSd"));

        ly_Blk3->addWidget(lb_BlkSd);

        le_BlkValSd = new QLineEdit(gb_BlkPara);
        le_BlkValSd->setObjectName(QStringLiteral("le_BlkValSd"));

        ly_Blk3->addWidget(le_BlkValSd);


        verticalLayout_5->addLayout(ly_Blk3);

        ly_Blk4 = new QHBoxLayout();
        ly_Blk4->setSpacing(1);
        ly_Blk4->setObjectName(QStringLiteral("ly_Blk4"));
        sp_Blk1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_Blk4->addItem(sp_Blk1);

        btn_BlkApp = new QPushButton(gb_BlkPara);
        btn_BlkApp->setObjectName(QStringLiteral("btn_BlkApp"));
        sizePolicy3.setHeightForWidth(btn_BlkApp->sizePolicy().hasHeightForWidth());
        btn_BlkApp->setSizePolicy(sizePolicy3);

        ly_Blk4->addWidget(btn_BlkApp);


        verticalLayout_5->addLayout(ly_Blk4);


        verticalLayout->addWidget(gb_BlkPara);

        gb_MCrvSel = new QGroupBox(dockWidgetContents);
        gb_MCrvSel->setObjectName(QStringLiteral("gb_MCrvSel"));
        sizePolicy2.setHeightForWidth(gb_MCrvSel->sizePolicy().hasHeightForWidth());
        gb_MCrvSel->setSizePolicy(sizePolicy2);
        ly_gbMCrvSel = new QVBoxLayout(gb_MCrvSel);
        ly_gbMCrvSel->setSpacing(1);
        ly_gbMCrvSel->setContentsMargins(11, 11, 11, 11);
        ly_gbMCrvSel->setObjectName(QStringLiteral("ly_gbMCrvSel"));
        ly_gbMCrvSel->setContentsMargins(3, 0, 3, 0);
        ly_MCrv = new QHBoxLayout();
        ly_MCrv->setSpacing(40);
        ly_MCrv->setObjectName(QStringLiteral("ly_MCrv"));
        cmb_MCrvSel = new QComboBox(gb_MCrvSel);
        cmb_MCrvSel->setObjectName(QStringLiteral("cmb_MCrvSel"));

        ly_MCrv->addWidget(cmb_MCrvSel);

        cb_MCrvVo = new QCheckBox(gb_MCrvSel);
        cb_MCrvVo->setObjectName(QStringLiteral("cb_MCrvVo"));

        ly_MCrv->addWidget(cb_MCrvVo);

        ly_MCrv->setStretch(0, 1);
        ly_MCrv->setStretch(1, 1);

        ly_gbMCrvSel->addLayout(ly_MCrv);


        verticalLayout->addWidget(gb_MCrvSel);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLaser->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSelect->menuAction());
        menuBar->addAction(menuBlock->menuAction());
        menuBar->addAction(menuOperate->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuLan->menuAction());
        menuFile->addAction(action_FileOpen);
        menuFile->addAction(action_FileSave);
        menuFile->addSeparator();
        menuFile->addAction(action_FileRecent);
        menuFile->addSeparator();
        menuFile->addAction(action_FileExit);
        menuLaser->addAction(action_LaserPara);
        menuLaser->addAction(action_LaserRegImp);
        menuLaser->addAction(action_LaserRegExp);
        menuLaser->addSeparator();
        menuLaser->addAction(action_LaserBatchSet);
        menuLaser->addAction(action_LaserTabGen);
        menuLaser->addSeparator();
        menuLaser->addAction(action_LaserCal);
        menuLaser->addAction(action_LaserPosTest);
        menuLaser->addAction(action_LaserPlatHor);
        menuView->addAction(action_ViewTool);
        menuView->addAction(action_ViewState);
        menuView->addAction(action_ViewCtrl);
        menuView->addSeparator();
        menuView->addAction(action_ViewForth);
        menuView->addAction(action_ViewTop);
        menuView->addAction(action_ViewRight);
        menuView->addAction(action_ViewUpdate);
        menuView->addSeparator();
        menuView->addAction(action_ViewOriModel);
        menuView->addAction(action_ViewModModel);
        menuView->addAction(action_ViewApartModel);
        menuSelect->addAction(action_SortOri);
        menuSelect->addAction(action_SortY2X);
        menuSelect->addAction(action_SortX2Y);
        menuSelect->addAction(action_SlotShort);
        menuBlock->addAction(action_BlockX2Y);
        menuBlock->addAction(action_BlockY2X);
        menuBlock->addAction(action_BlockShort);
        menuBlock->addAction(action_BlockPara);
        menuOperate->addAction(action_OperSaveCurPos2LaserOri);
        menuOperate->addAction(menu->menuAction());
        menuOperate->addAction(action_OperSetCurPos2LaserOri);
        menuOperate->addSeparator();
        menuOperate->addAction(action_OperPlatHome);
        menu->addAction(action_OperLaserOri);
        menuDebug->addAction(menu_StdMod->menuAction());
        menuDebug->addAction(action_DebugAtchModel);
        menuDebug->addAction(action_DebugSplitModel);
        menuDebug->addAction(action_DebugStopFun);
        menuDebug->addAction(action_DebugHotTest);
        menu_StdMod->addAction(action_StdModLine);
        menu_StdMod->addAction(action_StdModPlat);
        menu_StdMod->addAction(action_StdModCube);
        menu_StdMod->addAction(action_StdModSphere);
        menuHelp->addAction(action_HelpAboutMe);
        menuLan->addAction(action_LanCHN);
        toolBar->addAction(action_FileOpen);
        toolBar->addSeparator();
        toolBar->addAction(action_ViewForth);
        toolBar->addAction(action_ViewTop);
        toolBar->addAction(action_ViewRight);
        toolBar->addSeparator();
        toolBar->addAction(action_ViewOriModel);
        toolBar->addAction(action_ViewUpdate);
        toolBar->addSeparator();
        toolBar->addAction(action_BlockX2Y);
        toolBar->addAction(action_BlockY2X);
        toolBar->addSeparator();
        toolBar->addAction(action_BlockPara);
        toolBar->addSeparator();
        toolBar->addAction(action_StdModLine);
        toolBar->addAction(action_StdModPlat);
        toolBar->addSeparator();
        toolBar->addAction(action_HelpAboutMe);

        retranslateUi(MainWindow);
        QObject::connect(action_FileOpen, SIGNAL(triggered()), MainWindow, SLOT(slot_FileOpen()));
        QObject::connect(action_FileSave, SIGNAL(triggered()), MainWindow, SLOT(slot_FileSave()));
        QObject::connect(action_FileRecent, SIGNAL(triggered()), MainWindow, SLOT(slot_FileRecent()));
        QObject::connect(action_FileExit, SIGNAL(triggered()), MainWindow, SLOT(slot_FileExit()));
        QObject::connect(action_LaserPara, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserPara()));
        QObject::connect(action_LaserCal, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserCal()));
        QObject::connect(action_LaserBatchSet, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserBatchSet()));
        QObject::connect(action_LaserPlatHor, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserPlatSetH()));
        QObject::connect(action_LaserTabGen, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserTagGen()));
        QObject::connect(action_LaserRegImp, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserRegImp()));
        QObject::connect(action_LaserRegExp, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserRegExp()));
        QObject::connect(action_LaserPosTest, SIGNAL(triggered()), MainWindow, SLOT(slot_LaserPosTest()));
        QObject::connect(action_ViewTool, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewTool()));
        QObject::connect(action_ViewUpdate, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewUpdate()));
        QObject::connect(action_ViewCtrl, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewCtrl()));
        QObject::connect(action_ViewApartModel, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewApartModel()));
        QObject::connect(action_ViewModModel, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewModModel()));
        QObject::connect(action_ViewOriModel, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewOriModel()));
        QObject::connect(action_ViewRight, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewRight()));
        QObject::connect(action_ViewState, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewState()));
        QObject::connect(action_ViewTop, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewTop()));
        QObject::connect(action_ViewForth, SIGNAL(triggered()), MainWindow, SLOT(slot_ViewForth()));
        QObject::connect(action_SlotShort, SIGNAL(triggered()), MainWindow, SLOT(slot_SortShort()));
        QObject::connect(action_SortOri, SIGNAL(triggered()), MainWindow, SLOT(slot_SortOri()));
        QObject::connect(action_SortX2Y, SIGNAL(triggered()), MainWindow, SLOT(slot_SortX2Y()));
        QObject::connect(action_SortY2X, SIGNAL(triggered()), MainWindow, SLOT(slot_BlockY2X()));
        QObject::connect(action_BlockPara, SIGNAL(triggered()), MainWindow, SLOT(slot_BlockPara()));
        QObject::connect(action_BlockShort, SIGNAL(triggered()), MainWindow, SLOT(slot_BlockShort()));
        QObject::connect(action_BlockX2Y, SIGNAL(triggered()), MainWindow, SLOT(slot_BlockX2Y()));
        QObject::connect(action_BlockY2X, SIGNAL(triggered()), MainWindow, SLOT(slot_BlockY2X()));
        QObject::connect(action_OperPlatHome, SIGNAL(triggered()), MainWindow, SLOT(slot_OperPlatHome()));
        QObject::connect(action_OperSaveCurPos2LaserOri, SIGNAL(triggered()), MainWindow, SLOT(slot_OperSaveCurPos2LaserOri()));
        QObject::connect(action_DebugAtchModel, SIGNAL(triggered()), MainWindow, SLOT(slot_DebugAtchModel()));
        QObject::connect(action_OperSetCurPos2LaserOri, SIGNAL(triggered()), MainWindow, SLOT(slot_OperSetCurPos2LaserOri()));
        QObject::connect(action_DebugHotTest, SIGNAL(triggered()), MainWindow, SLOT(slot_DebugHotTest()));
        QObject::connect(action_DebugSplitModel, SIGNAL(triggered()), MainWindow, SLOT(slot_DebugSplitModel()));
        QObject::connect(action_DebugStopFun, SIGNAL(triggered()), MainWindow, SLOT(slot_DebugStopFun()));
        QObject::connect(action_StdModCube, SIGNAL(triggered()), MainWindow, SLOT(slot_StdModCube()));
        QObject::connect(action_StdModLine, SIGNAL(triggered()), MainWindow, SLOT(slot_StdModLine()));
        QObject::connect(action_StdModPlat, SIGNAL(triggered()), MainWindow, SLOT(slot_StdModPlat()));
        QObject::connect(action_StdModSphere, SIGNAL(triggered()), MainWindow, SLOT(slot_StdModSphere()));
        QObject::connect(action_HelpAboutMe, SIGNAL(triggered()), MainWindow, SLOT(slot_HelpAboutMe()));
        QObject::connect(action_LanCHN, SIGNAL(triggered()), MainWindow, SLOT(slot_LanCHN()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_FileOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
#ifndef QT_NO_TOOLTIP
        action_FileOpen->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        action_FileOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        action_FileSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
#ifndef QT_NO_TOOLTIP
        action_FileSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        action_FileSave->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        action_FileRecent->setText(QApplication::translate("MainWindow", "\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\346\226\207\344\273\266", 0));
        action_FileRecent->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0));
        action_FileExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        action_FileExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_TOOLTIP
        action_FileExit->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        action_LaserPara->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260", 0));
#ifndef QT_NO_TOOLTIP
        action_LaserPara->setToolTip(QApplication::translate("MainWindow", "\346\277\200\345\205\211\345\217\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        action_LaserPara->setShortcut(QApplication::translate("MainWindow", "Alt+P", 0));
        action_LaserRegImp->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\263\250\345\206\214\350\241\250", 0));
#ifndef QT_NO_TOOLTIP
        action_LaserRegImp->setToolTip(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\263\250\345\206\214\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        action_LaserRegImp->setShortcut(QApplication::translate("MainWindow", "Alt+I", 0));
        action_LaserRegExp->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\263\250\345\206\214\350\241\250", 0));
#ifndef QT_NO_TOOLTIP
        action_LaserRegExp->setToolTip(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\263\250\345\206\214\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        action_LaserRegExp->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        action_LaserBatchSet->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217\351\233\225\345\210\273\350\256\276\347\275\256(S)", 0));
        action_LaserBatchSet->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        action_LaserTabGen->setText(QApplication::translate("MainWindow", "\346\240\207\350\256\260\347\240\201\347\224\237\346\210\220", 0));
        action_LaserTabGen->setShortcut(QApplication::translate("MainWindow", "Alt+G", 0));
        action_LaserCal->setText(QApplication::translate("MainWindow", "\346\240\207\345\256\232", 0));
        action_LaserCal->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        action_LaserPosTest->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\346\265\213\350\257\225", 0));
        action_LaserPosTest->setShortcut(QApplication::translate("MainWindow", "Alt+T", 0));
        action_LaserPlatHor->setText(QApplication::translate("MainWindow", "\345\217\260\351\235\242\346\260\264\345\271\263\350\260\203\350\257\225", 0));
        action_LaserPlatHor->setShortcut(QApplication::translate("MainWindow", "Alt+H", 0));
        action_ViewTool->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
        action_ViewTool->setShortcut(QApplication::translate("MainWindow", "Alt+T", 0));
        action_ViewState->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", 0));
        action_ViewState->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        action_ViewCtrl->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\346\240\217", 0));
        action_ViewCtrl->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        action_ViewForth->setText(QApplication::translate("MainWindow", "\345\211\215\350\247\206\345\233\276", 0));
        action_ViewForth->setShortcut(QApplication::translate("MainWindow", "Alt+F", 0));
        action_ViewTop->setText(QApplication::translate("MainWindow", "\351\241\266\350\247\206\345\233\276", 0));
        action_ViewTop->setShortcut(QApplication::translate("MainWindow", "Alt+T", 0));
        action_ViewRight->setText(QApplication::translate("MainWindow", "\345\217\263\350\247\206\345\233\276", 0));
        action_ViewRight->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0));
        action_ViewUpdate->setText(QApplication::translate("MainWindow", "\350\247\206\345\233\276\346\233\264\346\226\260", 0));
        action_ViewOriModel->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\250\241\345\236\213", 0));
        action_ViewOriModel->setShortcut(QApplication::translate("MainWindow", "Alt+M", 0));
        action_ViewModModel->setText(QApplication::translate("MainWindow", "\344\277\256\346\255\243\346\250\241\345\236\213", 0));
        action_ViewModModel->setShortcut(QApplication::translate("MainWindow", "Alt+M", 0));
        action_ViewApartModel->setText(QApplication::translate("MainWindow", "\345\210\206\345\211\262\346\250\241\345\236\213", 0));
        action_ViewApartModel->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        action_SortOri->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\216\222\345\272\217(O)", 0));
        action_SortOri->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        action_SortY2X->setText(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(Y->X)", 0));
#ifndef QT_NO_TOOLTIP
        action_SortY2X->setToolTip(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(Y->X)", 0));
#endif // QT_NO_TOOLTIP
        action_SortX2Y->setText(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(X->Y)", 0));
#ifndef QT_NO_TOOLTIP
        action_SortX2Y->setToolTip(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(X->Y)", 0));
#endif // QT_NO_TOOLTIP
        action_SlotShort->setText(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\345\276\204(S)", 0));
        action_BlockX2Y->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\345\235\227(X->Y)", 0));
        action_BlockY2X->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\345\235\227(Y->X)", 0));
        action_BlockShort->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\345\235\227(\346\234\200\347\237\255\350\267\257\345\276\204)", 0));
        action_BlockPara->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\273\204\345\210\206\345\235\227\342\200\246", 0));
        action_OperSaveCurPos2LaserOri->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\344\275\215\347\275\256\347\202\271\344\270\272\351\233\225\345\210\273\345\216\237\347\202\271", 0));
        action_OperSetCurPos2LaserOri->setText(QApplication::translate("MainWindow", "\345\247\213\347\273\210\344\273\245\345\275\223\345\211\215\344\275\215\347\275\256\344\270\272\351\233\225\345\210\273\345\216\237\347\202\271", 0));
        action_OperPlatHome->setText(QApplication::translate("MainWindow", "\346\234\272\346\242\260\345\216\237\347\202\271\345\244\215\344\275\215", 0));
        action_OperLaserOri->setText(QApplication::translate("MainWindow", "(0.0,0.0,0.0)", 0));
#ifndef QT_NO_TOOLTIP
        action_OperLaserOri->setToolTip(QApplication::translate("MainWindow", "\346\277\200\345\205\211\345\216\237\347\202\271", 0));
#endif // QT_NO_TOOLTIP
        action_DebugAtchModel->setText(QApplication::translate("MainWindow", "\351\231\204\345\212\240\346\250\241\345\236\213(A)", 0));
        action_DebugAtchModel->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        action_DebugSplitModel->setText(QApplication::translate("MainWindow", "\345\210\206\347\246\273\346\250\241\345\236\213(U)", 0));
        action_DebugSplitModel->setShortcut(QApplication::translate("MainWindow", "Alt+U", 0));
        action_DebugHotTest->setText(QApplication::translate("MainWindow", "\347\203\244\346\234\272", 0));
        action_DebugStopFun->setText(QApplication::translate("MainWindow", "\345\201\234\347\224\250\345\212\237\350\203\275", 0));
        action_StdModLine->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277(L)", 0));
        action_StdModPlat->setText(QApplication::translate("MainWindow", "\345\271\263\351\235\242(P)", 0));
        action_StdModCube->setText(QApplication::translate("MainWindow", "\347\253\213\346\226\271\344\275\223(C)", 0));
        action_StdModSphere->setText(QApplication::translate("MainWindow", "\345\234\206\347\220\203(S)", 0));
        action_HelpAboutMe->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(A)", 0));
        action_HelpAboutMe->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        action_LanCHN->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menuLaser->setTitle(QApplication::translate("MainWindow", "\346\277\200\345\205\211", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", 0));
        menuSelect->setTitle(QApplication::translate("MainWindow", "\346\216\222\345\272\217", 0));
        menuBlock->setTitle(QApplication::translate("MainWindow", "\345\210\206\345\235\227", 0));
        menuOperate->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\351\200\211\345\217\226\351\233\225\345\210\273\345\216\237\347\202\271\342\200\246", 0));
        menuDebug->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225", 0));
        menu_StdMod->setTitle(QApplication::translate("MainWindow", "\346\240\207\345\207\206\346\250\241\345\236\213(S)", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menuLan->setTitle(QApplication::translate("MainWindow", "\350\257\255\350\250\200", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        gb_ModInfo->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\236\213\344\277\241\346\201\257", 0));
        lb_PointMinValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointNum->setText(QApplication::translate("MainWindow", "\346\200\273\347\202\271\346\225\260:", 0));
        lb_PointY->setText(QApplication::translate("MainWindow", "Y:", 0));
        lb_PointX->setText(QApplication::translate("MainWindow", "X:", 0));
        lb_PointZ->setText(QApplication::translate("MainWindow", "Z:", 0));
        lb_PointMinValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLen->setText(QApplication::translate("MainWindow", "\351\225\277\345\272\246", 0));
        lb_PointMin->setText(QApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274", 0));
        lb_PointMax->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274", 0));
        lb_PointObj->setText(QApplication::translate("MainWindow", "\346\235\220\346\226\231", 0));
        lb_PointNumVal->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMaxValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMinValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLenValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointObjValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMaxValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLenValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointObjValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMaxValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLenValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointObjValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        gb_CrvCtrl->setTitle(QApplication::translate("MainWindow", "\351\233\225\345\210\273\346\216\247\345\210\266", 0));
        lb_CrvT->setText(QApplication::translate("MainWindow", "\350\256\241\346\227\266:", 0));
        lb_CrvValT->setText(QApplication::translate("MainWindow", "0.0M0.0S", 0));
        lb_CrvPct->setText(QApplication::translate("MainWindow", "100%", 0));
#ifndef QT_NO_WHATSTHIS
        pb_Crv->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btn_CrvStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213(S)", 0));
        btn_CrvPause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234(P)", 0));
        btn_CrvStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242(T)", 0));
        btn_CrvClsLas->setText(QApplication::translate("MainWindow", "\345\205\263\346\277\200\345\205\211(L)", 0));
        gb_PlatCtrl->setTitle(QApplication::translate("MainWindow", "\345\271\263\345\217\260\346\216\247\345\210\266", 0));
        btn_PlatHome->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213(B)", 0));
        btn_PlatZero->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215(Z)", 0));
        btn_PlatReset->setText(QApplication::translate("MainWindow", "\346\234\272\346\242\260\345\244\215\344\275\215", 0));
        rbtn_PlatCo->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255", 0));
        btn_PlatXP->setText(QApplication::translate("MainWindow", "\345\217\263(X+)", 0));
        btn_PlatYP->setText(QApplication::translate("MainWindow", "\350\277\234(Y+)", 0));
        btn_PlatZP->setText(QApplication::translate("MainWindow", "\344\270\212(Z+)", 0));
        rbtn_PlatDe->setText(QApplication::translate("MainWindow", "\345\242\236\351\207\217", 0));
        btn_PlatXN->setText(QApplication::translate("MainWindow", "\345\267\246(X-)", 0));
        btn_PlatYN->setText(QApplication::translate("MainWindow", "\350\277\221(Y-)", 0));
        btn_PlatZN->setText(QApplication::translate("MainWindow", "\344\270\213(Z-)", 0));
        lb_PlatZ->setText(QApplication::translate("MainWindow", "Z:", 0));
        lb_PlatAbsValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatRelValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatRelValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatRelValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatAbsValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatAbsValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatY->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\271\205\351\235\242", 0));
        label_8->setText(QApplication::translate("MainWindow", "\345\271\205\351\235\242\350\256\276\347\275\256", 0));
        lb_PlatAbs->setText(QApplication::translate("MainWindow", "\346\234\272\346\242\260", 0));
        lb_PlatAxis->setText(QApplication::translate("MainWindow", "\350\275\264", 0));
        lb_PlatRel->setText(QApplication::translate("MainWindow", "\347\233\270\345\257\271", 0));
        lb_PlatX->setText(QApplication::translate("MainWindow", "X:", 0));
        lb_PlatMXYZ->setText(QApplication::translate("MainWindow", "X Y Z", 0));
        btn_PlatMRun->setText(QApplication::translate("MainWindow", "\345\211\215\345\276\200", 0));
        btn_PlatMStop->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\345\201\234", 0));
        gb_CrvEdit->setTitle(QApplication::translate("MainWindow", "\351\233\225\345\210\273\347\274\226\350\276\221", 0));
        lb_CrvMatS->setText(QApplication::translate("MainWindow", "\346\235\220\346\226\231\345\244\247\345\260\217(XYZ):", 0));
        btn_CrvView->setText(QApplication::translate("MainWindow", "\351\242\204\350\247\210", 0));
        lb_CrvModSz->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\213\345\201\217\347\247\273(XYZ):", 0));
        btn_ModMov->setText(QApplication::translate("MainWindow", "\345\201\217\347\247\273", 0));
        gb_BlkPara->setTitle(QApplication::translate("MainWindow", "\345\210\206\345\235\227\345\217\202\346\225\260", 0));
        lb_BlkXY->setText(QApplication::translate("MainWindow", "\345\210\206\345\235\227\345\244\247\345\260\217(XY):", 0));
        cb_BlkCen->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\345\257\271\344\275\215", 0));
        lb_BlkFuz->setText(QApplication::translate("MainWindow", "\346\250\241\347\263\212\345\270\246:", 0));
        rbtn_BlkUni->setText(QApplication::translate("MainWindow", "\345\235\207\345\214\200\345\210\206\345\270\203", 0));
        rbtn_BlkNor->setText(QApplication::translate("MainWindow", "\346\255\243\346\200\201\345\210\206\345\270\203", 0));
        lb_BlkW->setText(QApplication::translate("MainWindow", "\345\256\275\345\272\246:", 0));
        lb_BlkA->setText(QApplication::translate("MainWindow", "\350\247\222\345\272\246:", 0));
        lb_BlkSd->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\345\267\256:", 0));
        btn_BlkApp->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250", 0));
        gb_MCrvSel->setTitle(QApplication::translate("MainWindow", "\346\211\271\351\207\217\351\233\225\345\210\273\351\200\211\351\241\271", 0));
        cmb_MCrvSel->clear();
        cmb_MCrvSel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\215\225\346\250\241\345\236\213\345\215\225\346\254\241", 0)
         << QApplication::translate("MainWindow", "\345\215\225\346\250\241\345\236\213\346\211\271\351\207\217", 0)
         << QApplication::translate("MainWindow", "\345\244\232\346\250\241\345\236\213\346\211\271\351\207\217", 0)
        );
        cb_MCrvVo->setText(QApplication::translate("MainWindow", "\350\257\255\351\237\263\346\217\220\351\206\222", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
