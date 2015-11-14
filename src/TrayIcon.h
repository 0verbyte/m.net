#ifndef TRAY_ICON_H
#define TRAY_ICON_H

#include <QMenu>
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
};

#endif // TRAY_ICON_H
