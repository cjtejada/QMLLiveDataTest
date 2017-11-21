#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "worker.h"

class Controller : public QObject {
    Q_OBJECT
  public:
    Controller() {
      w = new Worker;
      t = new QThread;
      w->moveToThread(t);
      connect(this, SIGNAL(start()), w, SLOT(doWork()));
      connect(w, SIGNAL(result(int)), this, SIGNAL(result(int)));
      t->start();
    }
  private:
    Worker* w;
    QThread* t;
  signals:
    void start();
    void result(int r);
};

#endif // CONTROLLER_H
