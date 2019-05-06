#ifndef STATS_H
#define STATS_H

#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class Stats : public QJsonDocument {
 public:
  Stats();
  void ping(bool connected);

 private:
  QJsonArray statsPing;
  QJsonArray statsUptime;

  QJsonObject statsJson;
  QString statsFilePath = QDir::homePath() + "/.mnet/stats.json";
  QString mnetDir = QDir::homePath() + "/.mnet";

  bool writeStatsFile();
  bool readStatsFile();
};

#endif  // STATS_H