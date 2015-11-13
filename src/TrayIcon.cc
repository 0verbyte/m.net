#include <QDebug>
#include <QImage>
#include <QPixmap>

#include <utility> // std::move

#include "TrayIcon.h"

TrayIcon::TrayIcon() {
  // TODO: Use better icon..
  QImage img(32, 32, QImage::Format_RGB888);
  img.fill(Qt::green);
  setIcon(QPixmap::fromImage(std::move(img)));

  auto *act = ctxMenu.addAction("Click me!");
  connect(act, &QAction::triggered, [this]{
      showMessage("Test", "Hello, World!");
    });
  setContextMenu(&ctxMenu);
}
