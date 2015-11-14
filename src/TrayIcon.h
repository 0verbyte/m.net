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

private:
  void setupMenu();

  QMenu ctxMenu;
  Network net;
  QSettings settings;
};

#endif // TRAY_ICON_H
