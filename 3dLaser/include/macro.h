#ifndef MACRO_H
#define MACRO_H

#ifndef CUR_OK
#define CUR_OK (0)
#endif
#ifndef CUR_ERROR
#define CUR_ERROR (-1)
#endif
#ifndef CTRL_ERROR
#define CTRL_ERROR (-1)
#endif
#ifndef CTRL_OK
#define CTRL_OK (0)
#endif
#ifndef CTRL_NO_CARD_ERROR //没有安装ADT8937卡
#define CTRL_NO_CARD_ERROR (0)
#endif
#ifndef CTRL_NO_DRIVE_ERROR //没有安装端口驱动程序
#define CTRL_NO_DRIVE_ERROR (-1)
#endif
#ifndef CTRL_PCI_ERROR
#define CTRL_PCI_ERROR (-2)
#endif


#endif // MACRO_H
