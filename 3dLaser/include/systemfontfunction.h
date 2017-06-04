#ifndef SYSTEMFONTFUNCTION_H
#define SYSTEMFONTFUNCTION_H

#include <windows.h>
#include <sstream>
#include <QApplication>
//#include <QSettings>
//#include <QDebug>
//#include <QFont>
//#include <QFontInfo>
//#include <QFontComboBox>
//#include <QWidget>
//#include <QVBoxLayout>
//#include <QTextEdit>
//#include <QTime>
//#include <QDir>

//#if _MSC_VER >= 1600
//   #pragma execution_character_set("utf-8")
//#endif

class SystemFontFunction
{
public:
    SystemFontFunction();

    // Get system font file path
    std::string GetSystemFontFile(const std::string &faceName);

    #define MAKE_TAG(ch1, ch2, ch3, ch4) (\
        (((quint32)(ch4)) << 24) | \
        (((quint32)(ch3)) << 16) | \
        (((quint32)(ch2)) << 8) | \
        ((quint32)(ch1)) \
        )

    static inline quint16 getUShort(const unsigned char *p)
    {
        quint16 val;
        val = *p++ << 8;
        val |= *p;

        return val;
    }

    static QString getEnglishName(const uchar *table, quint32 bytes);

    static QString getEnglishName(const QString &familyName);
};

#endif // SYSTEMFONTFUNCTION_H
