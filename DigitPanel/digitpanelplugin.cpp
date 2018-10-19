#include "digitPanel.h"
#include "digitpanelplugin.h"

#include <QtPlugin>

DigitPanelPlugin::DigitPanelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void DigitPanelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool DigitPanelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *DigitPanelPlugin::createWidget(QWidget *parent)
{
    return new DigitPanel(parent);
}

QString DigitPanelPlugin::name() const
{
    return QLatin1String("DigitPanel");
}

QString DigitPanelPlugin::group() const
{
    return QLatin1String("");
}

QIcon DigitPanelPlugin::icon() const
{
    return QIcon();
}

QString DigitPanelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString DigitPanelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool DigitPanelPlugin::isContainer() const
{
    return false;
}

QString DigitPanelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"DigitPanel\" name=\"digitPanel\">\n</widget>\n");
}

QString DigitPanelPlugin::includeFile() const
{
    return QLatin1String("digitPanel.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(digitpanelplugin, DigitPanelPlugin)
#endif // QT_VERSION < 0x050000
