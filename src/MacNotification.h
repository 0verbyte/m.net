#ifndef MAC_NOTIFICATION_H
#define MAC_NOTIFICATION_H

#include <QSystemTrayIcon>

void showMacMessage(const QString &title, const QString &msg,
                    QSystemTrayIcon::MessageIcon icon, int timeoutMs);

#endif  // MAC_NOTIFICATION_H
