#include "tailfileinfo.h"
#include <QtDebug>

TailFileInfo::TailFileInfo() :
    QFileInfo()

{
    curPosition = 0;
}

TailFileInfo::TailFileInfo(const QString& file) :
    QFileInfo(file)

{
    curPosition = 0;
}


TailFileInfo::~TailFileInfo()
{

}

qint64 TailFileInfo::position()
{
    return (curPosition)?curPosition-1:0;
}

void TailFileInfo::set_position(qint64 pos)
{
    curPosition = pos;
}


