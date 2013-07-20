#include <QObject>

class QLocalServer;

class Server : public QObject {
  Q_OBJECT

  public:
    Server(QObject *parent);
    bool start();
    QString server_port();

  public slots:
    void handleConnection();

  private:
    QLocalServer *m_server;
};

