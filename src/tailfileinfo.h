#ifndef TAILFILEINFO_H
#define TAILFILEINFO_H

#include <QFile>
#include <QString>
#include <QFileInfo>

class TailFileInfo : public QFileInfo
{
public:
    TailFileInfo();
    TailFileInfo(const QString& file);
    ~TailFileInfo();

    QFile& file();
    qint64 position();
    void set_position(qint64 pos);

private:
    qint64 curPosition;
};

#endif // TAILFILEINFO_H
