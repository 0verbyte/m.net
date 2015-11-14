#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QApplication>

#include <utility> // std::move

#include "TrayIcon.h"

TrayIcon::TrayIcon() {
  // TODO: Use better icon..
  QImage img(32, 32, QImage::Format_RGB888);
  img.fill(Qt::green);
  setIcon(QPixmap::fromImage(std::move(img)));

  connect(&net, &Network::connected, [this]{
      showMessage(tr("Connected"), tr("Connected to the Internet."));
    });

  connect(&net, &Network::unconnected, [this](const QString &error) {
      showMessage(tr("Not connected!"), error, QSystemTrayIcon::Critical);
    });

  setupMenu();
}

void TrayIcon::setupMenu() {
  auto *menu = ctxMenu.addMenu(tr("Checking interval"));
  QList<QPair<QString,int>> ints = {{tr("5 seconds"), 5},
                                    {tr("15 seconds"), 15},
                                    {tr("30 seconds"), 30},
                                    {tr("1 minute"), 60},
                                    {tr("5 minutes"), 300}};
  auto *agrp = new QActionGroup(this);
  for (const auto &val : ints) {
    auto *act = menu->addAction(val.first);
    act->setCheckable(true);
    agrp->addAction(act);

    connect(act, &QAction::triggered, [val, this]{
        net.setInterval(val.second);
      });

    if (val.second == 15) {
      act->setChecked(true);
      act->trigger();
    }
  }

  ctxMenu.addSeparator();

  auto *act = ctxMenu.addAction(tr("Quit"));
  connect(act, &QAction::triggered, []{
      QApplication::quit();
    });

  setContextMenu(&ctxMenu);
}
