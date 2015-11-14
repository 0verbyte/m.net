#include <QUrl>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "Network.h"

Network::Network() : connState(true) {
  connect(&checkTimer, &QTimer::timeout, this, &Network::check);
}

void Network::setInterval(unsigned int secs) {
  qDebug() << "Interval set to" << secs << "seconds";
  checkTimer.setInterval(secs * 1000);
  checkTimer.start();
}

void Network::check() {
  QUrl url("http://google.com");
  QNetworkRequest req(url);
  auto *rep = mgr.get(req);
  connect(rep, &QNetworkReply::finished, this, &Network::onReplyFinished);
}

void Network::onReplyFinished() {
  auto *rep = qobject_cast<QNetworkReply*>(sender());
  if (!rep) return;

  if (rep->error() == QNetworkReply::NoError) {
    if (!connState) {
      emit connected();
    }
    connState = true;
    return;
  }

  if (connState) {
    emit unconnected(rep->errorString());
  }
  connState = false;
}
