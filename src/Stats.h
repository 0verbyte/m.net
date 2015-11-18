#ifndef STATS_H
#define STATS_H

#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class Stats : public QJsonDocument {

  public:
    Stats();
    void ping(bool connected);
    bool writeStatsFile();

  private:
    QJsonArray statsPing;
    QJsonArray statsUptime;

    QJsonObject statsJson;
    QString statsFilePath = QDir::homePath() + "/.mnet/stats.json";
    QString mnetDir = QDir::homePath() + "/.mnet";
};

#endif // STATS_H