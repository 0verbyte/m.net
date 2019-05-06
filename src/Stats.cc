#include <QByteArray>
#include <QDateTime>
#include <QDebug>
#include <QFile>

#include "Stats.h"

Stats::Stats() {
  // Create the mnet directory if it doesn't exist
  QDir mnetPath;
  if (!mnetPath.exists(mnetDir)) {
    mnetPath.mkdir(mnetDir);
    return;
  }

  // If a stats file is present already, read that into memory
  readStatsFile();
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

bool Stats::readStatsFile() {
  QFile jsonFile(statsFilePath);
  if (!jsonFile.open(QIODevice::ReadOnly)) {
    return false;
  }

  // Load the stats file into JSON object
  QByteArray statsData = jsonFile.readAll();
  statsJson = fromJson(statsData).object();
  return true;
}