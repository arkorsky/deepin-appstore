
#ifndef SHELL_SHELL_H
#define SHELL_SHELL_H

#include <QApplication>
#include <QCommandLineParser>
#include <QSettings>
#include <QPoint>
#include <libdui/darrowrectangle.h>
#include "DBusInterface.h"
#include "MainWindow.h"

class Shell : public QApplication {
    Q_OBJECT
public:
    Shell(int& argc, char** argv);
    ~Shell();

    void showTooltip(QString text, QPoint globalPos);
    void setTooltipVisible(bool visible);

    QCommandLineParser* argsParser = nullptr;
    QString basePath;
    QSettings* settings = nullptr;
    QUrl initUrl;
    QString origin;
    bool isInitialRun = true;

signals:
    void applicationCacheFinished();

private:
    DUI::DArrowRectangle* tooltip = nullptr;
    DBusInterface* dbusInterface = nullptr;
    void parseOptions();
    void onApplicationCacheFinished();
    void startWebView();
    MainWindow* win = nullptr;
};


#endif //SHELL_SHELL_H
