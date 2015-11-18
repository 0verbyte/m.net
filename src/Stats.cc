#include <QFile>
#include <QDebug>
#include <QDateTime>
#include <QByteArray>

#include "Stats.h"

Stats::Stats() {
  QDir mnetPath;
  if (!mnetPath.exists(mnetDir)) {
    mnetPath.mkdir(mnetDir);
    return;
  }

  QFile jsonFile(statsFilePath);
  if (!jsonFile.open(QIODevice::ReadOnly)) {
    return;
  }

  QByteArray statsData = jsonFile.readAll();
  statsJson = fromJson(statsData).object();
}

// Generate a stat for when connection is tested
void Stats::ping(bool connected) {
  // Unix epoch
  int now = QDateTime::currentDateTime().toTime_t();
  QJsonArray pingEntry;
  pingEntry.append(now);
  pingEntry.append(connected);
  QJsonArray statsPing = statsJson["pings"].toArray();
  statsPing.append(pingEntry);
  statsJson["pings"] = statsPing;

  writeStatsFile();
}

bool Stats::writeStatsFile() {
  QFile jsonFile(statsFilePath);
  if (!jsonFile.open(QIODevice::WriteOnly)) {
    return false;
  }

  QJsonDocument obj(statsJson);
  jsonFile.write(obj.toJson(QJsonDocument::Compact));
  return true;
}

