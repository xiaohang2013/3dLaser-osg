#include "pcgapplication.h"
#include "pcgexception.h"

bool PCGApplication::notify(QObject *rec, QEvent *ev)
{
    try
    {
        return QApplication::notify(rec,ev);
    }
    catch(PCGException& e)
    {
        qCritical("%s",e.what());
    }
    catch(...)
    {
        qCritical(qPrintable(tr("发生重大错误!")));
        abort();
    }
    return false;
}
