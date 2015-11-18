#import <Foundation/Foundation.h>

#include <QtMac>
#include <QStyle>
#include <QApplication>

#include <sys/sysctl.h>

#include "MacNotification.h"

@interface MacNotification : NSObject <NSUserNotificationCenterDelegate>
@end

@implementation MacNotification

- (BOOL)userNotificationCenter:(NSUserNotificationCenter*)center
     shouldPresentNotification:(NSUserNotification*)userNotification;
{
  return YES;
}

- (void)showNotificationWithTitle:(NSString*)title
                          message:(NSString*)msg
                            image:(NSImage*)image;
{
  NSUserNotification *notif = [[[NSUserNotification alloc] init] autorelease];
  notif.title = title;
  notif.informativeText = msg;
  notif.contentImage = image;

  NSUserNotificationCenter *center = [NSUserNotificationCenter defaultUserNotificationCenter];
  center.delegate = self;
  [center deliverNotification:notif];
}

@end

namespace {
  bool isMavericksOrLater() {
    char str[256];
    auto size = sizeof(str);
    auto ret = sysctlbyname("kern.osrelease", str, &size, nullptr, 0);
    if (ret != 0) {
      return false;
    }

    auto elms = QString(str).split(".");
    if (elms.size() != 3) {
      return false;
    }

    bool ok;
    auto ver = elms[0].toInt(&ok);
    return ok && ver >= 13;
  }
}

void showMacMessage(const QString &title, const QString &msg,
                    QSystemTrayIcon::MessageIcon icon, int timeoutMs) {
  // NOTE: timeoutMs is ignored right now.

  NSString *title_ =
    [NSString stringWithCString:title.toUtf8().constData() encoding:NSUTF8StringEncoding];
  NSString *msg_ =
    [NSString stringWithCString:msg.toUtf8().constData() encoding:NSUTF8StringEncoding];

  // Convert icon to image, if given.
  NSImage *img = nil;

  if (isMavericksOrLater()) {
    int iconVal = -1;
    switch (icon) {
    case QSystemTrayIcon::NoIcon:
      break;

    case QSystemTrayIcon::Information:
      iconVal = QStyle::SP_MessageBoxInformation;
      break;

    case QSystemTrayIcon::Warning:
      iconVal = QStyle::SP_MessageBoxWarning;
      break;

    case QSystemTrayIcon::Critical:
      iconVal = QStyle::SP_MessageBoxCritical;
      break;
    }

    if (iconVal != -1) {
      auto ic = QApplication::style()->standardIcon((QStyle::StandardPixmap) iconVal);
      auto sizes = ic.availableSizes();
      if (!sizes.isEmpty()) {
        auto pix = ic.pixmap(sizes.last());
        img = QtMac::toNSImage(pix);
      }
    }
  }

  MacNotification *mn = [[[MacNotification alloc] init] autorelease];
  [mn showNotificationWithTitle:title_ message:msg_ image:img];
}
