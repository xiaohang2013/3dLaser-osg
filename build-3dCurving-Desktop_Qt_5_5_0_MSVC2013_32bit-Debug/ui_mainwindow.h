/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
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
    QAction *action_QuitApp;
    QAction *action_ParameterSettings;
    QAction *action_ImportReg;
    QAction *action_ExportReg;
    QAction *action_BatchSettings;
    QAction *action_TagGenerate;
    QAction *action_Calibration;
    QAction *action_TestPosition;
    QAction *action_PlatHorAdjust;
    QAction *action_ToolBar;
    QAction *action_ViewState;
    QAction *action_ViewCtrl;
    QAction *action_FrontView;
    QAction *action_TopView;
    QAction *action_RightView;
    QAction *action_UpdateView;
    QAction *action_RawModel;
    QAction *action_AmendModel;
    QAction *action_CutupModel;
    QAction *action_OriginSorting;
    QAction *action_SortY2X;
    QAction *action_SortX2Y;
    QAction *action_SortByShortestPath;
    QAction *action_BlockX2Y;
    QAction *action_BlockY2X;
    QAction *action_BlockByShortestPath;
    QAction *action_BlockParaGroup;
    QAction *action_CurPosAsHomePos;
    QAction *action_AlwaysSetCurPosAsHomePos;
    QAction *action_ResetMechPos;
    QAction *action_SelectHomePos1;
    QAction *action_AttachModel;
    QAction *action_SplitModel;
    QAction *action_HeatTest;
    QAction *action_DisableFunction;
    QAction *action_StdModLine;
    QAction *action_StdModPlane;
    QAction *action_StdModCube;
    QAction *action_StdModBall;
    QAction *action_AboutThis;
    QAction *action_LanCHN;
    QAction *action_ClearFileList;
    QAction *action_ClearPathList;
    QAction *action_Chinese;
    QAction *action_English;
    QAction *action_NewBlock;
    QAction *action_DeleteBlock;
    QAction *action_DeleteAllBlock;
    QAction *action_IncreaseArea;
    QAction *action_ReduceArea;
    QAction *action_ClearArea;
    QAction *action_NoBorder;
    QAction *action_LinearBorder;
    QAction *action_RandomBorder;
    QAction *action_LastBlock;
    QAction *action_NextBlock;
    QAction *action_StdModRightAngle;
    QAction *action_ClearAll;
    QWidget *CenWidget;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu_RecentFileList;
    QMenu *menu_RecentPathList;
    QMenu *menuLaser;
    QMenu *menuView;
    QMenu *menu_Language;
    QMenu *menuSorting;
    QMenu *menuBlock;
    QMenu *menuDebug;
    QMenu *menu_StdMod;
    QMenu *menuHelp;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_4;
    QWidget *paraWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *gb_ModInfo;
    QGridLayout *ly_gbModInfo_2;
    QLabel *lb_PointMinValZ;
    QLabel *lb_PointNum;
    QLabel *lb_PointY;
    QLabel *lb_PointX;
    QLabel *lb_PointZ;
    QLabel *lb_PointMinValY;
    QLabel *lb_PointLen;
    QLabel *lb_PointMin;
    QLabel *lb_PointMax;
    QLabel *lb_CrystalSize;
    QLabel *lb_PointNumVal;
    QLabel *lb_PointMaxValX;
    QLabel *lb_PointMinValX;
    QLabel *lb_PointLenValX;
    QLabel *lb_CrystalSizeValX;
    QLabel *lb_PointMaxValY;
    QLabel *lb_PointLenValY;
    QLabel *lb_CrystalSizeValY;
    QLabel *lb_PointMaxValZ;
    QLabel *lb_PointLenValZ;
    QLabel *lb_CrystalSizeValZ;
    QSpacerItem *sp_Point4;
    QSpacerItem *sp_Point2;
    QSpacerItem *sp_Point3;
    QSpacerItem *sp_Point1;
    QGroupBox *gb_CrvCtrl;
    QVBoxLayout *ly_gbCrvCtrl_2;
    QHBoxLayout *ly_CrvTimer;
    QLabel *lb_CrvTime;
    QLabel *lb_CrvTimeVal;
    QSpacerItem *sp_Crv1;
    QProgressBar *pb_Crv;
    QHBoxLayout *ly_CrvBtn;
    QPushButton *pb_Start;
    QPushButton *pb_Pause;
    QPushButton *pb_Stop;
    QPushButton *pb_LaserOnOff;
    QGroupBox *gb_PlatCtrl;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QPushButton *pb_MoveToHome;
    QPushButton *pb_ResetPos;
    QPushButton *pb_ResetMechPos;
    QPushButton *pb_MoveXP;
    QPushButton *pb_MoveYP;
    QPushButton *pb_MoveZP;
    QPushButton *pb_MoveXN;
    QPushButton *pb_MoveYN;
    QPushButton *pb_MoveZN;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *gb_OperateMode;
    QRadioButton *rb_ContinousMove;
    QRadioButton *rb_IncrementalMove;
    QDoubleSpinBox *dsb_IncreDis;
    QLabel *lb_IncreDis;
    QGridLayout *gridLayout_2;
    QLabel *lb_PlatAxis;
    QLabel *lb_PlatCurPos;
    QLabel *lb_PlatSize;
    QLabel *lb_PlatX;
    QLabel *lb_PlatCurPosValX;
    QLabel *lb_PlatSizeValX;
    QLabel *lb_PlatY;
    QLabel *lb_PlatCurPosValY;
    QLabel *lb_PlatSizeValY;
    QLabel *lb_PlatZ;
    QLabel *lb_PlatCurPosValZ;
    QLabel *lb_PlatSizeValZ;
    QGroupBox *gb_CrvEdit;
    QVBoxLayout *verticalLayout;
    QGroupBox *gb_CrystalSize;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_CrystalSizeX;
    QDoubleSpinBox *dsb_CrystalSizeX;
    QLabel *lb_CrystalSizeY;
    QDoubleSpinBox *dsb_CrystalSizeY;
    QLabel *lb_CrystalSizeZ;
    QDoubleSpinBox *dsp_CrystalSizeZ;
    QGroupBox *gb_ModelOffset;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_OffsetX;
    QDoubleSpinBox *dsb_ModelOffsetX;
    QLabel *lb_OffsetY;
    QDoubleSpinBox *dsb_ModelOffsetY;
    QLabel *lb_OffsetZ;
    QDoubleSpinBox *dsb_ModelOffsetZ;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lb_BoardThickness;
    QDoubleSpinBox *dsb_BoardThickness;
    QSpacerItem *sp_Point4_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_Preview;
    QSpacerItem *sp_Point4_2;
    QPushButton *pb_Apply;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1280, 822);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setBaseSize(QSize(0, 0));
        action_FileOpen = new QAction(MainWindow);
        action_FileOpen->setObjectName(QStringLiteral("action_FileOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/prefix/resource/fileOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_FileOpen->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        action_FileOpen->setFont(font);
        action_FileSave = new QAction(MainWindow);
        action_FileSave->setObjectName(QStringLiteral("action_FileSave"));
        action_QuitApp = new QAction(MainWindow);
        action_QuitApp->setObjectName(QStringLiteral("action_QuitApp"));
        action_ParameterSettings = new QAction(MainWindow);
        action_ParameterSettings->setObjectName(QStringLiteral("action_ParameterSettings"));
        action_ImportReg = new QAction(MainWindow);
        action_ImportReg->setObjectName(QStringLiteral("action_ImportReg"));
        action_ExportReg = new QAction(MainWindow);
        action_ExportReg->setObjectName(QStringLiteral("action_ExportReg"));
        action_BatchSettings = new QAction(MainWindow);
        action_BatchSettings->setObjectName(QStringLiteral("action_BatchSettings"));
        action_TagGenerate = new QAction(MainWindow);
        action_TagGenerate->setObjectName(QStringLiteral("action_TagGenerate"));
        action_Calibration = new QAction(MainWindow);
        action_Calibration->setObjectName(QStringLiteral("action_Calibration"));
        action_TestPosition = new QAction(MainWindow);
        action_TestPosition->setObjectName(QStringLiteral("action_TestPosition"));
        action_PlatHorAdjust = new QAction(MainWindow);
        action_PlatHorAdjust->setObjectName(QStringLiteral("action_PlatHorAdjust"));
        action_ToolBar = new QAction(MainWindow);
        action_ToolBar->setObjectName(QStringLiteral("action_ToolBar"));
        action_ToolBar->setCheckable(true);
        action_ToolBar->setChecked(true);
        action_ViewState = new QAction(MainWindow);
        action_ViewState->setObjectName(QStringLiteral("action_ViewState"));
        action_ViewState->setCheckable(true);
        action_ViewState->setChecked(true);
        action_ViewCtrl = new QAction(MainWindow);
        action_ViewCtrl->setObjectName(QStringLiteral("action_ViewCtrl"));
        action_ViewCtrl->setCheckable(true);
        action_ViewCtrl->setChecked(true);
        action_FrontView = new QAction(MainWindow);
        action_FrontView->setObjectName(QStringLiteral("action_FrontView"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/prefix/resource/front-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_FrontView->setIcon(icon1);
        action_TopView = new QAction(MainWindow);
        action_TopView->setObjectName(QStringLiteral("action_TopView"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/prefix/resource/top-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_TopView->setIcon(icon2);
        action_RightView = new QAction(MainWindow);
        action_RightView->setObjectName(QStringLiteral("action_RightView"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/prefix/resource/right-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_RightView->setIcon(icon3);
        action_UpdateView = new QAction(MainWindow);
        action_UpdateView->setObjectName(QStringLiteral("action_UpdateView"));
        action_UpdateView->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/prefix/resource/refresh.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_UpdateView->setIcon(icon4);
        action_RawModel = new QAction(MainWindow);
        action_RawModel->setObjectName(QStringLiteral("action_RawModel"));
        action_RawModel->setCheckable(true);
        action_RawModel->setChecked(true);
        action_RawModel->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/prefix/resource/center-side.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_RawModel->setIcon(icon5);
        action_AmendModel = new QAction(MainWindow);
        action_AmendModel->setObjectName(QStringLiteral("action_AmendModel"));
        action_AmendModel->setEnabled(false);
        action_CutupModel = new QAction(MainWindow);
        action_CutupModel->setObjectName(QStringLiteral("action_CutupModel"));
        action_CutupModel->setEnabled(false);
        action_OriginSorting = new QAction(MainWindow);
        action_OriginSorting->setObjectName(QStringLiteral("action_OriginSorting"));
        action_SortY2X = new QAction(MainWindow);
        action_SortY2X->setObjectName(QStringLiteral("action_SortY2X"));
        action_SortX2Y = new QAction(MainWindow);
        action_SortX2Y->setObjectName(QStringLiteral("action_SortX2Y"));
        action_SortByShortestPath = new QAction(MainWindow);
        action_SortByShortestPath->setObjectName(QStringLiteral("action_SortByShortestPath"));
        action_SortByShortestPath->setCheckable(true);
        action_SortByShortestPath->setChecked(true);
        action_SortByShortestPath->setEnabled(false);
        action_BlockX2Y = new QAction(MainWindow);
        action_BlockX2Y->setObjectName(QStringLiteral("action_BlockX2Y"));
        action_BlockX2Y->setCheckable(false);
        action_BlockX2Y->setChecked(false);
        action_BlockX2Y->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/prefix/resource/b-X2Y.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_BlockX2Y->setIcon(icon6);
        action_BlockY2X = new QAction(MainWindow);
        action_BlockY2X->setObjectName(QStringLiteral("action_BlockY2X"));
        action_BlockY2X->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/prefix/resource/b-Y2X.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_BlockY2X->setIcon(icon7);
        action_BlockByShortestPath = new QAction(MainWindow);
        action_BlockByShortestPath->setObjectName(QStringLiteral("action_BlockByShortestPath"));
        action_BlockByShortestPath->setEnabled(false);
        action_BlockParaGroup = new QAction(MainWindow);
        action_BlockParaGroup->setObjectName(QStringLiteral("action_BlockParaGroup"));
        action_BlockParaGroup->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/prefix/resource/mirror.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_BlockParaGroup->setIcon(icon8);
        action_CurPosAsHomePos = new QAction(MainWindow);
        action_CurPosAsHomePos->setObjectName(QStringLiteral("action_CurPosAsHomePos"));
        action_AlwaysSetCurPosAsHomePos = new QAction(MainWindow);
        action_AlwaysSetCurPosAsHomePos->setObjectName(QStringLiteral("action_AlwaysSetCurPosAsHomePos"));
        action_AlwaysSetCurPosAsHomePos->setCheckable(true);
        action_AlwaysSetCurPosAsHomePos->setChecked(false);
        action_ResetMechPos = new QAction(MainWindow);
        action_ResetMechPos->setObjectName(QStringLiteral("action_ResetMechPos"));
        action_SelectHomePos1 = new QAction(MainWindow);
        action_SelectHomePos1->setObjectName(QStringLiteral("action_SelectHomePos1"));
        action_AttachModel = new QAction(MainWindow);
        action_AttachModel->setObjectName(QStringLiteral("action_AttachModel"));
        action_SplitModel = new QAction(MainWindow);
        action_SplitModel->setObjectName(QStringLiteral("action_SplitModel"));
        action_HeatTest = new QAction(MainWindow);
        action_HeatTest->setObjectName(QStringLiteral("action_HeatTest"));
        action_DisableFunction = new QAction(MainWindow);
        action_DisableFunction->setObjectName(QStringLiteral("action_DisableFunction"));
        action_StdModLine = new QAction(MainWindow);
        action_StdModLine->setObjectName(QStringLiteral("action_StdModLine"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/prefix/resource/line.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StdModLine->setIcon(icon9);
        action_StdModPlane = new QAction(MainWindow);
        action_StdModPlane->setObjectName(QStringLiteral("action_StdModPlane"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/prefix/resource/parallel.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StdModPlane->setIcon(icon10);
        action_StdModCube = new QAction(MainWindow);
        action_StdModCube->setObjectName(QStringLiteral("action_StdModCube"));
        action_StdModBall = new QAction(MainWindow);
        action_StdModBall->setObjectName(QStringLiteral("action_StdModBall"));
        action_AboutThis = new QAction(MainWindow);
        action_AboutThis->setObjectName(QStringLiteral("action_AboutThis"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/prefix/resource/info.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_AboutThis->setIcon(icon11);
        action_LanCHN = new QAction(MainWindow);
        action_LanCHN->setObjectName(QStringLiteral("action_LanCHN"));
        action_ClearFileList = new QAction(MainWindow);
        action_ClearFileList->setObjectName(QStringLiteral("action_ClearFileList"));
        action_ClearPathList = new QAction(MainWindow);
        action_ClearPathList->setObjectName(QStringLiteral("action_ClearPathList"));
        action_Chinese = new QAction(MainWindow);
        action_Chinese->setObjectName(QStringLiteral("action_Chinese"));
        action_English = new QAction(MainWindow);
        action_English->setObjectName(QStringLiteral("action_English"));
        action_NewBlock = new QAction(MainWindow);
        action_NewBlock->setObjectName(QStringLiteral("action_NewBlock"));
        action_DeleteBlock = new QAction(MainWindow);
        action_DeleteBlock->setObjectName(QStringLiteral("action_DeleteBlock"));
        action_DeleteAllBlock = new QAction(MainWindow);
        action_DeleteAllBlock->setObjectName(QStringLiteral("action_DeleteAllBlock"));
        action_IncreaseArea = new QAction(MainWindow);
        action_IncreaseArea->setObjectName(QStringLiteral("action_IncreaseArea"));
        action_ReduceArea = new QAction(MainWindow);
        action_ReduceArea->setObjectName(QStringLiteral("action_ReduceArea"));
        action_ClearArea = new QAction(MainWindow);
        action_ClearArea->setObjectName(QStringLiteral("action_ClearArea"));
        action_NoBorder = new QAction(MainWindow);
        action_NoBorder->setObjectName(QStringLiteral("action_NoBorder"));
        action_LinearBorder = new QAction(MainWindow);
        action_LinearBorder->setObjectName(QStringLiteral("action_LinearBorder"));
        action_RandomBorder = new QAction(MainWindow);
        action_RandomBorder->setObjectName(QStringLiteral("action_RandomBorder"));
        action_LastBlock = new QAction(MainWindow);
        action_LastBlock->setObjectName(QStringLiteral("action_LastBlock"));
        action_NextBlock = new QAction(MainWindow);
        action_NextBlock->setObjectName(QStringLiteral("action_NextBlock"));
        action_StdModRightAngle = new QAction(MainWindow);
        action_StdModRightAngle->setObjectName(QStringLiteral("action_StdModRightAngle"));
        action_ClearAll = new QAction(MainWindow);
        action_ClearAll->setObjectName(QStringLiteral("action_ClearAll"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/prefix/resource/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ClearAll->setIcon(icon12);
        CenWidget = new QWidget(MainWindow);
        CenWidget->setObjectName(QStringLiteral("CenWidget"));
        sizePolicy.setHeightForWidth(CenWidget->sizePolicy().hasHeightForWidth());
        CenWidget->setSizePolicy(sizePolicy);
        CenWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(CenWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(CenWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu_RecentFileList = new QMenu(menuFile);
        menu_RecentFileList->setObjectName(QStringLiteral("menu_RecentFileList"));
        menu_RecentPathList = new QMenu(menuFile);
        menu_RecentPathList->setObjectName(QStringLiteral("menu_RecentPathList"));
        menuLaser = new QMenu(menuBar);
        menuLaser->setObjectName(QStringLiteral("menuLaser"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menu_Language = new QMenu(menuView);
        menu_Language->setObjectName(QStringLiteral("menu_Language"));
        menuSorting = new QMenu(menuBar);
        menuSorting->setObjectName(QStringLiteral("menuSorting"));
        menuBlock = new QMenu(menuBar);
        menuBlock->setObjectName(QStringLiteral("menuBlock"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        menu_StdMod = new QMenu(menuDebug);
        menu_StdMod->setObjectName(QStringLiteral("menu_StdMod"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy1);
        statusBar->setMinimumSize(QSize(0, 22));
        statusBar->setMaximumSize(QSize(16777215, 22));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(350, 42));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        paraWidget = new QWidget(dockWidgetContents_4);
        paraWidget->setObjectName(QStringLiteral("paraWidget"));
        paraWidget->setGeometry(QRect(0, 0, 350, 774));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(paraWidget->sizePolicy().hasHeightForWidth());
        paraWidget->setSizePolicy(sizePolicy2);
        paraWidget->setMinimumSize(QSize(350, 0));
        paraWidget->setMaximumSize(QSize(350, 16777215));
        verticalLayout_3 = new QVBoxLayout(paraWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gb_ModInfo = new QGroupBox(paraWidget);
        gb_ModInfo->setObjectName(QStringLiteral("gb_ModInfo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(gb_ModInfo->sizePolicy().hasHeightForWidth());
        gb_ModInfo->setSizePolicy(sizePolicy3);
        gb_ModInfo->setMinimumSize(QSize(0, 0));
        ly_gbModInfo_2 = new QGridLayout(gb_ModInfo);
        ly_gbModInfo_2->setSpacing(1);
        ly_gbModInfo_2->setContentsMargins(11, 11, 11, 11);
        ly_gbModInfo_2->setObjectName(QStringLiteral("ly_gbModInfo_2"));
        ly_gbModInfo_2->setContentsMargins(3, 0, 3, 0);
        lb_PointMinValZ = new QLabel(gb_ModInfo);
        lb_PointMinValZ->setObjectName(QStringLiteral("lb_PointMinValZ"));
        lb_PointMinValZ->setScaledContents(false);
        lb_PointMinValZ->setAlignment(Qt::AlignCenter);
        lb_PointMinValZ->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMinValZ, 4, 1, 1, 1);

        lb_PointNum = new QLabel(gb_ModInfo);
        lb_PointNum->setObjectName(QStringLiteral("lb_PointNum"));
        lb_PointNum->setScaledContents(false);
        lb_PointNum->setAlignment(Qt::AlignCenter);
        lb_PointNum->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointNum, 0, 0, 1, 1);

        lb_PointY = new QLabel(gb_ModInfo);
        lb_PointY->setObjectName(QStringLiteral("lb_PointY"));
        lb_PointY->setScaledContents(false);
        lb_PointY->setAlignment(Qt::AlignCenter);
        lb_PointY->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointY, 3, 0, 1, 1);

        lb_PointX = new QLabel(gb_ModInfo);
        lb_PointX->setObjectName(QStringLiteral("lb_PointX"));
        lb_PointX->setScaledContents(false);
        lb_PointX->setAlignment(Qt::AlignCenter);
        lb_PointX->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointX, 2, 0, 1, 1);

        lb_PointZ = new QLabel(gb_ModInfo);
        lb_PointZ->setObjectName(QStringLiteral("lb_PointZ"));
        lb_PointZ->setScaledContents(false);
        lb_PointZ->setAlignment(Qt::AlignCenter);
        lb_PointZ->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointZ, 4, 0, 1, 1);

        lb_PointMinValY = new QLabel(gb_ModInfo);
        lb_PointMinValY->setObjectName(QStringLiteral("lb_PointMinValY"));
        lb_PointMinValY->setScaledContents(false);
        lb_PointMinValY->setAlignment(Qt::AlignCenter);
        lb_PointMinValY->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMinValY, 3, 1, 1, 1);

        lb_PointLen = new QLabel(gb_ModInfo);
        lb_PointLen->setObjectName(QStringLiteral("lb_PointLen"));
        lb_PointLen->setScaledContents(false);
        lb_PointLen->setAlignment(Qt::AlignCenter);
        lb_PointLen->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointLen, 1, 3, 1, 1);

        lb_PointMin = new QLabel(gb_ModInfo);
        lb_PointMin->setObjectName(QStringLiteral("lb_PointMin"));
        lb_PointMin->setScaledContents(false);
        lb_PointMin->setAlignment(Qt::AlignCenter);
        lb_PointMin->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMin, 1, 1, 1, 1);

        lb_PointMax = new QLabel(gb_ModInfo);
        lb_PointMax->setObjectName(QStringLiteral("lb_PointMax"));
        lb_PointMax->setScaledContents(false);
        lb_PointMax->setAlignment(Qt::AlignCenter);
        lb_PointMax->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMax, 1, 2, 1, 1);

        lb_CrystalSize = new QLabel(gb_ModInfo);
        lb_CrystalSize->setObjectName(QStringLiteral("lb_CrystalSize"));
        lb_CrystalSize->setScaledContents(false);
        lb_CrystalSize->setAlignment(Qt::AlignCenter);
        lb_CrystalSize->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_CrystalSize, 1, 4, 1, 1);

        lb_PointNumVal = new QLabel(gb_ModInfo);
        lb_PointNumVal->setObjectName(QStringLiteral("lb_PointNumVal"));
        lb_PointNumVal->setScaledContents(false);
        lb_PointNumVal->setAlignment(Qt::AlignCenter);
        lb_PointNumVal->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointNumVal, 0, 1, 1, 1);

        lb_PointMaxValX = new QLabel(gb_ModInfo);
        lb_PointMaxValX->setObjectName(QStringLiteral("lb_PointMaxValX"));
        lb_PointMaxValX->setScaledContents(false);
        lb_PointMaxValX->setAlignment(Qt::AlignCenter);
        lb_PointMaxValX->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMaxValX, 2, 2, 1, 1);

        lb_PointMinValX = new QLabel(gb_ModInfo);
        lb_PointMinValX->setObjectName(QStringLiteral("lb_PointMinValX"));
        lb_PointMinValX->setScaledContents(false);
        lb_PointMinValX->setAlignment(Qt::AlignCenter);
        lb_PointMinValX->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMinValX, 2, 1, 1, 1);

        lb_PointLenValX = new QLabel(gb_ModInfo);
        lb_PointLenValX->setObjectName(QStringLiteral("lb_PointLenValX"));
        lb_PointLenValX->setScaledContents(false);
        lb_PointLenValX->setAlignment(Qt::AlignCenter);
        lb_PointLenValX->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointLenValX, 2, 3, 1, 1);

        lb_CrystalSizeValX = new QLabel(gb_ModInfo);
        lb_CrystalSizeValX->setObjectName(QStringLiteral("lb_CrystalSizeValX"));
        lb_CrystalSizeValX->setScaledContents(false);
        lb_CrystalSizeValX->setAlignment(Qt::AlignCenter);
        lb_CrystalSizeValX->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_CrystalSizeValX, 2, 4, 1, 1);

        lb_PointMaxValY = new QLabel(gb_ModInfo);
        lb_PointMaxValY->setObjectName(QStringLiteral("lb_PointMaxValY"));
        lb_PointMaxValY->setScaledContents(false);
        lb_PointMaxValY->setAlignment(Qt::AlignCenter);
        lb_PointMaxValY->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMaxValY, 3, 2, 1, 1);

        lb_PointLenValY = new QLabel(gb_ModInfo);
        lb_PointLenValY->setObjectName(QStringLiteral("lb_PointLenValY"));
        lb_PointLenValY->setScaledContents(false);
        lb_PointLenValY->setAlignment(Qt::AlignCenter);
        lb_PointLenValY->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointLenValY, 3, 3, 1, 1);

        lb_CrystalSizeValY = new QLabel(gb_ModInfo);
        lb_CrystalSizeValY->setObjectName(QStringLiteral("lb_CrystalSizeValY"));
        lb_CrystalSizeValY->setScaledContents(false);
        lb_CrystalSizeValY->setAlignment(Qt::AlignCenter);
        lb_CrystalSizeValY->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_CrystalSizeValY, 3, 4, 1, 1);

        lb_PointMaxValZ = new QLabel(gb_ModInfo);
        lb_PointMaxValZ->setObjectName(QStringLiteral("lb_PointMaxValZ"));
        lb_PointMaxValZ->setScaledContents(false);
        lb_PointMaxValZ->setAlignment(Qt::AlignCenter);
        lb_PointMaxValZ->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointMaxValZ, 4, 2, 1, 1);

        lb_PointLenValZ = new QLabel(gb_ModInfo);
        lb_PointLenValZ->setObjectName(QStringLiteral("lb_PointLenValZ"));
        lb_PointLenValZ->setScaledContents(false);
        lb_PointLenValZ->setAlignment(Qt::AlignCenter);
        lb_PointLenValZ->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_PointLenValZ, 4, 3, 1, 1);

        lb_CrystalSizeValZ = new QLabel(gb_ModInfo);
        lb_CrystalSizeValZ->setObjectName(QStringLiteral("lb_CrystalSizeValZ"));
        lb_CrystalSizeValZ->setScaledContents(false);
        lb_CrystalSizeValZ->setAlignment(Qt::AlignCenter);
        lb_CrystalSizeValZ->setWordWrap(false);

        ly_gbModInfo_2->addWidget(lb_CrystalSizeValZ, 4, 4, 1, 1);

        sp_Point4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo_2->addItem(sp_Point4, 1, 0, 1, 1);

        sp_Point2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo_2->addItem(sp_Point2, 0, 2, 1, 1);

        sp_Point3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo_2->addItem(sp_Point3, 0, 3, 1, 1);

        sp_Point1 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        ly_gbModInfo_2->addItem(sp_Point1, 0, 4, 1, 1);


        verticalLayout_3->addWidget(gb_ModInfo);

        gb_CrvCtrl = new QGroupBox(paraWidget);
        gb_CrvCtrl->setObjectName(QStringLiteral("gb_CrvCtrl"));
        sizePolicy1.setHeightForWidth(gb_CrvCtrl->sizePolicy().hasHeightForWidth());
        gb_CrvCtrl->setSizePolicy(sizePolicy1);
        ly_gbCrvCtrl_2 = new QVBoxLayout(gb_CrvCtrl);
        ly_gbCrvCtrl_2->setSpacing(1);
        ly_gbCrvCtrl_2->setContentsMargins(11, 11, 11, 11);
        ly_gbCrvCtrl_2->setObjectName(QStringLiteral("ly_gbCrvCtrl_2"));
        ly_gbCrvCtrl_2->setContentsMargins(3, 0, 3, 3);
        ly_CrvTimer = new QHBoxLayout();
        ly_CrvTimer->setSpacing(1);
        ly_CrvTimer->setObjectName(QStringLiteral("ly_CrvTimer"));
        lb_CrvTime = new QLabel(gb_CrvCtrl);
        lb_CrvTime->setObjectName(QStringLiteral("lb_CrvTime"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lb_CrvTime->sizePolicy().hasHeightForWidth());
        lb_CrvTime->setSizePolicy(sizePolicy4);

        ly_CrvTimer->addWidget(lb_CrvTime);

        lb_CrvTimeVal = new QLabel(gb_CrvCtrl);
        lb_CrvTimeVal->setObjectName(QStringLiteral("lb_CrvTimeVal"));
        sizePolicy3.setHeightForWidth(lb_CrvTimeVal->sizePolicy().hasHeightForWidth());
        lb_CrvTimeVal->setSizePolicy(sizePolicy3);

        ly_CrvTimer->addWidget(lb_CrvTimeVal);

        sp_Crv1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ly_CrvTimer->addItem(sp_Crv1);


        ly_gbCrvCtrl_2->addLayout(ly_CrvTimer);

        pb_Crv = new QProgressBar(gb_CrvCtrl);
        pb_Crv->setObjectName(QStringLiteral("pb_Crv"));
        sizePolicy1.setHeightForWidth(pb_Crv->sizePolicy().hasHeightForWidth());
        pb_Crv->setSizePolicy(sizePolicy1);
        pb_Crv->setAutoFillBackground(false);
        pb_Crv->setValue(0);
        pb_Crv->setTextVisible(true);
        pb_Crv->setTextDirection(QProgressBar::TopToBottom);

        ly_gbCrvCtrl_2->addWidget(pb_Crv);

        ly_CrvBtn = new QHBoxLayout();
        ly_CrvBtn->setSpacing(1);
        ly_CrvBtn->setObjectName(QStringLiteral("ly_CrvBtn"));
        ly_CrvBtn->setSizeConstraint(QLayout::SetDefaultConstraint);
        pb_Start = new QPushButton(gb_CrvCtrl);
        pb_Start->setObjectName(QStringLiteral("pb_Start"));
        sizePolicy1.setHeightForWidth(pb_Start->sizePolicy().hasHeightForWidth());
        pb_Start->setSizePolicy(sizePolicy1);

        ly_CrvBtn->addWidget(pb_Start);

        pb_Pause = new QPushButton(gb_CrvCtrl);
        pb_Pause->setObjectName(QStringLiteral("pb_Pause"));
        sizePolicy1.setHeightForWidth(pb_Pause->sizePolicy().hasHeightForWidth());
        pb_Pause->setSizePolicy(sizePolicy1);

        ly_CrvBtn->addWidget(pb_Pause);

        pb_Stop = new QPushButton(gb_CrvCtrl);
        pb_Stop->setObjectName(QStringLiteral("pb_Stop"));
        sizePolicy1.setHeightForWidth(pb_Stop->sizePolicy().hasHeightForWidth());
        pb_Stop->setSizePolicy(sizePolicy1);

        ly_CrvBtn->addWidget(pb_Stop);

        pb_LaserOnOff = new QPushButton(gb_CrvCtrl);
        pb_LaserOnOff->setObjectName(QStringLiteral("pb_LaserOnOff"));
        sizePolicy1.setHeightForWidth(pb_LaserOnOff->sizePolicy().hasHeightForWidth());
        pb_LaserOnOff->setSizePolicy(sizePolicy1);
        pb_LaserOnOff->setMinimumSize(QSize(0, 0));
        pb_LaserOnOff->setMaximumSize(QSize(16777215, 16777215));

        ly_CrvBtn->addWidget(pb_LaserOnOff);


        ly_gbCrvCtrl_2->addLayout(ly_CrvBtn);

        pb_Crv->raise();

        verticalLayout_3->addWidget(gb_CrvCtrl);

        gb_PlatCtrl = new QGroupBox(paraWidget);
        gb_PlatCtrl->setObjectName(QStringLiteral("gb_PlatCtrl"));
        verticalLayout_2 = new QVBoxLayout(gb_PlatCtrl);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pb_MoveToHome = new QPushButton(gb_PlatCtrl);
        pb_MoveToHome->setObjectName(QStringLiteral("pb_MoveToHome"));
        sizePolicy3.setHeightForWidth(pb_MoveToHome->sizePolicy().hasHeightForWidth());
        pb_MoveToHome->setSizePolicy(sizePolicy3);
        pb_MoveToHome->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveToHome, 0, 0, 1, 1);

        pb_ResetPos = new QPushButton(gb_PlatCtrl);
        pb_ResetPos->setObjectName(QStringLiteral("pb_ResetPos"));
        sizePolicy3.setHeightForWidth(pb_ResetPos->sizePolicy().hasHeightForWidth());
        pb_ResetPos->setSizePolicy(sizePolicy3);
        pb_ResetPos->setAutoDefault(false);

        gridLayout_3->addWidget(pb_ResetPos, 0, 1, 1, 1);

        pb_ResetMechPos = new QPushButton(gb_PlatCtrl);
        pb_ResetMechPos->setObjectName(QStringLiteral("pb_ResetMechPos"));
        sizePolicy3.setHeightForWidth(pb_ResetMechPos->sizePolicy().hasHeightForWidth());
        pb_ResetMechPos->setSizePolicy(sizePolicy3);
        pb_ResetMechPos->setAutoDefault(false);

        gridLayout_3->addWidget(pb_ResetMechPos, 0, 2, 1, 1);

        pb_MoveXP = new QPushButton(gb_PlatCtrl);
        pb_MoveXP->setObjectName(QStringLiteral("pb_MoveXP"));
        sizePolicy3.setHeightForWidth(pb_MoveXP->sizePolicy().hasHeightForWidth());
        pb_MoveXP->setSizePolicy(sizePolicy3);
        pb_MoveXP->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveXP, 1, 0, 1, 1);

        pb_MoveYP = new QPushButton(gb_PlatCtrl);
        pb_MoveYP->setObjectName(QStringLiteral("pb_MoveYP"));
        sizePolicy3.setHeightForWidth(pb_MoveYP->sizePolicy().hasHeightForWidth());
        pb_MoveYP->setSizePolicy(sizePolicy3);
        pb_MoveYP->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveYP, 1, 1, 1, 1);

        pb_MoveZP = new QPushButton(gb_PlatCtrl);
        pb_MoveZP->setObjectName(QStringLiteral("pb_MoveZP"));
        sizePolicy3.setHeightForWidth(pb_MoveZP->sizePolicy().hasHeightForWidth());
        pb_MoveZP->setSizePolicy(sizePolicy3);
        pb_MoveZP->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveZP, 1, 2, 1, 1);

        pb_MoveXN = new QPushButton(gb_PlatCtrl);
        pb_MoveXN->setObjectName(QStringLiteral("pb_MoveXN"));
        sizePolicy3.setHeightForWidth(pb_MoveXN->sizePolicy().hasHeightForWidth());
        pb_MoveXN->setSizePolicy(sizePolicy3);
        pb_MoveXN->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveXN, 2, 0, 1, 1);

        pb_MoveYN = new QPushButton(gb_PlatCtrl);
        pb_MoveYN->setObjectName(QStringLiteral("pb_MoveYN"));
        sizePolicy3.setHeightForWidth(pb_MoveYN->sizePolicy().hasHeightForWidth());
        pb_MoveYN->setSizePolicy(sizePolicy3);
        pb_MoveYN->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveYN, 2, 1, 1, 1);

        pb_MoveZN = new QPushButton(gb_PlatCtrl);
        pb_MoveZN->setObjectName(QStringLiteral("pb_MoveZN"));
        sizePolicy3.setHeightForWidth(pb_MoveZN->sizePolicy().hasHeightForWidth());
        pb_MoveZN->setSizePolicy(sizePolicy3);
        pb_MoveZN->setAutoDefault(false);

        gridLayout_3->addWidget(pb_MoveZN, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gb_OperateMode = new QGroupBox(gb_PlatCtrl);
        gb_OperateMode->setObjectName(QStringLiteral("gb_OperateMode"));
        rb_ContinousMove = new QRadioButton(gb_OperateMode);
        rb_ContinousMove->setObjectName(QStringLiteral("rb_ContinousMove"));
        rb_ContinousMove->setGeometry(QRect(10, 20, 53, 20));
        sizePolicy1.setHeightForWidth(rb_ContinousMove->sizePolicy().hasHeightForWidth());
        rb_ContinousMove->setSizePolicy(sizePolicy1);
        rb_IncrementalMove = new QRadioButton(gb_OperateMode);
        rb_IncrementalMove->setObjectName(QStringLiteral("rb_IncrementalMove"));
        rb_IncrementalMove->setGeometry(QRect(10, 40, 53, 20));
        sizePolicy1.setHeightForWidth(rb_IncrementalMove->sizePolicy().hasHeightForWidth());
        rb_IncrementalMove->setSizePolicy(sizePolicy1);
        dsb_IncreDis = new QDoubleSpinBox(gb_OperateMode);
        dsb_IncreDis->setObjectName(QStringLiteral("dsb_IncreDis"));
        dsb_IncreDis->setGeometry(QRect(10, 60, 71, 22));
        sizePolicy1.setHeightForWidth(dsb_IncreDis->sizePolicy().hasHeightForWidth());
        dsb_IncreDis->setSizePolicy(sizePolicy1);
        dsb_IncreDis->setMaximum(999999);
        lb_IncreDis = new QLabel(gb_OperateMode);
        lb_IncreDis->setObjectName(QStringLiteral("lb_IncreDis"));
        lb_IncreDis->setGeometry(QRect(80, 60, 31, 22));
        sizePolicy3.setHeightForWidth(lb_IncreDis->sizePolicy().hasHeightForWidth());
        lb_IncreDis->setSizePolicy(sizePolicy3);
        lb_IncreDis->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(gb_OperateMode);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lb_PlatAxis = new QLabel(gb_PlatCtrl);
        lb_PlatAxis->setObjectName(QStringLiteral("lb_PlatAxis"));

        gridLayout_2->addWidget(lb_PlatAxis, 0, 0, 1, 1);

        lb_PlatCurPos = new QLabel(gb_PlatCtrl);
        lb_PlatCurPos->setObjectName(QStringLiteral("lb_PlatCurPos"));

        gridLayout_2->addWidget(lb_PlatCurPos, 0, 1, 1, 1);

        lb_PlatSize = new QLabel(gb_PlatCtrl);
        lb_PlatSize->setObjectName(QStringLiteral("lb_PlatSize"));

        gridLayout_2->addWidget(lb_PlatSize, 0, 2, 1, 1);

        lb_PlatX = new QLabel(gb_PlatCtrl);
        lb_PlatX->setObjectName(QStringLiteral("lb_PlatX"));
        sizePolicy3.setHeightForWidth(lb_PlatX->sizePolicy().hasHeightForWidth());
        lb_PlatX->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(lb_PlatX, 1, 0, 1, 1);

        lb_PlatCurPosValX = new QLabel(gb_PlatCtrl);
        lb_PlatCurPosValX->setObjectName(QStringLiteral("lb_PlatCurPosValX"));

        gridLayout_2->addWidget(lb_PlatCurPosValX, 1, 1, 1, 1);

        lb_PlatSizeValX = new QLabel(gb_PlatCtrl);
        lb_PlatSizeValX->setObjectName(QStringLiteral("lb_PlatSizeValX"));

        gridLayout_2->addWidget(lb_PlatSizeValX, 1, 2, 1, 1);

        lb_PlatY = new QLabel(gb_PlatCtrl);
        lb_PlatY->setObjectName(QStringLiteral("lb_PlatY"));

        gridLayout_2->addWidget(lb_PlatY, 2, 0, 1, 1);

        lb_PlatCurPosValY = new QLabel(gb_PlatCtrl);
        lb_PlatCurPosValY->setObjectName(QStringLiteral("lb_PlatCurPosValY"));

        gridLayout_2->addWidget(lb_PlatCurPosValY, 2, 1, 1, 1);

        lb_PlatSizeValY = new QLabel(gb_PlatCtrl);
        lb_PlatSizeValY->setObjectName(QStringLiteral("lb_PlatSizeValY"));

        gridLayout_2->addWidget(lb_PlatSizeValY, 2, 2, 1, 1);

        lb_PlatZ = new QLabel(gb_PlatCtrl);
        lb_PlatZ->setObjectName(QStringLiteral("lb_PlatZ"));

        gridLayout_2->addWidget(lb_PlatZ, 3, 0, 1, 1);

        lb_PlatCurPosValZ = new QLabel(gb_PlatCtrl);
        lb_PlatCurPosValZ->setObjectName(QStringLiteral("lb_PlatCurPosValZ"));

        gridLayout_2->addWidget(lb_PlatCurPosValZ, 3, 1, 1, 1);

        lb_PlatSizeValZ = new QLabel(gb_PlatCtrl);
        lb_PlatSizeValZ->setObjectName(QStringLiteral("lb_PlatSizeValZ"));

        gridLayout_2->addWidget(lb_PlatSizeValZ, 3, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(gb_PlatCtrl);

        gb_CrvEdit = new QGroupBox(paraWidget);
        gb_CrvEdit->setObjectName(QStringLiteral("gb_CrvEdit"));
        verticalLayout = new QVBoxLayout(gb_CrvEdit);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gb_CrystalSize = new QGroupBox(gb_CrvEdit);
        gb_CrystalSize->setObjectName(QStringLiteral("gb_CrystalSize"));
        horizontalLayout_3 = new QHBoxLayout(gb_CrystalSize);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lb_CrystalSizeX = new QLabel(gb_CrystalSize);
        lb_CrystalSizeX->setObjectName(QStringLiteral("lb_CrystalSizeX"));
        sizePolicy3.setHeightForWidth(lb_CrystalSizeX->sizePolicy().hasHeightForWidth());
        lb_CrystalSizeX->setSizePolicy(sizePolicy3);
        lb_CrystalSizeX->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(lb_CrystalSizeX);

        dsb_CrystalSizeX = new QDoubleSpinBox(gb_CrystalSize);
        dsb_CrystalSizeX->setObjectName(QStringLiteral("dsb_CrystalSizeX"));
        sizePolicy1.setHeightForWidth(dsb_CrystalSizeX->sizePolicy().hasHeightForWidth());
        dsb_CrystalSizeX->setSizePolicy(sizePolicy1);
        dsb_CrystalSizeX->setMaximum(999999);

        horizontalLayout_3->addWidget(dsb_CrystalSizeX);

        lb_CrystalSizeY = new QLabel(gb_CrystalSize);
        lb_CrystalSizeY->setObjectName(QStringLiteral("lb_CrystalSizeY"));
        sizePolicy3.setHeightForWidth(lb_CrystalSizeY->sizePolicy().hasHeightForWidth());
        lb_CrystalSizeY->setSizePolicy(sizePolicy3);
        lb_CrystalSizeY->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(lb_CrystalSizeY);

        dsb_CrystalSizeY = new QDoubleSpinBox(gb_CrystalSize);
        dsb_CrystalSizeY->setObjectName(QStringLiteral("dsb_CrystalSizeY"));
        sizePolicy1.setHeightForWidth(dsb_CrystalSizeY->sizePolicy().hasHeightForWidth());
        dsb_CrystalSizeY->setSizePolicy(sizePolicy1);
        dsb_CrystalSizeY->setMaximum(999999);

        horizontalLayout_3->addWidget(dsb_CrystalSizeY);

        lb_CrystalSizeZ = new QLabel(gb_CrystalSize);
        lb_CrystalSizeZ->setObjectName(QStringLiteral("lb_CrystalSizeZ"));
        sizePolicy3.setHeightForWidth(lb_CrystalSizeZ->sizePolicy().hasHeightForWidth());
        lb_CrystalSizeZ->setSizePolicy(sizePolicy3);
        lb_CrystalSizeZ->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(lb_CrystalSizeZ);

        dsp_CrystalSizeZ = new QDoubleSpinBox(gb_CrystalSize);
        dsp_CrystalSizeZ->setObjectName(QStringLiteral("dsp_CrystalSizeZ"));
        sizePolicy1.setHeightForWidth(dsp_CrystalSizeZ->sizePolicy().hasHeightForWidth());
        dsp_CrystalSizeZ->setSizePolicy(sizePolicy1);
        dsp_CrystalSizeZ->setMaximum(999999);

        horizontalLayout_3->addWidget(dsp_CrystalSizeZ);


        verticalLayout->addWidget(gb_CrystalSize);

        gb_ModelOffset = new QGroupBox(gb_CrvEdit);
        gb_ModelOffset->setObjectName(QStringLiteral("gb_ModelOffset"));
        horizontalLayout_4 = new QHBoxLayout(gb_ModelOffset);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lb_OffsetX = new QLabel(gb_ModelOffset);
        lb_OffsetX->setObjectName(QStringLiteral("lb_OffsetX"));
        sizePolicy3.setHeightForWidth(lb_OffsetX->sizePolicy().hasHeightForWidth());
        lb_OffsetX->setSizePolicy(sizePolicy3);
        lb_OffsetX->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(lb_OffsetX);

        dsb_ModelOffsetX = new QDoubleSpinBox(gb_ModelOffset);
        dsb_ModelOffsetX->setObjectName(QStringLiteral("dsb_ModelOffsetX"));
        sizePolicy1.setHeightForWidth(dsb_ModelOffsetX->sizePolicy().hasHeightForWidth());
        dsb_ModelOffsetX->setSizePolicy(sizePolicy1);
        dsb_ModelOffsetX->setMinimum(-999999);
        dsb_ModelOffsetX->setMaximum(999999);

        horizontalLayout_4->addWidget(dsb_ModelOffsetX);

        lb_OffsetY = new QLabel(gb_ModelOffset);
        lb_OffsetY->setObjectName(QStringLiteral("lb_OffsetY"));
        sizePolicy3.setHeightForWidth(lb_OffsetY->sizePolicy().hasHeightForWidth());
        lb_OffsetY->setSizePolicy(sizePolicy3);
        lb_OffsetY->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(lb_OffsetY);

        dsb_ModelOffsetY = new QDoubleSpinBox(gb_ModelOffset);
        dsb_ModelOffsetY->setObjectName(QStringLiteral("dsb_ModelOffsetY"));
        sizePolicy1.setHeightForWidth(dsb_ModelOffsetY->sizePolicy().hasHeightForWidth());
        dsb_ModelOffsetY->setSizePolicy(sizePolicy1);
        dsb_ModelOffsetY->setMinimum(-999999);
        dsb_ModelOffsetY->setMaximum(999999);

        horizontalLayout_4->addWidget(dsb_ModelOffsetY);

        lb_OffsetZ = new QLabel(gb_ModelOffset);
        lb_OffsetZ->setObjectName(QStringLiteral("lb_OffsetZ"));
        sizePolicy3.setHeightForWidth(lb_OffsetZ->sizePolicy().hasHeightForWidth());
        lb_OffsetZ->setSizePolicy(sizePolicy3);
        lb_OffsetZ->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(lb_OffsetZ);

        dsb_ModelOffsetZ = new QDoubleSpinBox(gb_ModelOffset);
        dsb_ModelOffsetZ->setObjectName(QStringLiteral("dsb_ModelOffsetZ"));
        sizePolicy1.setHeightForWidth(dsb_ModelOffsetZ->sizePolicy().hasHeightForWidth());
        dsb_ModelOffsetZ->setSizePolicy(sizePolicy1);
        dsb_ModelOffsetZ->setMinimum(-999999);
        dsb_ModelOffsetZ->setMaximum(999999);

        horizontalLayout_4->addWidget(dsb_ModelOffsetZ);


        verticalLayout->addWidget(gb_ModelOffset);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lb_BoardThickness = new QLabel(gb_CrvEdit);
        lb_BoardThickness->setObjectName(QStringLiteral("lb_BoardThickness"));

        horizontalLayout_5->addWidget(lb_BoardThickness);

        dsb_BoardThickness = new QDoubleSpinBox(gb_CrvEdit);
        dsb_BoardThickness->setObjectName(QStringLiteral("dsb_BoardThickness"));
        sizePolicy1.setHeightForWidth(dsb_BoardThickness->sizePolicy().hasHeightForWidth());
        dsb_BoardThickness->setSizePolicy(sizePolicy1);
        dsb_BoardThickness->setMaximumSize(QSize(16777215, 16777215));
        dsb_BoardThickness->setDecimals(1);
        dsb_BoardThickness->setMinimum(0);
        dsb_BoardThickness->setMaximum(999999);

        horizontalLayout_5->addWidget(dsb_BoardThickness);

        sp_Point4_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(sp_Point4_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pb_Preview = new QPushButton(gb_CrvEdit);
        pb_Preview->setObjectName(QStringLiteral("pb_Preview"));
        sizePolicy3.setHeightForWidth(pb_Preview->sizePolicy().hasHeightForWidth());
        pb_Preview->setSizePolicy(sizePolicy3);
        pb_Preview->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(pb_Preview);

        sp_Point4_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(sp_Point4_2);

        pb_Apply = new QPushButton(gb_CrvEdit);
        pb_Apply->setObjectName(QStringLiteral("pb_Apply"));
        pb_Apply->setEnabled(true);
        sizePolicy3.setHeightForWidth(pb_Apply->sizePolicy().hasHeightForWidth());
        pb_Apply->setSizePolicy(sizePolicy3);
        pb_Apply->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(pb_Apply);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addWidget(gb_CrvEdit);

        dockWidget->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLaser->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSorting->menuAction());
        menuBar->addAction(menuBlock->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_FileOpen);
        menuFile->addAction(action_ClearAll);
        menuFile->addAction(action_FileSave);
        menuFile->addSeparator();
        menuFile->addAction(menu_RecentFileList->menuAction());
        menuFile->addAction(menu_RecentPathList->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(action_QuitApp);
        menuLaser->addAction(action_ParameterSettings);
        menuLaser->addAction(action_ImportReg);
        menuLaser->addAction(action_ExportReg);
        menuLaser->addSeparator();
        menuLaser->addAction(action_BatchSettings);
        menuLaser->addAction(action_TagGenerate);
        menuLaser->addSeparator();
        menuLaser->addAction(action_Calibration);
        menuLaser->addSeparator();
        menuLaser->addAction(action_TestPosition);
        menuLaser->addAction(action_PlatHorAdjust);
        menuView->addAction(action_FrontView);
        menuView->addAction(action_TopView);
        menuView->addAction(action_RightView);
        menuView->addAction(action_UpdateView);
        menuView->addSeparator();
        menuView->addAction(action_RawModel);
        menuView->addAction(action_AmendModel);
        menuView->addAction(action_CutupModel);
        menuView->addSeparator();
        menuView->addAction(menu_Language->menuAction());
        menu_Language->addAction(action_Chinese);
        menu_Language->addAction(action_English);
        menuSorting->addAction(action_OriginSorting);
        menuSorting->addAction(action_SortY2X);
        menuSorting->addAction(action_SortX2Y);
        menuSorting->addAction(action_SortByShortestPath);
        menuBlock->addAction(action_BlockX2Y);
        menuBlock->addAction(action_BlockY2X);
        menuBlock->addAction(action_BlockByShortestPath);
        menuBlock->addSeparator();
        menuBlock->addAction(action_NewBlock);
        menuBlock->addAction(action_DeleteBlock);
        menuBlock->addAction(action_DeleteAllBlock);
        menuBlock->addSeparator();
        menuBlock->addAction(action_IncreaseArea);
        menuBlock->addAction(action_ReduceArea);
        menuBlock->addAction(action_ClearArea);
        menuBlock->addSeparator();
        menuBlock->addAction(action_NoBorder);
        menuBlock->addAction(action_LinearBorder);
        menuBlock->addAction(action_RandomBorder);
        menuBlock->addSeparator();
        menuBlock->addAction(action_LastBlock);
        menuBlock->addAction(action_NextBlock);
        menuDebug->addAction(menu_StdMod->menuAction());
        menuDebug->addAction(action_HeatTest);
        menu_StdMod->addAction(action_StdModLine);
        menu_StdMod->addAction(action_StdModPlane);
        menu_StdMod->addAction(action_StdModCube);
        menu_StdMod->addAction(action_StdModBall);
        menu_StdMod->addAction(action_StdModRightAngle);
        menuHelp->addAction(action_AboutThis);
        toolBar->addAction(action_ClearAll);
        toolBar->addAction(action_FileOpen);
        toolBar->addSeparator();
        toolBar->addAction(action_FrontView);
        toolBar->addAction(action_TopView);
        toolBar->addAction(action_RightView);
        toolBar->addSeparator();
        toolBar->addAction(action_RawModel);
        toolBar->addAction(action_UpdateView);
        toolBar->addSeparator();
        toolBar->addAction(action_BlockX2Y);
        toolBar->addAction(action_BlockY2X);
        toolBar->addSeparator();
        toolBar->addAction(action_BlockParaGroup);
        toolBar->addSeparator();
        toolBar->addAction(action_StdModLine);
        toolBar->addAction(action_StdModPlane);
        toolBar->addSeparator();
        toolBar->addAction(action_AboutThis);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_FileOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", 0));
#ifndef QT_NO_TOOLTIP
        action_FileOpen->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        action_FileOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        action_FileSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
#ifndef QT_NO_TOOLTIP
        action_FileSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        action_FileSave->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        action_QuitApp->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&Q)", 0));
#ifndef QT_NO_TOOLTIP
        action_QuitApp->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_TOOLTIP
        action_QuitApp->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        action_ParameterSettings->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260(&P)", 0));
#ifndef QT_NO_TOOLTIP
        action_ParameterSettings->setToolTip(QApplication::translate("MainWindow", "\346\234\272\345\231\250\345\217\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        action_ParameterSettings->setShortcut(QApplication::translate("MainWindow", "Alt+P", 0));
        action_ImportReg->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\263\250\345\206\214\350\241\250(&I)", 0));
#ifndef QT_NO_TOOLTIP
        action_ImportReg->setToolTip(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\263\250\345\206\214\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        action_ImportReg->setShortcut(QApplication::translate("MainWindow", "Alt+I", 0));
        action_ExportReg->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\263\250\345\206\214\350\241\250(&E)", 0));
#ifndef QT_NO_TOOLTIP
        action_ExportReg->setToolTip(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\263\250\345\206\214\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        action_ExportReg->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        action_BatchSettings->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217\351\233\225\345\210\273\350\256\276\347\275\256(&S)", 0));
#ifndef QT_NO_TOOLTIP
        action_BatchSettings->setToolTip(QApplication::translate("MainWindow", "\346\211\271\351\207\217\351\233\225\345\210\273\350\256\276\347\275\256", 0));
#endif // QT_NO_TOOLTIP
        action_BatchSettings->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        action_TagGenerate->setText(QApplication::translate("MainWindow", "\346\240\207\350\256\260\347\240\201\347\224\237\346\210\220(&G)", 0));
#ifndef QT_NO_TOOLTIP
        action_TagGenerate->setToolTip(QApplication::translate("MainWindow", "\346\240\207\350\256\260\347\240\201\347\224\237\346\210\220", 0));
#endif // QT_NO_TOOLTIP
        action_TagGenerate->setShortcut(QApplication::translate("MainWindow", "Alt+G", 0));
        action_Calibration->setText(QApplication::translate("MainWindow", "\346\240\207\345\256\232(&C)", 0));
#ifndef QT_NO_TOOLTIP
        action_Calibration->setToolTip(QApplication::translate("MainWindow", "\346\240\207\345\256\232", 0));
#endif // QT_NO_TOOLTIP
        action_Calibration->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        action_TestPosition->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\346\265\213\350\257\225(&T)", 0));
#ifndef QT_NO_TOOLTIP
        action_TestPosition->setToolTip(QApplication::translate("MainWindow", "\344\275\215\347\275\256\346\265\213\350\257\225", 0));
#endif // QT_NO_TOOLTIP
        action_TestPosition->setShortcut(QApplication::translate("MainWindow", "Alt+T", 0));
        action_PlatHorAdjust->setText(QApplication::translate("MainWindow", "\345\217\260\351\235\242\346\260\264\345\271\263\350\260\203\350\257\225(&H)", 0));
#ifndef QT_NO_TOOLTIP
        action_PlatHorAdjust->setToolTip(QApplication::translate("MainWindow", "\345\217\260\351\235\242\346\260\264\345\271\263\350\260\203\350\257\225", 0));
#endif // QT_NO_TOOLTIP
        action_PlatHorAdjust->setShortcut(QApplication::translate("MainWindow", "Alt+H", 0));
        action_ToolBar->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", 0));
        action_ToolBar->setShortcut(QApplication::translate("MainWindow", "Alt+T", 0));
        action_ViewState->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", 0));
        action_ViewState->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        action_ViewCtrl->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\346\240\217", 0));
        action_ViewCtrl->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        action_FrontView->setText(QApplication::translate("MainWindow", "\345\211\215\350\247\206\345\233\276(&F)", 0));
#ifndef QT_NO_TOOLTIP
        action_FrontView->setToolTip(QApplication::translate("MainWindow", "\345\211\215\350\247\206\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        action_FrontView->setShortcut(QApplication::translate("MainWindow", "Alt+F", 0));
        action_TopView->setText(QApplication::translate("MainWindow", "\351\241\266\350\247\206\345\233\276(&T)", 0));
#ifndef QT_NO_TOOLTIP
        action_TopView->setToolTip(QApplication::translate("MainWindow", "\351\241\266\350\247\206\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        action_TopView->setShortcut(QApplication::translate("MainWindow", "Alt+T", 0));
        action_RightView->setText(QApplication::translate("MainWindow", "\345\217\263\350\247\206\345\233\276(&R)", 0));
#ifndef QT_NO_TOOLTIP
        action_RightView->setToolTip(QApplication::translate("MainWindow", "\345\217\263\350\247\206\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        action_RightView->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0));
        action_UpdateView->setText(QApplication::translate("MainWindow", "\350\247\206\345\233\276\346\233\264\346\226\260", 0));
        action_RawModel->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\250\241\345\236\213(&O)", 0));
#ifndef QT_NO_TOOLTIP
        action_RawModel->setToolTip(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\250\241\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        action_RawModel->setShortcut(QApplication::translate("MainWindow", "Alt+M", 0));
        action_AmendModel->setText(QApplication::translate("MainWindow", "\344\277\256\346\255\243\346\250\241\345\236\213(&M)", 0));
#ifndef QT_NO_TOOLTIP
        action_AmendModel->setToolTip(QApplication::translate("MainWindow", "\344\277\256\346\255\243\346\250\241\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        action_AmendModel->setShortcut(QApplication::translate("MainWindow", "Alt+M", 0));
        action_CutupModel->setText(QApplication::translate("MainWindow", "\345\210\206\345\211\262\346\250\241\345\236\213(&A)", 0));
#ifndef QT_NO_TOOLTIP
        action_CutupModel->setToolTip(QApplication::translate("MainWindow", "\345\210\206\345\211\262\346\250\241\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        action_CutupModel->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        action_OriginSorting->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\216\222\345\272\217(&O)", 0));
        action_OriginSorting->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        action_SortY2X->setText(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(&Y->X)", 0));
#ifndef QT_NO_TOOLTIP
        action_SortY2X->setToolTip(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(Y->X)", 0));
#endif // QT_NO_TOOLTIP
        action_SortX2Y->setText(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(&X->Y)", 0));
#ifndef QT_NO_TOOLTIP
        action_SortX2Y->setToolTip(QApplication::translate("MainWindow", "\351\241\272\345\272\217\346\211\253\346\217\217(X->Y)", 0));
#endif // QT_NO_TOOLTIP
        action_SortByShortestPath->setText(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\345\276\204(&S)", 0));
#ifndef QT_NO_TOOLTIP
        action_SortByShortestPath->setToolTip(QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\257\345\276\204", 0));
#endif // QT_NO_TOOLTIP
        action_BlockX2Y->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\345\235\227(&X->Y)", 0));
        action_BlockY2X->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\345\235\227(&Y->X)", 0));
        action_BlockByShortestPath->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\345\235\227(&Z.\346\234\200\347\237\255\350\267\257\345\276\204)", 0));
        action_BlockParaGroup->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\347\273\204\345\210\206\345\235\227\342\200\246", 0));
        action_CurPosAsHomePos->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\344\275\215\347\275\256\347\202\271\344\270\272\351\233\225\345\210\273\345\216\237\347\202\271", 0));
        action_AlwaysSetCurPosAsHomePos->setText(QApplication::translate("MainWindow", "\345\247\213\347\273\210\344\273\245\345\275\223\345\211\215\344\275\215\347\275\256\344\270\272\351\233\225\345\210\273\345\216\237\347\202\271", 0));
        action_ResetMechPos->setText(QApplication::translate("MainWindow", "\346\234\272\346\242\260\345\216\237\347\202\271\345\244\215\344\275\215", 0));
        action_SelectHomePos1->setText(QApplication::translate("MainWindow", "(0.0,0.0,0.0)", 0));
#ifndef QT_NO_TOOLTIP
        action_SelectHomePos1->setToolTip(QApplication::translate("MainWindow", "\346\277\200\345\205\211\345\216\237\347\202\271", 0));
#endif // QT_NO_TOOLTIP
        action_AttachModel->setText(QApplication::translate("MainWindow", "\351\231\204\345\212\240\346\250\241\345\236\213(&A)", 0));
#ifndef QT_NO_TOOLTIP
        action_AttachModel->setToolTip(QApplication::translate("MainWindow", "\351\231\204\345\212\240\346\250\241\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        action_AttachModel->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        action_SplitModel->setText(QApplication::translate("MainWindow", "\345\210\206\347\246\273\346\250\241\345\236\213(&S)", 0));
#ifndef QT_NO_TOOLTIP
        action_SplitModel->setToolTip(QApplication::translate("MainWindow", "\345\210\206\347\246\273\346\250\241\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        action_SplitModel->setShortcut(QApplication::translate("MainWindow", "Alt+U", 0));
        action_HeatTest->setText(QApplication::translate("MainWindow", "\347\203\244\346\234\272", 0));
        action_DisableFunction->setText(QApplication::translate("MainWindow", "\345\201\234\347\224\250\345\212\237\350\203\275", 0));
        action_StdModLine->setText(QApplication::translate("MainWindow", "\347\233\264\347\272\277(&L)", 0));
        action_StdModPlane->setText(QApplication::translate("MainWindow", "\345\271\263\351\235\242(&P)", 0));
        action_StdModCube->setText(QApplication::translate("MainWindow", "\347\253\213\346\226\271\344\275\223(&C)", 0));
        action_StdModBall->setText(QApplication::translate("MainWindow", "\345\234\206\347\220\203(&B)", 0));
        action_AboutThis->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", 0));
        action_AboutThis->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        action_LanCHN->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207", 0));
        action_ClearFileList->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\217\234\345\215\225", 0));
        action_ClearPathList->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\217\234\345\215\225", 0));
        action_Chinese->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207(&C)", 0));
        action_English->setText(QApplication::translate("MainWindow", "English(&E)", 0));
        action_NewBlock->setText(QApplication::translate("MainWindow", "\346\226\260\345\242\236(&N)", 0));
        action_DeleteBlock->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244(&D)", 0));
        action_DeleteAllBlock->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250\345\210\240\351\231\244(&A)", 0));
        action_IncreaseArea->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\345\214\272\345\237\237(&I)", 0));
        action_ReduceArea->setText(QApplication::translate("MainWindow", "\345\207\217\345\260\221\345\214\272\345\237\237(&R)", 0));
        action_ClearArea->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\214\272\345\237\237(&C)", 0));
        action_NoBorder->setText(QApplication::translate("MainWindow", "\346\227\240\350\276\271\347\225\214(&O)", 0));
        action_LinearBorder->setText(QApplication::translate("MainWindow", "\347\272\277\346\200\247\350\276\271\347\225\214(&L)", 0));
        action_RandomBorder->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\350\276\271\347\225\214(&M)", 0));
        action_LastBlock->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\345\235\227(&U)", 0));
        action_NextBlock->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\235\227(&D)", 0));
        action_StdModRightAngle->setText(QApplication::translate("MainWindow", "\347\233\264\350\247\222(&R)", 0));
        action_ClearAll->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\211\200\346\234\211(&C)", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_RecentFileList->setTitle(QApplication::translate("MainWindow", "\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\346\226\207\344\273\266", 0));
        menu_RecentPathList->setTitle(QApplication::translate("MainWindow", "\346\234\200\350\277\221\346\211\223\345\274\200\347\233\256\345\275\225", 0));
        menuLaser->setTitle(QApplication::translate("MainWindow", "\346\234\272\345\231\250(&M)", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276(&V)", 0));
        menu_Language->setTitle(QApplication::translate("MainWindow", "\350\257\255\350\250\200(&L)", 0));
        menuSorting->setTitle(QApplication::translate("MainWindow", "\346\216\222\345\272\217(&S)", 0));
        menuBlock->setTitle(QApplication::translate("MainWindow", "\345\210\206\345\235\227(&B)", 0));
        menuDebug->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225(&D)", 0));
        menu_StdMod->setTitle(QApplication::translate("MainWindow", "\346\240\207\345\207\206\346\250\241\345\236\213(&S)", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
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
        lb_CrystalSize->setText(QApplication::translate("MainWindow", "\346\260\264\346\231\266", 0));
        lb_PointNumVal->setText(QApplication::translate("MainWindow", "000000000", 0));
        lb_PointMaxValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMinValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLenValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_CrystalSizeValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMaxValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLenValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_CrystalSizeValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointMaxValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PointLenValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_CrystalSizeValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        gb_CrvCtrl->setTitle(QApplication::translate("MainWindow", "\351\233\225\345\210\273\346\216\247\345\210\266", 0));
        lb_CrvTime->setText(QApplication::translate("MainWindow", "\350\256\241\346\227\266:", 0));
        lb_CrvTimeVal->setText(QApplication::translate("MainWindow", "0.0M0.0S", 0));
#ifndef QT_NO_WHATSTHIS
        pb_Crv->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pb_Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        pb_Pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        pb_Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        pb_LaserOnOff->setText(QApplication::translate("MainWindow", "\345\274\200\346\277\200\345\205\211", 0));
        gb_PlatCtrl->setTitle(QApplication::translate("MainWindow", "\345\271\263\345\217\260\346\216\247\345\210\266", 0));
        pb_MoveToHome->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\344\275\215(B)", 0));
        pb_ResetPos->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215(R)", 0));
        pb_ResetMechPos->setText(QApplication::translate("MainWindow", "\346\234\272\346\242\260\345\244\215\344\275\215", 0));
        pb_MoveXP->setText(QApplication::translate("MainWindow", "\345\217\263(X+)", 0));
        pb_MoveYP->setText(QApplication::translate("MainWindow", "\345\220\216(Y+)", 0));
        pb_MoveZP->setText(QApplication::translate("MainWindow", "\344\270\212(Z+)", 0));
        pb_MoveXN->setText(QApplication::translate("MainWindow", "\345\267\246(X-)", 0));
        pb_MoveYN->setText(QApplication::translate("MainWindow", "\345\211\215(Y-)", 0));
        pb_MoveZN->setText(QApplication::translate("MainWindow", "\344\270\213(Z-)", 0));
        gb_OperateMode->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\250\241\345\274\217", 0));
        rb_ContinousMove->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255", 0));
        rb_IncrementalMove->setText(QApplication::translate("MainWindow", "\345\242\236\351\207\217", 0));
        lb_IncreDis->setText(QApplication::translate("MainWindow", "mm", 0));
        lb_PlatAxis->setText(QApplication::translate("MainWindow", "\350\275\264", 0));
        lb_PlatCurPos->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256", 0));
        lb_PlatSize->setText(QApplication::translate("MainWindow", "\345\271\205\351\235\242", 0));
        lb_PlatX->setText(QApplication::translate("MainWindow", "X:", 0));
        lb_PlatCurPosValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatSizeValX->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatY->setText(QApplication::translate("MainWindow", "Y:", 0));
        lb_PlatCurPosValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatSizeValY->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatZ->setText(QApplication::translate("MainWindow", "Z:", 0));
        lb_PlatCurPosValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        lb_PlatSizeValZ->setText(QApplication::translate("MainWindow", "0.0", 0));
        gb_CrvEdit->setTitle(QApplication::translate("MainWindow", "\351\233\225\345\210\273\347\274\226\350\276\221", 0));
        gb_CrystalSize->setTitle(QApplication::translate("MainWindow", "\346\260\264\346\231\266\345\244\247\345\260\217(mm)", 0));
        lb_CrystalSizeX->setText(QApplication::translate("MainWindow", "X:", 0));
        lb_CrystalSizeY->setText(QApplication::translate("MainWindow", "Y:", 0));
        lb_CrystalSizeZ->setText(QApplication::translate("MainWindow", "Z:", 0));
        gb_ModelOffset->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\236\213\345\201\217\347\247\273(mm)", 0));
        lb_OffsetX->setText(QApplication::translate("MainWindow", "X:", 0));
        lb_OffsetY->setText(QApplication::translate("MainWindow", "Y:", 0));
        lb_OffsetZ->setText(QApplication::translate("MainWindow", "Z:", 0));
        lb_BoardThickness->setText(QApplication::translate("MainWindow", "\345\236\253\346\235\277\345\216\232\345\272\246(mm):", 0));
        pb_Preview->setText(QApplication::translate("MainWindow", "\351\242\204\350\247\210", 0));
        pb_Apply->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
