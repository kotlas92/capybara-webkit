#include <QObject>

class QLocalServer;
class WebPage;

class Server : public QObject {
  Q_OBJECT

  public:
    Server(QObject *parent);
    bool start();
    QString server_name();

  public slots:
    void handleConnection();

  private:
    QLocalServer *m_server;
    WebPage *m_page;
};

