#include "testwdt.h"
#include "testwdtplugin.h"

#include <QtPlugin>

TestWdtPlugin::TestWdtPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TestWdtPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TestWdtPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TestWdtPlugin::createWidget(QWidget *parent)
{
    return new TestWdt(parent);
}

QString TestWdtPlugin::name() const
{
    return QLatin1String("TestWdt");
}

QString TestWdtPlugin::group() const
{
    return QLatin1String("");
}

QIcon TestWdtPlugin::icon() const
{
    return QIcon();
}

QString TestWdtPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TestWdtPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TestWdtPlugin::isContainer() const
{
    return false;
}

QString TestWdtPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TestWdt\" name=\"testWdt\">\n</widget>\n");
}

QString TestWdtPlugin::includeFile() const
{
    return QLatin1String("testwdt.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(testwdtplugin, TestWdtPlugin)
#endif // QT_VERSION < 0x050000
