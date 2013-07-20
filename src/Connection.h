#include <QObject>
#include <QStringList>

class QLocalSocket;
class WebPage;
class Command;
class Response;
class CommandParser;
class CommandFactory;
class PageLoadingCommand;
class WebPageManager;

class Connection : public QObject {
  Q_OBJECT

  public:
    Connection(QLocalSocket *socket, WebPageManager *manager, QObject *parent = 0);

  public slots:
    void commandReady(Command *command);
    void finishCommand(Response *response);
    void pendingLoadFinished(bool success);

  private:
    void startCommand(Command *);
    void writeResponse(Response *response);
    void writePageLoadFailure();

    QLocalSocket *m_socket;
    WebPageManager *m_manager;
    CommandParser *m_commandParser;
    CommandFactory *m_commandFactory;
    bool m_pageSuccess;
    WebPage *currentPage();
};

