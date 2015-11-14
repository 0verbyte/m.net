#import <Foundation/NSUserNotification.h>

#include "MacNotification.h"

void showMacMessage(const QString &title, const QString &msg, QSystemTrayIcon::MessageIcon icon,
                    int timeoutMs) {
  NSLog(@"sending notification");

  NSUserNotification *notif = [[[NSUserNotification alloc] init] autorelease];
  notif.title = @"mnet";
  notif.informativeText = @"osx notification";

  [[NSUserNotificationCenter defaultUserNotificationCenter] deliverNotification:notif];

  NSLog(@"sent notification");
}
