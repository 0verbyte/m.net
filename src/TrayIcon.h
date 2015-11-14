#ifndef TRAY_ICON_H
#define TRAY_ICON_H

#include <QMenu>
#include <QSystemTrayIcon>

#include "Network.h"

class TrayIcon : public QSystemTrayIcon {
  Q_OBJECT

public:
  TrayIcon();

private:
  void setupMenu();

  QMenu ctxMenu;
  Network net;
};

#endif // TRAY_ICON_H
