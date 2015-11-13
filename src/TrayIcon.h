#ifndef TRAY_ICON_H
#define TRAY_ICON_H

#include <QSystemTrayIcon>
#include <QMenu>

class TrayIcon : public QSystemTrayIcon {
  Q_OBJECT

public:
  TrayIcon();

private:
  QMenu ctxMenu;
};

#endif // TRAY_ICON_H
