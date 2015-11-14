#import <Foundation/Foundation.h>

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
     message:(NSString*)msg;
{
  NSUserNotification *notif = [[[NSUserNotification alloc] init] autorelease];
  notif.title = title;
  notif.informativeText = msg;

  NSUserNotificationCenter *center = [NSUserNotificationCenter defaultUserNotificationCenter];
  center.delegate = self;
  [center deliverNotification:notif];
}

@end

void showMacMessage(const QString &title, const QString &msg,
                    QSystemTrayIcon::MessageIcon icon, int timeoutMs) {
  // NOTE: icon and timeoutMs are ignored right now.
  NSString *title_ =
    [NSString stringWithCString:title.toUtf8().constData() encoding:NSUTF8StringEncoding];
  NSString *msg_ =
    [NSString stringWithCString:msg.toUtf8().constData() encoding:NSUTF8StringEncoding];
  MacNotification *mn = [[[MacNotification alloc] init] autorelease];
  [mn showNotificationWithTitle:title_ message:msg_];
}
