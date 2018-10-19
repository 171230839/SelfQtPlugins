#include "overviewtable.h"
#include "overviewtableplugin.h"

#include <QtPlugin>

OverviewTablePlugin::OverviewTablePlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void OverviewTablePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool OverviewTablePlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *OverviewTablePlugin::createWidget(QWidget *parent)
{
    return new OverviewTable(parent);
}

QString OverviewTablePlugin::name() const
{
    return QLatin1String("OverviewTable");
}

QString OverviewTablePlugin::group() const
{
    return QLatin1String("");
}

QIcon OverviewTablePlugin::icon() const
{
    return QIcon();
}

QString OverviewTablePlugin::toolTip() const
{
    return QLatin1String("");
}

QString OverviewTablePlugin::whatsThis() const
{
    return QLatin1String("");
}

bool OverviewTablePlugin::isContainer() const
{
    return false;
}

QString OverviewTablePlugin::domXml() const
{
    return QLatin1String("<widget class=\"OverviewTable\" name=\"overviewTable\">\n</widget>\n");
}

QString OverviewTablePlugin::includeFile() const
{
    return QLatin1String("overviewtable.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(overviewtableplugin, OverviewTablePlugin)
#endif // QT_VERSION < 0x050000
