#include "keyboard.h"
#include "keyboardplugin.h"

#include <QtPlugin>

KeyboardPlugin::KeyboardPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void KeyboardPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool KeyboardPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *KeyboardPlugin::createWidget(QWidget *parent)
{
    return new Keyboard(parent);
}

QString KeyboardPlugin::name() const
{
    return QLatin1String("Keyboard");
}

QString KeyboardPlugin::group() const
{
    return QLatin1String("");
}

QIcon KeyboardPlugin::icon() const
{
    return QIcon();
}

QString KeyboardPlugin::toolTip() const
{
    return QLatin1String("");
}

QString KeyboardPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool KeyboardPlugin::isContainer() const
{
    return false;
}

QString KeyboardPlugin::domXml() const
{
    return QLatin1String("<widget class=\"Keyboard\" name=\"keyboard\">\n</widget>\n");
}

QString KeyboardPlugin::includeFile() const
{
    return QLatin1String("keyboard.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(keyboardplugin, KeyboardPlugin)
#endif // QT_VERSION < 0x050000
