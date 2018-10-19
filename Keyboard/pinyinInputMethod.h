#ifndef PINYININPUTMETHOD_H
#define PINYININPUTMETHOD_H

#include <QObject>
#include <QStringList>
#include <QVector>
#include "csingleton.h"

class CPinyinInputMethod
{
public:
    CPinyinInputMethod();
    ~CPinyinInputMethod();


public:
    QString SearchCN(const QString &gemfield);
    void clear();

    QVector<QStringList> HanziModel;

private:
    QStringList lstEN;
    QString m_gemfield;
};

typedef CSingleton<CPinyinInputMethod> g_CPinyinInputMethod;

#endif
