#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QObject {
    Q_OBJECT
  public slots:
    void doWork() {
      int i = 0;
      while (true) {
        result(i++);
        QThread::msleep(100);
      }
    }
  signals:
    void result(int r);
};

#endif // WORKER_H
