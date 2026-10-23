// read_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QList>
#include <QString>

#include <cstdlib>

#include "file_header.h"

int main()
{
  QFile file("temp.dat");
  if (!file.open(QIODevice::ReadOnly)){
    qDebug() << "Error: could not open file for reading.";
    return EXIT_FAILURE;
  }
  QDataStream in(&file);

  // Read and check the header
  quint32 magic = 0;
  in >> magic;
  if (magic != MAGIC){
    qDebug() << "Error: unexpected format.";
    return EXIT_FAILURE;
  }

  // Read the version
  qint32 version = 0;
  in >> version;
  if(version != VERSION){
    qDebug() << "Error: unsupported file version.";
    return EXIT_FAILURE;
  }

  // use the same encoding format
  in.setVersion(QDataStream::Qt_5_0);

  // Read the data
  QList<QString> messages;
  in >> messages;

  if (in.status() != QDataStream::Ok){
    qDebug() << "Error: could not read data.";
    return EXIT_FAILURE;
  }

  qDebug() << "Read data from a file: " << messages;
  
  return EXIT_SUCCESS;
}
