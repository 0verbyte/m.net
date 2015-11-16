#include <QDebug>
#include <QTimer>
#include <QApplication>

#include <signal.h>

#include "TrayIcon.h"

void signalHandler(int signal) {
  qDebug().nospace() << "Closing.. got signal=" << signal;
  QApplication::quit();
}

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  if (!QSystemTrayIcon::isSystemTrayAvailable()) {
    // TODO: Show another dialog instead of the tray icon.
    qCritical() << "System tray not supported!";
    return -1;
  }

  signal(SIGABRT, &signalHandler);
  signal(SIGTERM, &signalHandler);
  signal(SIGINT, &signalHandler);
#ifndef WIN32
  signal(SIGKILL, &signalHandler);
#endif

  TrayIcon trayIcon;
  QTimer::singleShot(1, &trayIcon, SLOT(show()));

  return app.exec();
}
