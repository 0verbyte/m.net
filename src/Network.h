#ifndef NETWORK_H
#define NETWORK_H

#include <QTimer>
#include <QObject>
#include <QSettings>
#include <QNetworkAccessManager>

class Network : public QObject {
  Q_OBJECT

public:
  Network();

  /// Set interval and (re)start timer.
  void setInterval(int secs);

signals:
  void connected();
  void unconnected(const QString &error = QString());

public slots:
  /// Checks internet connectivity.
  void check();

private slots:
  void onReplyFinished();

private:
  bool connState;
  QTimer checkTimer;
  QSettings settings;
  QNetworkAccessManager mgr;
};

#endif // NETWORK_H
