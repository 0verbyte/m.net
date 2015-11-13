#include <QDebug>
#include <QTimer>
#include <QApplication>

#include "TrayIcon.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  if (!QSystemTrayIcon::isSystemTrayAvailable()) {
    // TODO: Show another dialog instead of the tray icon.
    qCritical() << "System tray not supported!";
    return -1;
  }

  TrayIcon trayIcon;
  QTimer::singleShot(1, &trayIcon, SLOT(show()));

  return app.exec();
}
