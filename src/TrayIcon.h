#ifndef TRAY_ICON_H
#define TRAY_ICON_H

#include <QMenu>
#include <QSettings>
#include <QSystemTrayIcon>

#include "Network.h"

class TrayIcon : public QSystemTrayIcon {
  Q_OBJECT

public:
  TrayIcon();

  void showMsg(const QString &title, const QString &msg,
               QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information,
               int timeoutMs = 10000);

private:
  void setupMenu();

  QMenu ctxMenu;
  Network net;
  QSettings settings;
};

#endif // TRAY_ICON_H
